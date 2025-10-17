#include "value_bar.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    value_bar_cfg_t cfg;
    float value;

    lv_obj_t *track, *fill;
    lv_obj_t *lbl_val, *lbl_name, *lbl_min, *lbl_mid, *lbl_max;
    lv_obj_t *tick_min, *tick_mid, *tick_max;

    lv_coord_t fill_w_prev;
    lv_color_t fill_col_prev;
    const char *name_prev;
} value_bar_state_t;

/*------------------------------ helpers -------------------------------------*/
static inline float clampf(float v, float lo, float hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}
static inline float normf(float v, float lo, float hi)
{
    if (hi <= lo)
        return 0.f;
    return (v - lo) / (hi - lo);
}
static lv_color_t mix_warn_color(const value_bar_cfg_t *C, float f)
{
    const uint8_t start = C->warn_start_pct;
    if (f <= (float)start / 100.f)
        return C->col_fill_low;
    float t = (f - (float)start / 100.f) / (1.f - (float)start / 100.f);
    if (t < 0.f)
        t = 0.f;
    if (t > 1.f)
        t = 1.f;
    uint8_t m = (uint8_t)(t * 255.f + 0.5f);
    return lv_color_mix(C->col_fill_high, C->col_fill_low, m);
}
static void fmt_value(char *buf, size_t n, float v, uint8_t decimals, const char *unit)
{
    char fmt[8];
    if (decimals > 3)
        decimals = 3;
    lv_snprintf(fmt, sizeof(fmt), "%%.%uf", (unsigned)decimals);
    int used = lv_snprintf(buf, n, fmt, (double)v);
    if (unit && used > 0 && (size_t)used < n)
    {
        lv_snprintf(buf + used, n - (size_t)used, " %s", unit);
    }
}

static void layout_ticks(value_bar_state_t *st, lv_obj_t *obj)
{
    const lv_coord_t pw    = lv_obj_get_width(obj);
    const lv_coord_t pad_l = lv_obj_get_style_pad_left(obj, static_cast<lv_part_t>(0));
    const lv_coord_t pad_r = lv_obj_get_style_pad_right(obj, static_cast<lv_part_t>(0));
    const lv_coord_t tick_h = st->cfg.tick_h;

    const lv_coord_t w = LV_MAX(0, pw - pad_l - pad_r);
    lv_coord_t y1 = 18 + 2;
    lv_obj_set_pos(st->tick_min, 0,           y1);
    lv_obj_set_pos(st->tick_mid, w/2 - 1,     y1);
    lv_obj_set_pos(st->tick_max, w - 2,       y1);
    lv_obj_set_size(st->tick_min, 2, tick_h);
    lv_obj_set_size(st->tick_mid, 2, tick_h);
    lv_obj_set_size(st->tick_max, 2, tick_h);
}

static void layout_scale_labels(value_bar_state_t *st)
{
    lv_obj_set_style_text_color(st->lbl_min, st->cfg.col_scale, 0);
    lv_obj_set_style_text_color(st->lbl_mid, st->cfg.col_scale, 0);
    lv_obj_set_style_text_color(st->lbl_max, st->cfg.col_scale, 0);

    lv_obj_align(st->lbl_min, LV_ALIGN_TOP_LEFT,  0, 0);
    lv_obj_align(st->lbl_mid, LV_ALIGN_TOP_MID,   0, 0);
    lv_obj_align(st->lbl_max, LV_ALIGN_TOP_RIGHT, 0, 0);
}

