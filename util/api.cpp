#include "util/api.h"

static constexpr uint32_t PACKET_SZ = 64;
static constexpr uint32_t DCACHE_LINE = 32;

static void get_config_usb(void);
static void burn_config_from_usb(void);

static uint32_t crc32(const uint8_t *buf, size_t len)
{
    uint32_t crc = ~0u;
    while (len--)
    {
        crc ^= *buf++;
        for (int i = 0; i < 8; i++)
            crc = (crc >> 1) ^ (0xEDB88320u & -(crc & 1));
    }
    return ~crc;
}

static void get_config_usb(void)
{
    chnWrite(&SDU1, reinterpret_cast<const uint8_t *>(&config), sizeof(config));
    uint32_t crc = crc32(reinterpret_cast<const uint8_t *>(&config), sizeof(config));
    chnWrite(&SDU1, reinterpret_cast<const uint8_t *>(&crc), sizeof(crc));
}

static void burn_config_from_usb(void)
{
    uint8_t buffer[sizeof(config)];
    size_t bytesRead = chnRead(&SDU1, buffer, sizeof(buffer));
    if (bytesRead <= 0 || bytesRead != sizeof(config))
    {
        return;
    }
    else
    {
        memcpy(&config, buffer, sizeof(config));
    }
    config_save();
    chThdSleepMilliseconds(10);
    NVIC_SystemReset();
}

void read_command(void)
{
    uint8_t buffer[4] = {0};
    chnReadTimeout(&SDU1, buffer, 4, 100);
    switch (classifyCommand(buffer))
    {
    case Command::Read:
        get_config_usb();
        break;
    case Command::Write:
        burn_config_from_usb();
        break;
    case Command::Defaults:
        load_default();
        NVIC_SystemReset();
        break;
    default:
        break;
    }
}