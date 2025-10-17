#include "flash.h"

static void flashWaitWhileBusy(uint8_t bank)
{
    switch (bank)
    {
    case 0:
        do
        {
            __DSB();
        } while (FLASH->SR1 & FLASH_SR_QW);
        break;
    case 1:
        do
        {
            __DSB();
        } while (FLASH->SR2 & FLASH_SR_QW);
        break;

    default:
        break;
    }
}

static void flashUnlock(uint8_t bank)
{
    switch (bank)
    {
    case 0:
        // Check if FLASH Bank 2 is locked
        if (!(FLASH->CR1 & FLASH_CR_LOCK))
        {
            return;
        }
        // FLASH Bank 2 unlock sequence
        FLASH->KEYR1 = 0x45670123;
        FLASH->KEYR1 = 0xCDEF89AB;
        break;
    case 1:
        // Check if FLASH Bank 2 is locked
        if (!(FLASH->CR2 & FLASH_CR_LOCK))
        {
            return;
        }
        // FLASH Bank 2 unlock sequence
        FLASH->KEYR2 = 0x45670123;
        FLASH->KEYR2 = 0xCDEF89AB;
        break;

    default:
        break;
    }
}

static void flashLock(uint8_t bank)
{
    switch (bank)
    {
    case 0:
        FLASH->CR1 |= FLASH_CR_LOCK;
        break;
    case 1:
        FLASH->CR2 |= FLASH_CR_LOCK;
        break;
    default:
        break;
    }
}

void Flash::EraseSector(uint8_t sectorIdx, uint8_t bank)
{
    flashUnlock(bank);

    flashWaitWhileBusy(bank);

    switch (bank)
    {
    case 0:
        FLASH->CR1 &= ~FLASH_CR_SNB_Msk;
        FLASH->CR1 |= (sectorIdx << FLASH_CR_SNB_Pos) & FLASH_CR_SNB_Msk;
        // Select sector erase mode
        FLASH->CR1 |= FLASH_CR_SER;
        // Start sector erase
        FLASH->CR1 |= FLASH_CR_START;
        flashWaitWhileBusy(bank);
        // Clear sector erase bit
        FLASH->CR1 &= ~FLASH_CR_SER;
        break;
    case 1:
        FLASH->CR2 &= ~FLASH_CR_SNB_Msk;
        FLASH->CR2 |= (sectorIdx << FLASH_CR_SNB_Pos) & FLASH_CR_SNB_Msk;
        // Select sector erase mode
        FLASH->CR2 |= FLASH_CR_SER;
        // Start sector erase
        FLASH->CR2 |= FLASH_CR_START;
        flashWaitWhileBusy(bank);
        // Clear sector erase bit
        FLASH->CR2 &= ~FLASH_CR_SER;
        break;
    default:
        break;
    }
    flashLock(bank);
}
void Flash::Write(flashaddr_t address, const char *buffer, size_t size, uint8_t bank)
{
    flashUnlock(bank);
    flashWaitWhileBusy(bank);
    size_t flashWordCount = (size - 1) / 16 + 1;
    const flashdata_t *pRead = (const flashdata_t *)buffer;
    flashdata_t *pWrite = (flashdata_t *)address;
    switch (bank)
    {
    case 0:
        for (size_t word = 0; word < flashWordCount; word++)
        {
            /* Enter flash programming mode */
            FLASH->CR1 |= FLASH_CR_PG;

            // Flush pipelines
            __ISB();
            __DSB();

            // Write 32 bytes
            for (size_t i = 0; i < 4; i++)
            {
                *pWrite++ = *pRead++;
            }

            // Flush pipelines
            __ISB();
            __DSB();

            /* Wait for completion */
            flashWaitWhileBusy(bank);

            /* Exit flash programming mode */
            FLASH->CR1 &= ~FLASH_CR_PG;

            // Flush pipelines
            __ISB();
            __DSB();
        }
        break;
    case 1:
        for (size_t word = 0; word < flashWordCount; word++)
        {
            /* Enter flash programming mode */
            FLASH->CR2 |= FLASH_CR_PG;

            // Flush pipelines
            __ISB();
            __DSB();

            // Write 32 bytes
            for (size_t i = 0; i < 4; i++)
            {
                *pWrite++ = *pRead++;
            }

            // Flush pipelines
            __ISB();
            __DSB();

            /* Wait for completion */
            flashWaitWhileBusy(bank);

            /* Exit flash programming mode */
            FLASH->CR2 &= ~FLASH_CR_PG;

            // Flush pipelines
            __ISB();
            __DSB();
        }
        break;
    default:
        break;
    }
    // Re-lock flash after operation
    flashLock(bank);
}