static void layout_static(value_bar_state_t *st, lv_obj_t *obj)
{
    layout_scale_labels(st);

    layout_ticks(st, obj);

    const lv_coord_t pw = lv_obj_get_width(obj);
    const lv_coord_t pad_l = lv_obj_get_style_pad_left(obj, static_cast<lv_part_t>(0));
    const lv_coord_t pad_r = lv_obj_get_style_pad_right(obj, static_cast<lv_part_t>(0));

    const lv_coord_t content_w = LV_MAX(0, pw - pad_l - pad_r);

    lv_coord_t track_x = 0;
    lv_coord_t track_w = LV_MAX(4, content_w);
    lv_coord_t track_h = 26;
    lv_coord_t track_y = 18 + st->cfg.tick_h + 2;

    lv_obj_set_pos(st->track, track_x, track_y);
    lv_obj_set_size(st->track, track_w, track_h);
    lv_obj_set_style_radius(st->track, st->cfg.track_radius, 0);
    lv_obj_set_style_bg_color(st->track, st->cfg.col_track, 0);
    lv_obj_set_style_bg_opa(st->track, LV_OPA_COVER, 0);

    if (st->cfg.name != st->name_prev)
    {
        lv_label_set_text(st->lbl_name, st->cfg.name ? st->cfg.name : "");
        st->name_prev = st->cfg.name;
    }
    lv_obj_set_style_text_color(st->lbl_name, st->cfg.col_text_name, 0);
    lv_obj_align_to(st->lbl_name, st->track, LV_ALIGN_OUT_BOTTOM_MID, 0, 6);

    lv_obj_set_style_text_color(st->lbl_val, st->cfg.col_text_main, 0);
    lv_obj_align_to(st->lbl_val, st->track, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_radius(st->fill, st->cfg.track_radius, 0);
    lv_obj_set_style_bg_opa(st->fill, LV_OPA_COVER, 0);
}

static void layout_track_and_fill(value_bar_state_t *st, lv_obj_t *obj)
{
    const lv_coord_t pw    = lv_obj_get_width(obj);
    const lv_coord_t pad_l = lv_obj_get_style_pad_left(obj, static_cast<lv_part_t>(0));
    const lv_coord_t pad_r = lv_obj_get_style_pad_right(obj, static_cast<lv_part_t>(0));

    const lv_coord_t content_w = LV_MAX(0, pw - pad_l - pad_r);

    lv_coord_t track_x = 0;
    lv_coord_t track_w = LV_MAX(4, content_w);
    lv_coord_t track_h = 26;
    lv_coord_t track_y = 18 + st->cfg.tick_h + 2;

    lv_obj_set_pos(st->track, track_x, track_y);
    lv_obj_set_size(st->track, track_w, track_h);
    lv_obj_set_style_radius(st->track, st->cfg.track_radius, 0);
    lv_obj_set_style_bg_color(st->track, st->cfg.col_track, 0);
    lv_obj_set_style_bg_opa(st->track, LV_OPA_COVER, 0);

    float f = normf(clampf(st->value, st->cfg.min, st->cfg.max), st->cfg.min, st->cfg.max);
    lv_coord_t fill_w = (lv_coord_t)(f * (float)track_w + 0.5f);
    lv_obj_set_pos(st->fill, track_x, track_y);
    lv_obj_set_size(st->fill, fill_w, track_h);
    lv_obj_set_style_radius(st->fill, st->cfg.track_radius, 0);
    lv_color_t col = mix_warn_color(&st->cfg, f);
    lv_obj_set_style_bg_color(st->fill, col, 0);
    lv_obj_set_style_bg_opa(st->fill, LV_OPA_COVER, 0);

    char buf[32];
    fmt_value(buf, sizeof(buf), st->value, st->cfg.decimals, st->cfg.unit);
    lv_label_set_text(st->lbl_val, buf);
    lv_obj_set_style_text_color(st->lbl_val, st->cfg.col_text_main, 0);
    lv_obj_align_to(st->lbl_val, st->track, LV_ALIGN_CENTER, 0, 0);

    lv_label_set_text(st->lbl_name, st->cfg.name ? st->cfg.name : "");
    lv_obj_set_style_text_color(st->lbl_name, st->cfg.col_text_name, 0);
    lv_obj_align_to(st->lbl_name, st->track, LV_ALIGN_OUT_BOTTOM_MID, 0, 6);
}

static void update_scale_texts(value_bar_state_t *st)
{
    char bmin[16], bmid[16], bmax[16];
    if (st->cfg.decimals > 3)
        st->cfg.decimals = 3;
    char fmt[8];
    lv_snprintf(fmt, sizeof(fmt), "%%.%uf", (unsigned)st->cfg.decimals);

    const float mid = (st->cfg.min + st->cfg.max) * 0.5f;
    lv_snprintf(bmin, sizeof(bmin), fmt, (double)st->cfg.min);
    lv_snprintf(bmid, sizeof(bmid), fmt, (double)mid);
    lv_snprintf(bmax, sizeof(bmax), fmt, (double)st->cfg.max);

    lv_label_set_text(st->lbl_min, bmin);
    lv_label_set_text(st->lbl_mid, bmid);
    lv_label_set_text(st->lbl_max, bmax);
}

/*------------------------------ events --------------------------------------*/
static void value_bar_size_changed(lv_event_t *e)
{
    lv_obj_t *obj = static_cast<lv_obj_t*>(lv_event_get_target(e));
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;
    update_scale_texts(st);
    layout_static(st, obj);
    value_bar_set_value(obj, st->value);
}

static void value_bar_delete(lv_event_t *e)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(static_cast<lv_obj_t*>(lv_event_get_target(e))));
    if (st)
        lv_free(st);
}

