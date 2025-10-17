#include "ch.h"
#include "hal.h"
#include <string.h>
#include "flash.h"
#include "aes.h"
#include "usbcfg.h"

#define APPLICATION_ADDRESS 0x08020400
#define SIZE_STORAGE_ADDRESS 0x08020000
#define CRC_STORAGE_ADDRESS 0x08020004
#define SECTOR_SIZE (128U * 1024U)
#define MAX_IMAGE_SIZE (14 * SECTOR_SIZE)
#define BANK_SIZE (8 * SECTOR_SIZE)

typedef void (*pAppEntry_t)(void);

struct AES_ctx ctx;

uint32_t crc32(const uint8_t *data, uint32_t length)
{
    uint32_t crc = 0xFFFFFFFF;
    for (uint32_t i = 0; i < length; i++)
    {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc >>= 1;
        }
    }
    return crc ^ 0xFFFFFFFF;
}

void decrypt_chunk(uint8_t *encrypted_chunk, uint8_t *output, uint32_t length)
{
    memcpy(output, encrypted_chunk, length);
    AES_CTR_xcrypt_buffer(&ctx, output, length);
}

bool check_application_crc(void)
{
    uint32_t storedCRC = *reinterpret_cast<uint32_t *>(CRC_STORAGE_ADDRESS);
    uint32_t crc = crcCalc(&CRCD1, *reinterpret_cast<uint32_t *>(SIZE_STORAGE_ADDRESS), reinterpret_cast<const uint8_t *>(APPLICATION_ADDRESS));
    return (crc == storedCRC);
}

static uint8_t performUpdate(void)
{
    uint8_t encrypted_buffer[1024] = {0};
    uint8_t decrypted_buffer[1024] = {0};
    size_t chunkSize = 0;
    uint32_t imageSize = 0;
    uint32_t bytesReceived = 0;
    uintptr_t address = (uintptr_t)APPLICATION_ADDRESS;
    uint32_t expectedCRC = 0;
    uint32_t computedCRC = 0;
    if (chnRead((BaseChannel *)&SDU1, (uint8_t *)&imageSize, 4) == 4)
    {
        uint8_t ack = 0x55;
        chnWrite((BaseChannel *)&SDU1, &ack, 1);
    }
    else
    {
        return 1; // Error code 1: failed to receive image size.
    }

    if ((imageSize == 0) || (imageSize > MAX_IMAGE_SIZE))
    {
        return 2; // Error code 2: image size sanity check failed.
    }
    uint32_t sectorsN = (imageSize + SECTOR_SIZE - 1) / SECTOR_SIZE;
    for (uint32_t i = 1; i < sectorsN + 1; i++)
    {
        Flash::EraseSector(i, 0);
        if (i >= 8)
        {
            Flash::EraseSector(i - 8, 1);
        }
    }
    while (bytesReceived < imageSize)
    {
        chunkSize = ((sizeof(encrypted_buffer)) < (imageSize - bytesReceived)) ? (sizeof(encrypted_buffer)) : (imageSize - bytesReceived);
        if (chnRead((BaseChannel *)&SDU1, encrypted_buffer, chunkSize) != chunkSize)
        {
            return 3; // Error code 3: failed to receive firmware data chunk.
        }
        decrypt_chunk(encrypted_buffer, decrypted_buffer, chunkSize);
        if (address < 0x08100000)
        {
            Flash::Write(address, reinterpret_cast<const char *>(decrypted_buffer), chunkSize, 0);
        }
        else
        {
            Flash::Write(address, reinterpret_cast<const char *>(decrypted_buffer), chunkSize, 1);
        }
        address += chunkSize;
        bytesReceived += chunkSize;
    }
    if (bytesReceived != imageSize)
    {
        return 4; // Error code 4: total firmware data length mismatch.
    }

    uint8_t crcBytes[4] = {0};
    if (chnRead((BaseChannel *)&SDU1, crcBytes, sizeof(crcBytes)) != 4)
    {
        return 5; // Error code 5: failed to receive CRC.
    }
    expectedCRC = (static_cast<uint32_t>(crcBytes[0]) |
                   ((static_cast<uint32_t>(crcBytes[1])) << 8) |
                   ((static_cast<uint32_t>(crcBytes[2])) << 16) |
                   ((static_cast<uint32_t>(crcBytes[3])) << 24));
    computedCRC = crc32(reinterpret_cast<const uint8_t *>(APPLICATION_ADDRESS), imageSize);
    if (computedCRC != expectedCRC)
    {
        return 6; // Error code 6: CRC mismatch.
    }
    return 0; // Success.
}

void read_command(void)
{
    uint8_t command[4] = {0};
    if (chnReadTimeout((BaseChannel *)&SDU1, command, 4, TIME_MS2I(2000)) != 4)
    {
        return; // Error reading command
    }
    if (command[0] == 'U' && command[1] == 'P' && command[2] == 'D' && command[3] == 'T')
    {
        uint8_t result = performUpdate();
        if (result != 0)
        {
            chnWrite((BaseChannel *)&SDU1, &result, 1); // Send error code
        }
        else
        {
            uint8_t ack = 0xAA; // Acknowledge success
            chnWrite((BaseChannel *)&SDU1, &ack, 1);
            chThdSleepMilliseconds(100);
            NVIC_SystemReset();
        }
    }
    else
    {
        uint8_t error = 0xFF; // Unknown command
        chnWrite((BaseChannel *)&SDU1, &error, 1);
    }
}

void boot_app(void)
{
    uint32_t sp_value;
    pAppEntry_t app_entry;

    sduStop(&SDU1);
    chSysDisable();

    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL = 0;

    SCB_DisableDCache();
    SCB_DisableICache();

    sp_value = (uint32_t)*((__IO uint32_t *)APPLICATION_ADDRESS);
    app_entry = (pAppEntry_t) * (__IO uint32_t *)(APPLICATION_ADDRESS + 4UL);
    SCB->VTOR = APPLICATION_ADDRESS;
    __set_MSP(sp_value);
    app_entry();
}

int main(void)
{
    halInit();
    chSysInit();
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);
    crcStart(&CRCD1, NULL);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1500); // Wait for host to recognize disconnect
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(3000);

    while (true)
    {
        if (usbGetDriverStateI(serusbcfg.usbp) == USB_ACTIVE) {
            read_command();
        }
        //if (check_application_crc()) {
            boot_app();
        //}
        palTogglePad(GPIOC, 13U);
        chThdSleepMilliseconds(100);
    }
}