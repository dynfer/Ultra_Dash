#include "lvgl_thread.h"

uint8_t frame_buffer1[600 * 1024 * 2 / 10] __attribute__((section(".ram0"), aligned(4)));
uint8_t frame_buffer_optional[600 * 1024 * 2 / 10] __attribute__((section(".ram0"), aligned(4)));

uint8_t frame_buffer[600 * 1024 * 2] __attribute__((section(".sdram"), aligned(4))); /**< Frame buffer for LTDC. Height * Width * Bytes_per_pixel, additional settings can be applied like section(.sdram) */

static const ltdc_window_t ltdc_fullscreen_wincfg = {
    .hstart = 0,
    .hstop = 1024 - 1,
    .vstart = 0,
    .vstop = 600 - 1,
};

static const ltdc_frame_t ltdc_view_frmcfg1 = {
    .bufferp = frame_buffer,
    .width = 1024,
    .height = 600,
    .pitch = (1024 * 2), /**< Width * bytes per pixel */
    .fmt = LTDC_FMT_RGB565};

static const ltdc_laycfg_t ltdc_view_laycfg1 = {
    .frame = &ltdc_view_frmcfg1,
    .window = &ltdc_fullscreen_wincfg,
    .def_color = LTDC_COLOR_FUCHSIA,
    .const_alpha = 0xFF,
    .key_color = 0xFFFFFF,
    .pal_colors = NULL,
    .pal_length = 0,
    .blending = 255,
    .flags = static_cast<ltdc_flags_t>(LTDC_BLEND_FIX1_FIX2 | LTDC_LEF_ENABLE)};

static const LTDCConfig ltdc_cfg = {
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
    .line_isr = NULL,                                      /**< Line Interrupt ISR, or @p NULL.*/
    .rr_isr = (ltdc_isrcb_t)reload_event_callback_handler, /**< Register Reload ISR, or @p NULL.*/
    .fuerr_isr = NULL,                                     /**< FIFO Underrun ISR, or @p NULL.*/
    .terr_isr = NULL,                                      /**< Transfer Error ISR, or @p NULL.*/

    /* Color and layer settings.*/
    .clear_color = LTDC_COLOR_TEAL,
    .bg_laycfg = &ltdc_view_laycfg1,
    .fg_laycfg = NULL,
};

static THD_WORKING_AREA(waLV_TIMER_HANDLER, 8192);
static THD_FUNCTION(LV_TIMER_HANDLER, arg)
{
    (void)arg;
    chRegSetThreadName("LV_TIMER_HANDLER");
    uint32_t sleep = 0;
    while (true)
    {
        sleep = lv_timer_handler();
        if (sleep == LV_NO_TIMER_READY)
        {
            sleep = LV_DEF_REFR_PERIOD;
        }
        if (sleep <= 0)
        {
            continue;
        }
        chThdSleepMilliseconds(sleep);
    }
}

static THD_WORKING_AREA(waLV_GFX, 8192);
static THD_FUNCTION(LV_GFX, arg)
{
    chRegSetThreadName("LV_GFX_HANDLER");

    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_layout(screen, LV_LAYOUT_NONE);
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);

    auto container = createDefaultLayout(screen);

    auto sensorTable = static_cast<sensorContainer*>(arg);

    lv_scr_load(screen);

    bool gorpm = true;
    uint32_t rpm = 0;
    float testvalue = 0.0f;
    while (true)
    {
        rpm_bar_set_value(container->rpmBar, getSensorPtr(sensorTable, SensorEnum::RPM)->getValue());
        for(size_t i = 0; i < 8; i++)
        {
            value_bar_set_value(container->slideGauge[i], getSensorPtr(sensorTable, config.slideGauges[i].type)->getValue());
        }
        
        gauge_set_value(container->mainGauge, getSensorPtr(sensorTable, config.mainGauge.type)->getValue());

        chThdSleepMilliseconds(33);
    }
}

virtual_timer_t vt;

static void tick_inc_callback(virtual_timer_t *vtp, void *p)
{
    (void)vtp;
    (void)p;

    lv_tick_inc(1);
}

void startLVGL(sensorContainer *sensors)
{
    palSetPad(GPIOH, 6U);
    lv_init();
    ltdcInit();
    ltdcStart(&LTDCD1, &ltdc_cfg);
    lv_display_t *disp = lv_st_ltdc_create_partial(frame_buffer1, frame_buffer_optional, sizeof(frame_buffer_optional), 0);
    lv_display_set_default(disp);
    chThdCreateStatic(waLV_TIMER_HANDLER, sizeof(waLV_TIMER_HANDLER), NORMALPRIO + 8, LV_TIMER_HANDLER, NULL);
    chVTSetContinuous(&vt, TIME_MS2I(1), tick_inc_callback, NULL);
    chThdCreateStatic(waLV_GFX, sizeof(waLV_GFX), NORMALPRIO, LV_GFX, sensors);
}