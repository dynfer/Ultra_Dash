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
    uint32_t min_rpm;
    uint32_t max_rpm;
    uint32_t redline_rpm;
    uint16_t segments;
    uint16_t gap_px;
    uint16_t corner_radius;

    uint16_t band_height_left_permil;
    uint16_t band_height_right_permil;
    uint16_t baseline_permil;

    lv_color_t col_inactive;
    lv_color_t col_active;
    lv_color_t col_red;

    lv_color_t col_bg;
    uint8_t    bg_opa;
    SensorEnum type;
} rpm_bar_cfg_t;

lv_obj_t * rpm_bar_create(lv_obj_t * parent, const rpm_bar_cfg_t * cfg_opt);

void        rpm_bar_set_value(lv_obj_t * obj, uint32_t rpm);
uint32_t    rpm_bar_get_value(lv_obj_t * obj);

void        rpm_bar_set_config(lv_obj_t * obj, const rpm_bar_cfg_t * cfg);
rpm_bar_cfg_t rpm_bar_default_config(void);

lv_obj_t *  rpm_bar_get_label(lv_obj_t * obj);

#ifdef __cplusplus
}
#endif
