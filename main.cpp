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
#include "ch.h"
#include "hal.h"
#include "hal_sdram.h"
#include "hal_sdram_lld.h"
#include "util/usb_config.h"
#include "util/sdram.h"
#include <string.h>
#include "gfx/lvgl_thread.h"
#include "flash/config_struct.h"
#include "can/can.h"
#include "gfx/layout.h"

#define VECTOR_TABLE_SIZE ((WAKEUP_PIN_IRQn + 1 + 16) * sizeof(uint32_t))

__attribute__((section(".configbl"), used))
const uint32_t boot_data_placeholder[2] = { 0xFFFFFFFF, 0xFFFFFFFF };


static void sdram_bulk_erase(void)
{
  memset((uint32_t *)(SDRAM_BANK_ADDR), 0, (uint32_t)(W9825G6KH5_SIZE));
}

void relocate_vector_to_sram(void)
{
  memcpy((void *)0x20000000, (void *)0x08020400, VECTOR_TABLE_SIZE);
  SCB->VTOR = 0x20000000;
  __DSB();
  __ISB();
}

int main(void)
{

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  relocate_vector_to_sram();
  halInit();
  chSysInit();

  sdramInit();
  sdramStart(&SDRAMD1, &sdram_cfg);
  sdram_bulk_erase();
  config_load();
  static sensorContainer sensors;
  initCan(&sensors);

  startLVGL(&sensors);
  //startTouch();
  startUsb();

  while (1)
  {
    palTogglePad(GPIOC, 13U);
    chThdSleepMilliseconds(100);
  }
}