#pragma once

#include "ch.h"
#include "hal.h"
#include "lvgl/lvgl.h"
#include "hal_stm32_ltdc.h"
#include "lvgl/src/drivers/display/st_ltdc_chibios/lv_st_ltdc_chibios.h" // Required for the reload_event_callback_handler
#include "gfx/layout.h"
#include "flash/config_struct.h"

static uint8_t frame_buffer1[600 * 1024 * 2 / 10] __attribute__((section(".ram0"), aligned(4)));
static uint8_t frame_buffer_optional[600 * 1024 * 2 / 10] __attribute__((section(".ram0"), aligned(4)));

static uint8_t frame_buffer[600 * 1024 * 2] __attribute__((section(".sdram"), aligned(4))); /**< Frame buffer for LTDC. Height * Width * Bytes_per_pixel, additional settings can be applied like section(.sdram) */

static void rr_isr_shim(LTDCDriver *ldp) {
    (void)ldp;
    reload_event_callback_handler();
}

static constexpr ltdc_window_t ltdc_fullscreen_wincfg = {
    .hstart = 0,
    .hstop = 1024 - 1,
    .vstart = 0,
    .vstop = 600 - 1,
};

static constexpr ltdc_frame_t ltdc_view_frmcfg1 = {
    .bufferp = frame_buffer,
    .width = 1024,
    .height = 600,
    .pitch = (1024 * 2), /**< Width * bytes per pixel */
    .fmt = LTDC_FMT_RGB565};

static constexpr ltdc_laycfg_t ltdc_view_laycfg1 = {
    .frame = &ltdc_view_frmcfg1,
    .window = &ltdc_fullscreen_wincfg,
    .def_color = LTDC_COLOR_FUCHSIA,
    .const_alpha = 0xFF,
    .key_color = 0xFFFFFF,
    .pal_colors = NULL,
    .pal_length = 0,
    .blending = 255,
    .flags = static_cast<ltdc_flags_t>(LTDC_BLEND_FIX1_FIX2 | LTDC_LEF_ENABLE)};

static constexpr LTDCConfig ltdc_cfg = {
    /* Display specifications.*/
    .screen_width = 1024, /**< Screen pixel width.*/
    .screen_height = 600, /**< Screen pixel height.*/
    .hsync_width = 1,     /**< Horizontal sync pixel width.*/
    .vsync_height = 3,    /**< Vertical sync pixel height.*/
    .hbp_width = 46,      /**< Horizontal back porch pixel width.*/
    .vbp_height = 23,     /**< Vertical back porch pixel height.*/
    .hfp_width = 40,      /**< Horizontal front porch pixel width.*/
    .vfp_height = 10,     /**< Vertical front porch pixel height.*/
    .flags = 0,           /**< Driver configuration flags.*/

    /* ISR callbacks.*/
    .line_isr = NULL,    /**< Line Interrupt ISR, or @p NULL.*/
    .rr_isr = rr_isr_shim, /**< Register Reload ISR, or @p NULL.*/
    .fuerr_isr = NULL,   /**< FIFO Underrun ISR, or @p NULL.*/
    .terr_isr = NULL,    /**< Transfer Error ISR, or @p NULL.*/

    /* Color and layer settings.*/
    .clear_color = LTDC_COLOR_TEAL,
    .bg_laycfg = &ltdc_view_laycfg1,
    .fg_laycfg = NULL,
};

void startLVGL(sensorContainer *sensors);