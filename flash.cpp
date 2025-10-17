#include "ch.h"
#include "hal.h"
#include "flash.h"

static void flashWaitWhileBusy()
{
    // Wait until FLASH Bank 2 is no longer busy
    do
    {
        __DSB();
    } while (FLASH->SR2 & FLASH_SR_QW);
}

static void flashUnlock()
{
    // Check if FLASH Bank 2 is locked
    if (!(FLASH->CR2 & FLASH_CR_LOCK))
        return;

    // FLASH Bank 2 unlock sequence
    FLASH->KEYR2 = 0x45670123;
    FLASH->KEYR2 = 0xCDEF89AB;
}

static void flashLock()
{
    // Lock FLASH Bank 2
    FLASH->CR2 |= FLASH_CR_LOCK;
}

void Flash::EraseSector(uint8_t sectorIdx)
{
    flashUnlock();

    flashWaitWhileBusy();

    // Select sector erase mode
    FLASH->CR2 &= ~(FLASH_CR_PSIZE_0 | FLASH_CR_PSIZE_1);
	FLASH->CR2 |= FLASH_CR_PSIZE_1;
    FLASH->CR2 &= ~FLASH_CR_SNB_Msk;
    FLASH->CR2 |= (sectorIdx << FLASH_CR_SNB_Pos) & FLASH_CR_SNB_Msk;
    FLASH->CR2 |= FLASH_CR_SER;


    // Start sector erase
    FLASH->CR2 |= FLASH_CR_START;

    flashWaitWhileBusy();

    // Clear sector erase bit
    FLASH->CR2 &= ~FLASH_CR_SER;

    flashLock();
}
void Flash::Write(flashaddr_t address, const char* buffer, size_t size)
{
    flashUnlock();

    flashWaitWhileBusy();

    FLASH->CR2 &= ~(FLASH_CR_PSIZE_0 | FLASH_CR_PSIZE_1);
	FLASH->CR2 |= FLASH_CR_PSIZE_1;

    size_t flashWordCount = (size - 1) / 32 + 1;

    const flashdata_t* pRead = (const flashdata_t*)buffer;
	flashdata_t* pWrite = (flashdata_t*)address;

	for (size_t word = 0; word < flashWordCount; word++) {
		/* Enter flash programming mode */
		FLASH->CR2 |= FLASH_CR_PG;

		// Flush pipelines
		__ISB();
		__DSB();

		// Write 32 bytes
		for (size_t i = 0; i < 8; i++) {
			*pWrite++ = *pRead++;
		}
		
		// Flush pipelines
		__ISB();
		__DSB();

		/* Wait for completion */
		flashWaitWhileBusy();

		/* Exit flash programming mode */
		FLASH->CR2 &= ~FLASH_CR_PG;

		// Flush pipelines
		__ISB();
		__DSB();
	}
    // Re-lock flash after operation
    flashLock();
}