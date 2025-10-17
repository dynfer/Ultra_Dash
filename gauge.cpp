#include "gauge.h"
#include <stdio.h>

typedef struct
{
    gauge_cfg_t cfg;
    float value;

    lv_obj_t *scale;
    lv_obj_t *arc_red;
    lv_obj_t *arc_val;
    lv_obj_t *lbl_value;
    lv_obj_t *lbl_name;
} gauge_state_t;

static inline float clampf(float v, float lo, float hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
static inline int16_t value_to_angle(const gauge_state_t *st, float v)
{
    const float min = st->cfg.min, max = st->cfg.max;
    if (max == min) return (int16_t)st->cfg.start_deg;
    float t = (v - min) / (max - min);
    if (t < 0.f) t = 0.f;
    if (t > 1.f) t = 1.f;
    return (int16_t)(st->cfg.start_deg + (float)st->cfg.sweep_deg * t);
}
static void fmt_value(char *buf, size_t n, float v, uint8_t decimals, const char *unit)
{
    char fmt[8];
    if (decimals > 3) decimals = 3;
    lv_snprintf(fmt, sizeof(fmt), "%%.%uf", (unsigned)decimals);
    int used = lv_snprintf(buf, n, fmt, (double)v);
    if (unit && used > 0 && (size_t)used < n) {
        lv_snprintf(buf + used, n - (size_t)used, " %s", unit);
    }
}

static void layout_update(lv_obj_t *obj)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;

    const lv_coord_t w = lv_obj_get_content_width(obj);
    const lv_coord_t h = lv_obj_get_content_height(obj);
    lv_coord_t s = w < h ? w : h;
    if (s < 10) s = 10;

    const lv_coord_t pad_outer = s / 16;
    const lv_coord_t pad_label = s / 8;

    lv_coord_t scale_size = s - pad_outer * 2 - pad_label / 3;
    if (scale_size < 10) scale_size = 10;

    lv_obj_set_size(st->scale, scale_size, scale_size);
    lv_obj_center(st->scale);
    lv_obj_set_y(st->scale, pad_label / 2);

    lv_coord_t thick = st->cfg.arc_width ? (lv_coord_t)st->cfg.arc_width : (scale_size / 18);
    if (thick < 3) thick = 3;

    lv_obj_set_size(st->arc_val, scale_size, scale_size);
    lv_obj_set_style_arc_width(st->arc_val, thick, LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(st->arc_val, thick, LV_PART_MAIN);

    lv_obj_set_size(st->arc_red, scale_size, scale_size);
    lv_obj_set_style_arc_width(st->arc_red, thick, LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(st->arc_red, thick, LV_PART_MAIN);

    lv_obj_align(st->lbl_name, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_align(st->lbl_value, LV_ALIGN_CENTER, 0, 0);
}

static void setup_static(lv_obj_t *obj)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;

    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_set_style_pad_all(st->scale, 0, 0);
    lv_obj_set_style_pad_all(st->arc_red, 0, 0);
    lv_obj_set_style_pad_all(st->arc_val, 0, 0);
    lv_obj_set_style_pad_all(st->lbl_value, 0, 0);
    lv_obj_set_style_pad_all(st->lbl_name, 0, 0);

    lv_scale_set_mode(st->scale, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_rotation(st->scale, st->cfg.start_deg);
    lv_scale_set_angle_range(st->scale, st->cfg.sweep_deg);
    lv_scale_set_range(st->scale, st->cfg.min, st->cfg.max);
    lv_scale_set_total_tick_count(st->scale, 21);
    lv_scale_set_major_tick_every(st->scale, 5);
    lv_scale_set_label_show(st->scale, true);

    lv_obj_set_style_length(st->scale, st->cfg.tick_len_minor, LV_PART_ITEMS);
    lv_obj_set_style_line_width(st->scale, 1, LV_PART_ITEMS);
    lv_obj_set_style_length(st->scale, st->cfg.tick_len_major, LV_PART_INDICATOR);
    lv_obj_set_style_line_width(st->scale, 2, LV_PART_INDICATOR);
    lv_obj_set_style_translate_y(st->scale, 6, LV_PART_INDICATOR);

    lv_obj_set_style_text_color(st->scale, st->cfg.col_scale, LV_PART_ITEMS);
    lv_obj_set_style_text_color(st->scale, st->cfg.col_scale, LV_PART_MAIN);
    lv_obj_set_style_line_color(st->scale, st->cfg.col_scale, LV_PART_ITEMS);
    lv_obj_set_style_line_color(st->scale, st->cfg.col_scale, LV_PART_INDICATOR);

    lv_obj_set_style_bg_opa(st->arc_red, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(st->arc_red, LV_OPA_TRANSP, LV_PART_KNOB);
    lv_obj_set_style_arc_opa(st->arc_red, LV_OPA_20,    LV_PART_MAIN);
    lv_obj_set_style_arc_opa(st->arc_red, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(st->arc_red, st->cfg.col_red, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(st->arc_red, st->cfg.col_red, LV_PART_MAIN);

    lv_obj_set_style_bg_opa(st->arc_val, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(st->arc_val, LV_OPA_TRANSP, LV_PART_KNOB);
    lv_obj_set_style_arc_opa(st->arc_val, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_opa(st->arc_val, LV_OPA_COVER,  LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(st->arc_val, st->cfg.col_arc, LV_PART_INDICATOR);

    lv_arc_set_rotation(st->arc_red, 0);
    lv_arc_set_bg_angles(st->arc_red, st->cfg.start_deg, st->cfg.start_deg + st->cfg.sweep_deg);

    const int16_t red_a1 = value_to_angle(st, clampf(st->cfg.redline, st->cfg.min, st->cfg.max));
    const int16_t red_a2 = value_to_angle(st, st->cfg.max);
    lv_arc_set_angles(st->arc_red, red_a1, red_a2);

    lv_arc_set_rotation(st->arc_val, 0);
    lv_arc_set_bg_angles(st->arc_val, st->cfg.start_deg, st->cfg.start_deg + st->cfg.sweep_deg);

    lv_obj_set_style_text_align(st->lbl_value, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font (st->lbl_value, lv_theme_get_font_large(st->lbl_value), 0);
    lv_obj_set_style_text_color(st->lbl_value, st->cfg.col_text_main, 0);

    lv_obj_set_style_text_align(st->lbl_name, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font (st->lbl_name,  lv_theme_get_font_normal(st->lbl_name), 0);
    lv_obj_set_style_text_color(st->lbl_name,  st->cfg.col_text_name, 0);
    lv_label_set_text(st->lbl_name, st->cfg.name ? st->cfg.name : "");
}

static void on_size_or_style(lv_event_t *e)
{
    lv_obj_t *obj = static_cast<lv_obj_t*>(lv_event_get_target(e));
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;
    layout_update(obj);
    gauge_set_value(obj, st->value);
}
static void on_delete(lv_event_t *e)
{
    lv_obj_t *obj = static_cast<lv_obj_t*>(lv_event_get_target(e));
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (st) lv_free(st);
}

lv_obj_t * gauge_create(lv_obj_t *parent, const gauge_cfg_t *cfg_opt)
{
    lv_obj_t *obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
    lv_obj_set_size(obj, 220, 220);

    lv_obj_set_style_pad_all(obj, 0, 0);

    gauge_state_t *st = static_cast<gauge_state_t*>(lv_malloc(sizeof(*st)));
    lv_memset(st, 0, sizeof(*st));
    st->cfg = gauge_default_config();
    if (cfg_opt) st->cfg = *cfg_opt;
    st->cfg.max = (st->cfg.max == st->cfg.min) ? (st->cfg.min + 1.0f) : st->cfg.max;
    st->cfg.redline = clampf(st->cfg.redline, st->cfg.min, st->cfg.max);
    st->value = st->cfg.min;

    lv_obj_set_user_data(obj, st);

    st->scale     = lv_scale_create(obj);
    st->arc_red   = lv_arc_create(st->scale);
    st->arc_val   = lv_arc_create(st->scale);
    st->lbl_value = lv_label_create(st->scale);
    st->lbl_name  = lv_label_create(obj);

    lv_obj_remove_flag(st->arc_red, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(st->arc_val, LV_OBJ_FLAG_CLICKABLE);

    setup_static(obj);
    layout_update(obj);

    char buf[32];
    fmt_value(buf, sizeof(buf), st->value, st->cfg.decimals, st->cfg.unit);
    lv_label_set_text(st->lbl_value, buf);

    lv_obj_add_event_cb(obj, on_size_or_style, LV_EVENT_SIZE_CHANGED, NULL);
    lv_obj_add_event_cb(obj, on_size_or_style, LV_EVENT_STYLE_CHANGED, NULL);
    lv_obj_add_event_cb(obj, on_delete,        LV_EVENT_DELETE, NULL);

    return obj;
}

void gauge_set_value(lv_obj_t *obj, float v)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;

    const float v_clamped = clampf(v, st->cfg.min, st->cfg.max);
    if (v_clamped == st->value) {
    }
    st->value = v_clamped;

    const int16_t a1 = (int16_t)st->cfg.start_deg;
    const int16_t a2 = value_to_angle(st, st->value);
    lv_arc_set_angles(st->arc_val, a1, a2);

    char buf[32];
    fmt_value(buf, sizeof(buf), st->value, st->cfg.decimals, st->cfg.unit);
    lv_label_set_text(st->lbl_value, buf);
}

void gauge_set_range(lv_obj_t *obj, float min, float max)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;
    if (max == min) max = min + 1.0f;

    st->cfg.min = min;
    st->cfg.max = max;
    st->value   = clampf(st->value, min, max);
    st->cfg.redline = clampf(st->cfg.redline, min, max);

    lv_scale_set_range(st->scale, st->cfg.min, st->cfg.max);

    const int16_t red_a1 = value_to_angle(st, st->cfg.redline);
    const int16_t red_a2 = value_to_angle(st, st->cfg.max);
    lv_arc_set_angles(st->arc_red, red_a1, red_a2);

    gauge_set_value(obj, st->value);
}

void gauge_set_unit(lv_obj_t *obj, const char *unit)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;
    st->cfg.unit = unit;
    /* refresh label only */
    char buf[32];
    fmt_value(buf, sizeof(buf), st->value, st->cfg.decimals, st->cfg.unit);
    lv_label_set_text(st->lbl_value, buf);
}

void gauge_set_name(lv_obj_t *obj, const char *name)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;
    st->cfg.name = name;
    lv_label_set_text(st->lbl_name, st->cfg.name ? st->cfg.name : "");
}

void gauge_set_redline(lv_obj_t *obj, float redline)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st) return;
    st->cfg.redline = clampf(redline, st->cfg.min, st->cfg.max);
    const int16_t red_a1 = value_to_angle(st, st->cfg.redline);
    const int16_t red_a2 = value_to_angle(st, st->cfg.max);
    lv_arc_set_angles(st->arc_red, red_a1, red_a2);
}

void gauge_set_config(lv_obj_t *obj, const gauge_cfg_t *cfg)
{
    gauge_state_t *st = static_cast<gauge_state_t*>(lv_obj_get_user_data(obj));
    if (!st || !cfg) return;

    st->cfg = *cfg;
    if (st->cfg.max == st->cfg.min) st->cfg.max = st->cfg.min + 1.0f;
    st->cfg.redline = clampf(st->cfg.redline, st->cfg.min, st->cfg.max);
    st->value = clampf(st->value, st->cfg.min, st->cfg.max);

    setup_static(obj);
    layout_update(obj);
    gauge_set_value(obj, st->value);
}

gauge_cfg_t gauge_default_config(void)
{
    gauge_cfg_t c;
    c.min = 0.f;
    c.max = 8000.f;
    c.decimals = 0;
    c.start_deg = 135;
    c.sweep_deg = 270;
    c.redline = 6500.f;
    c.unit = "rpm";
    c.name = "RPM";
    c.col_arc = lv_palette_main(LV_PALETTE_GREEN);
    c.col_red = lv_palette_main(LV_PALETTE_RED);
    c.col_text_main = lv_color_white();
    c.col_text_name = lv_color_white();
    c.col_scale = lv_color_white();
    c.tick_len_minor = 8;
    c.tick_len_major = 14;
    c.arc_width = 0; /* auto */
    return c;
}