/*------------------------------ public API ----------------------------------*/
lv_obj_t *value_bar_create(lv_obj_t *parent, const value_bar_cfg_t *cfg_opt)
{
    lv_obj_t *obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
    lv_obj_set_size(obj, 200, 100);
    lv_obj_set_style_border_width(obj, 3, 0);
    lv_obj_set_style_border_color(obj, lv_color_white(), 0);

    lv_obj_set_style_pad_top(obj, 18, 0);
    lv_obj_set_style_pad_bottom(obj, 26, 0);
    lv_obj_set_style_pad_left(obj, 8, 0);
    lv_obj_set_style_pad_right(obj, 8, 0);

    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_malloc(sizeof(*st)));
    lv_memset(st, 0, sizeof(*st));
    st->cfg = value_bar_default_config();
    if (cfg_opt)
        st->cfg = *cfg_opt;
    st->value = st->cfg.min;

    lv_obj_set_user_data(obj, st);

    st->lbl_min = lv_label_create(obj);
    st->lbl_mid = lv_label_create(obj);
    st->lbl_max = lv_label_create(obj);

    st->tick_min = lv_obj_create(obj);
    st->tick_mid = lv_obj_create(obj);
    st->tick_max = lv_obj_create(obj);
    {
        lv_obj_t *ticks[3] = {st->tick_min, st->tick_mid, st->tick_max};
        for (int i = 0; i < 3; i++)
        {
            lv_obj_t *t = ticks[i];
            lv_obj_remove_style_all(t);
            lv_obj_set_style_bg_opa(t, LV_OPA_COVER, 0);
            lv_obj_set_style_bg_color(t, st->cfg.col_scale, 0);
        }
    }

    st->track = lv_obj_create(obj);
    st->fill = lv_obj_create(obj);
    lv_obj_remove_style_all(st->track);
    lv_obj_remove_style_all(st->fill);

    st->lbl_val = lv_label_create(obj);
    st->lbl_name = lv_label_create(obj);

    update_scale_texts(st);
    layout_scale_labels(st);
    layout_ticks(st, obj);
    layout_track_and_fill(st, obj);

    lv_obj_add_event_cb(obj, value_bar_size_changed, LV_EVENT_SIZE_CHANGED, NULL);
    lv_obj_add_event_cb(obj, value_bar_delete, LV_EVENT_DELETE, NULL);
    lv_obj_add_event_cb(obj, value_bar_size_changed, LV_EVENT_STYLE_CHANGED, NULL);

    st->fill_w_prev = 0;
    st->fill_col_prev = lv_color_hex(0x000000);
    st->name_prev = NULL;

    return obj;
}

void value_bar_set_value(lv_obj_t *obj, float v)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if(!st) return;

    float v_clamped = clampf(v, st->cfg.min, st->cfg.max);
    st->value = v_clamped;

    lv_coord_t track_w = lv_obj_get_width(st->track);
    if(track_w < 0) track_w = 0;
    float f = normf(st->value, st->cfg.min, st->cfg.max);
    lv_coord_t new_w = (lv_coord_t)(f * (float)track_w + 0.5f);

    lv_color_t new_col = mix_warn_color(&st->cfg, f);
    if(memcmp(&new_col, &st->fill_col_prev, sizeof(lv_color_t)) != 0) {
        st->fill_col_prev = new_col;
        lv_obj_set_style_bg_color(st->fill, new_col, 0);
    }

    if(new_w != st->fill_w_prev) {
        lv_obj_set_width(st->fill, new_w);
        st->fill_w_prev = new_w;
    }

    char buf[32];
    fmt_value(buf, sizeof(buf), st->value, st->cfg.decimals, st->cfg.unit);
    lv_label_set_text(st->lbl_val, buf);
}

void value_bar_set_range(lv_obj_t *obj, float min, float max)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;
    st->cfg.min = min;
    st->cfg.max = max;
    update_scale_texts(st);
    layout_track_and_fill(st, obj);
}

void value_bar_set_unit(lv_obj_t *obj, const char *unit)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;
    st->cfg.unit = unit;
    layout_track_and_fill(st, obj);
}

void value_bar_set_name(lv_obj_t *obj, const char *name)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;
    if (name == st->cfg.name)
        return;
    st->cfg.name = name;
    st->name_prev = NULL;
    layout_static(st, obj);
}

void value_bar_set_warn_pct(lv_obj_t *obj, uint8_t pct)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;
    st->cfg.warn_start_pct = pct;
    layout_track_and_fill(st, obj);
}

void value_bar_set_config(lv_obj_t *obj, const value_bar_cfg_t *cfg)
{
    value_bar_state_t *st = static_cast<value_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st || !cfg)
        return;
    st->cfg = *cfg;
    update_scale_texts(st);
    layout_scale_labels(st);
    layout_ticks(st, obj);
    layout_track_and_fill(st, obj);
}

value_bar_cfg_t value_bar_default_config(void)
{
    value_bar_cfg_t c;
    c.min = 0.f;
    c.max = 10.f;
    c.decimals = 1;
    c.warn_start_pct = 70;
    c.unit = "bar";
    c.name = "OIL PRESS";
    c.col_track = lv_color_hex(0xBFC2C7);
    c.col_fill_low = lv_color_hex(0xF2B400);  // yellow/amber
    c.col_fill_high = lv_color_hex(0xD81E1E); // red
    c.col_text_main = lv_color_black();
    c.col_text_name = lv_color_white();
    c.col_scale = lv_color_white();
    c.track_radius = 6;
    c.tick_h = 8;
    return c;
}
