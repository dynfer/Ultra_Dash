#ifndef LV_THREAD_H
#define LV_THREAD_H

#include "ch.h"
#include "hal.h"
#include "lvgl/lvgl.h"
#include "hal_stm32_ltdc.h"
#include "lvgl/src/drivers/display/st_ltdc_chibios/lv_st_ltdc_chibios.h" // Required for the reload_event_callback_handler
#include "layout.h"
#include "config_struct.h"

#ifdef __cplusplus
extern "C" {
#endif

void startLVGL(sensorContainer *sensors);

#ifdef __cplusplus
}
#endif

#endif