#pragma once

#if __has_include("lvgl.h")
#  include "lvgl.h"
#else
#  include "lvgl/lvgl.h"
#endif

#include "canbroadcast.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float     min;                // e.g. 0.0f (can be negative)
    float     max;                // e.g. 10.0f
    uint8_t   decimals;           // digits after decimal in the value label
    uint8_t   warn_start_pct;     // start blending at this % (0..100), default 70

    const char *unit;             // e.g. "bar" (may be NULL)
    const char *name;             // e.g. "OIL PRESS" (may be NULL)

    // Colors
    lv_color_t col_track;         // bar track color (background of bar)
    lv_color_t col_fill_low;      // yellow part
    lv_color_t col_fill_high;     // red part
    lv_color_t col_text_main;     // value text
    lv_color_t col_text_name;     // name text
    lv_color_t col_scale;         // scale text/ticks

    // Sizes
    uint16_t   track_radius;      // px corner radius of track/fill
    uint16_t   tick_h;            // tick height (px)
    SensorEnum type;
} value_bar_cfg_t;

lv_obj_t * value_bar_create(lv_obj_t *parent, const value_bar_cfg_t *cfg_opt);

void        value_bar_set_value(lv_obj_t *obj, float v);

void        value_bar_set_range(lv_obj_t *obj, float min, float max);
void        value_bar_set_unit(lv_obj_t *obj, const char *unit);
void        value_bar_set_name(lv_obj_t *obj, const char *name);
void        value_bar_set_warn_pct(lv_obj_t *obj, uint8_t pct);

void        value_bar_set_config(lv_obj_t *obj, const value_bar_cfg_t *cfg);
value_bar_cfg_t value_bar_default_config(void);

#ifdef __cplusplus
}
#endif
