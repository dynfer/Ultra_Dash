#pragma once

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "can/canbroadcast.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* ====================== Config ====================== */
    typedef struct
    {
        /* Range and formatting */
        float min;        // e.g. 0.0f (can be negative)
        float max;        // e.g. 8000.0f
        uint8_t decimals; // digits after decimal for the value label

        /* Geometry (degrees, clockwise; 0° points right) */
        uint16_t start_deg; // e.g. 135
        uint16_t sweep_deg; // e.g. 270

        /* Thresholds */
        float redline; // value where red arc starts (clamped to [min..max])

        /* Labels */
        const char *unit; // e.g. "rpm" (may be NULL)
        const char *name; // e.g. "RPM" (may be NULL)

        /* Colors */
        lv_color_t col_arc;       // main (value) arc color
        lv_color_t col_red;       // redline arc color
        lv_color_t col_text_main; // numeric value text
        lv_color_t col_text_name; // name text
        lv_color_t col_scale;     // scale ticks/labels

        /* Sizes (pixels) */
        uint16_t tick_len_minor;
        uint16_t tick_len_major;
        uint16_t arc_width; // stroke width of arcs (0 => auto based on widget size)
        SensorEnum type;
    } gauge_cfg_t;

    lv_obj_t *gauge_create(lv_obj_t *parent, const gauge_cfg_t *cfg_opt);

    void gauge_set_value(lv_obj_t *obj, float v);

    void gauge_set_range(lv_obj_t *obj, float min, float max);
    void gauge_set_unit(lv_obj_t *obj, const char *unit);
    void gauge_set_name(lv_obj_t *obj, const char *name);
    void gauge_set_redline(lv_obj_t *obj, float redline);

    void gauge_set_config(lv_obj_t *obj, const gauge_cfg_t *cfg);
    gauge_cfg_t gauge_default_config(void);

#ifdef __cplusplus
}
#endif