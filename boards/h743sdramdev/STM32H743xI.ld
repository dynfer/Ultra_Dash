/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * STM32H743xI generic setup with W9825G6KH5 SDRAM.
 */

MEMORY
{
    blflash (rx) : org = 0x08000000, len = 128k
    configbl (rx) : org = 0x08020000, len = 1k
    flash0 (rx) : org = 0x08020400, len = 2m - 128k - 1k        /* Flash bank1+bank2 */
    flash1 (rx) : org = 0x08000000, len = 1m        /* Flash bank 1 */
    flash2 (rx) : org = 0x08100000, len = 1m - 128k        /* Flash bank 2 */
    config (rx) : org = 0x081E0000, len = 128k
    flash3 (rx) : org = 0x00000000, len = 0
    flash4 (rx) : org = 0x00000000, len = 0
    flash5 (rx) : org = 0x00000000, len = 0
    flash6 (rx) : org = 0x00000000, len = 0
    flash7 (rx) : org = 0x00000000, len = 0
    ram0   (wx) : org = 0x24000000, len = 512k      /* AXI SRAM */
    ram1   (wx) : org = 0x30000000, len = 256k      /* AHB SRAM1+SRAM2 */
    ram2   (wx) : org = 0x30000000, len = 288k      /* AHB SRAM1+SRAM2+SRAM3 */
    ram3   (wx) : org = 0x30040000, len = 32k       /* AHB SRAM3 */
    ram4   (wx) : org = 0x38000000, len = 64k       /* AHB SRAM4 */
    ram5   (wx) : org = 0x20000000, len = 128k      /* DTCM-RAM */
    ram6   (wx) : org = 0x00000000, len = 64k       /* ITCM-RAM */
    ram7   (wx) : org = 0x38800000, len = 4k        /* BCKP SRAM */
    sdram  (wx) : org = 0xc0000000, len = 32M        /* External SDRAM (W9825G6KH5) */
}

__config_start__ = ORIGIN(config);
__config_size__ = LENGTH(config);

/* For each data/text section two regions are defined, a virtual region
   and a load region (_LMA suffix).*/

/* Flash region to be used for exception vectors.*/
REGION_ALIAS("VECTORS_FLASH", flash0);
REGION_ALIAS("VECTORS_FLASH_LMA", flash0);

/* Flash region to be used for constructors and destructors.*/
REGION_ALIAS("XTORS_FLASH", flash0);
REGION_ALIAS("XTORS_FLASH_LMA", flash0);

/* Flash region to be used for code text.*/
REGION_ALIAS("TEXT_FLASH", flash0);
REGION_ALIAS("TEXT_FLASH_LMA", flash0);

/* Flash region to be used for read-only data.*/
REGION_ALIAS("RODATA_FLASH", flash0);
REGION_ALIAS("RODATA_FLASH_LMA", flash0);

/* Flash region to be used for various.*/
REGION_ALIAS("VARIOUS_FLASH", flash0);
REGION_ALIAS("VARIOUS_FLASH_LMA", flash0);

/* Flash region to be used for RAM(n) initialization data.*/
REGION_ALIAS("RAM_INIT_FLASH_LMA", flash0);

/* RAM region to be used for Main stack. */
REGION_ALIAS("MAIN_STACK_RAM", ram5);

/* RAM region to be used for the process stack. */
REGION_ALIAS("PROCESS_STACK_RAM", ram5);

/* RAM region to be used for data segment.*/
REGION_ALIAS("DATA_RAM", ram0);
REGION_ALIAS("DATA_RAM_LMA", flash0);

/* RAM region to be used for BSS segment.*/
REGION_ALIAS("BSS_RAM", ram0);

/* RAM region to be used for the default heap.*/
REGION_ALIAS("HEAP_RAM", ram0);

/* RAM region to be used for SDRAM.*/
REGION_ALIAS("SDRAM_RAM", sdram);

/* Stack rules inclusion.*/
INCLUDE ChibiOS/os/common/startup/ARMCMx/compilers/GCC/ld/rules_stacks.ld

/*===========================================================================*/
/* Custom sections for STM32H7xx.                                            */
/*===========================================================================*/

/* Code rules inclusion.*/
INCLUDE ChibiOS/os/common/startup/ARMCMx/compilers/GCC/ld/rules_code.ld

/* Data rules inclusion.*/
INCLUDE ChibiOS/os/common/startup/ARMCMx/compilers/GCC/ld/rules_data.ld

/* Memory rules inclusion.*/
INCLUDE ChibiOS/os/common/startup/ARMCMx/compilers/GCC/ld/rules_memory.ld

/* SDRAM rules */
INCLUDE boards/h743sdramdev/sdram_rules.ld