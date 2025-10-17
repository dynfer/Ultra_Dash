#include "lvgl_thread.h"

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