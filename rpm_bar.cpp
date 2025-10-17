#include "rpm_bar.h"
#include <stdbool.h>
#include <string.h>

#ifndef RPM_BAR_MAX_SEGS
#define RPM_BAR_MAX_SEGS 64
#endif

typedef struct
{
    rpm_bar_cfg_t cfg;
    uint32_t value_rpm;
    lv_obj_t *lbl;

    uint16_t bar_count;
    lv_obj_t *bars[RPM_BAR_MAX_SEGS];

    lv_coord_t W, H;
    lv_coord_t baseY;
    int16_t x1[RPM_BAR_MAX_SEGS];
    int16_t x2[RPM_BAR_MAX_SEGS];
    int16_t hh[RPM_BAR_MAX_SEGS];

    uint16_t lit_count_prev;
    uint16_t red_start_prev;
    lv_color_t color_cache[RPM_BAR_MAX_SEGS];

    bool cache_valid;
    bool lbl_is_red;
} rpm_bar_state_t;

static inline uint32_t clamp_u32(uint32_t v, uint32_t lo, uint32_t hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

static inline bool color_equal(lv_color_t a, lv_color_t b)
{
    return memcmp(&a, &b, sizeof(lv_color_t)) == 0;
}

static void rpm_bar_build(lv_obj_t *obj)
{
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;

    uint16_t segs = st->cfg.segments;
    if (segs > RPM_BAR_MAX_SEGS)
        segs = RPM_BAR_MAX_SEGS;
    if (segs == 0)
        return;

    if (st->bar_count < segs)
    {
        for (uint16_t i = st->bar_count; i < segs; ++i)
        {
            lv_obj_t *b = lv_obj_create(obj);
            lv_obj_remove_style_all(b);
            lv_obj_set_style_bg_opa(b, LV_OPA_COVER, 0);
            lv_obj_set_style_radius(b, st->cfg.corner_radius, 0);
            st->bars[i] = b;
        }
    }
    else if (st->bar_count > segs)
    {
        for (uint16_t i = segs; i < st->bar_count; ++i)
        {
            if (st->bars[i])
            {
                lv_obj_del(st->bars[i]);
                st->bars[i] = NULL;
            }
        }
    }
    st->bar_count = segs;

    const lv_coord_t pw = lv_obj_get_width(obj);
    const lv_coord_t ph = lv_obj_get_height(obj);

    const lv_coord_t pad_l = lv_obj_get_style_pad_left(obj, static_cast<lv_part_t>(0));
    const lv_coord_t pad_r = lv_obj_get_style_pad_right(obj, static_cast<lv_part_t>(0));
    const lv_coord_t pad_t = lv_obj_get_style_pad_top(obj, static_cast<lv_part_t>(0));
    const lv_coord_t pad_b = lv_obj_get_style_pad_bottom(obj, static_cast<lv_part_t>(0));

    const lv_coord_t ox = pad_l;
    const lv_coord_t oy = pad_t;
    const lv_coord_t W = LV_MAX(0, pw - pad_l - pad_r);
    const lv_coord_t H = LV_MAX(0, ph - pad_t - pad_b);

    st->W = W;
    st->H = H;
    st->baseY = oy + ((int32_t)H * (int32_t)st->cfg.baseline_permil / 1000);

    const int32_t hL = (int32_t)H * st->cfg.band_height_left_permil / 1000;
    const int32_t hR = (int32_t)H * st->cfg.band_height_right_permil / 1000;

    const int32_t gap = st->cfg.gap_px;
    const int32_t wfree = W - (int32_t)gap * (int32_t)(segs - 1);
    const int32_t wseg = LV_MAX(1, wfree / segs);

    int32_t x = ox;
    for (uint16_t i = 0; i < segs; ++i)
    {
        st->x1[i] = (int16_t)x;
        st->x2[i] = (int16_t)(x + wseg - 1);

        int32_t t_num = (int32_t)(i * 2 + 1);
        int32_t t_den = (int32_t)(segs * 2);
        int32_t hh = (int32_t)hL + (int32_t)((int64_t)(hR - hL) * t_num / t_den);
        if (hh < 1)
            hh = 1;
        st->hh[i] = (int16_t)hh;

        x += wseg + gap;
        if (x > (ox + W))
            break;
    }

    for (uint16_t i = 0; i < segs; ++i)
    {
        lv_obj_t *b = st->bars[i];
        if (!b)
            continue;
        const lv_coord_t bx = st->x1[i];
        const lv_coord_t bw = st->x2[i] - st->x1[i] + 1;
        const lv_coord_t by = st->baseY;
        const lv_coord_t bh = st->hh[i];

        lv_obj_set_pos(b, bx, by);
        lv_obj_set_size(b, bw, bh);
        lv_obj_set_style_radius(b, st->cfg.corner_radius, 0);
    }

    st->cache_valid = false;
}

static void rpm_bar_update_colors(lv_obj_t *obj)
{
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st || st->bar_count == 0)
        return;

    const uint32_t minr = st->cfg.min_rpm;
    const uint32_t maxr = LV_MAX(st->cfg.max_rpm, minr + 1);
    const uint32_t val = clamp_u32(st->value_rpm, minr, maxr);
    const uint16_t segs = st->bar_count;

    const uint16_t lit_count = (uint16_t)(((uint64_t)(val - minr) * segs) / (maxr - minr));
    const uint16_t red_start = (uint16_t)(((uint64_t)(clamp_u32(st->cfg.redline_rpm, minr, maxr) - minr) * segs) / (maxr - minr));

    uint16_t lo = st->lit_count_prev < lit_count ? st->lit_count_prev : lit_count;
    uint16_t hi = st->lit_count_prev < lit_count ? lit_count : st->lit_count_prev;

    for (uint16_t i = lo; i < hi && i < segs; ++i)
    {
        lv_color_t c = (i < lit_count) ? ((i >= red_start) ? st->cfg.col_red : st->cfg.col_active)
                                       : st->cfg.col_inactive;
        if (!color_equal(c, st->color_cache[i]))
        {
            st->color_cache[i] = c;
            lv_obj_set_style_bg_color(st->bars[i], c, 0);
        }
    }

    if (red_start != st->red_start_prev)
    {
        uint16_t r_lo = (red_start < st->red_start_prev) ? red_start : st->red_start_prev;
        uint16_t r_hi = (red_start < st->red_start_prev) ? st->red_start_prev : red_start;
        for (uint16_t i = r_lo; i < r_hi && i < lit_count && i < segs; ++i)
        {
            lv_color_t c = (i >= red_start) ? st->cfg.col_red : st->cfg.col_active;
            if (!color_equal(c, st->color_cache[i]))
            {
                st->color_cache[i] = c;
                lv_obj_set_style_bg_color(st->bars[i], c, 0);
            }
        }
    }

    bool warn = (lit_count > red_start);
    if (st->lbl && warn != st->lbl_is_red)
    {
        st->lbl_is_red = warn;
        lv_obj_set_style_text_color(st->lbl,
                                    warn ? st->cfg.col_red : lv_color_white(),
                                    0);
    }

    st->lit_count_prev = lit_count;
    st->red_start_prev = red_start;

    if (!st->cache_valid)
    {
        for (uint16_t i = 0; i < segs; ++i)
        {
            lv_color_t c = (i < lit_count) ? ((i >= red_start) ? st->cfg.col_red : st->cfg.col_active)
                                           : st->cfg.col_inactive;
            st->color_cache[i] = c;
            lv_obj_set_style_bg_color(st->bars[i], c, 0);
        }
        st->lit_count_prev = lit_count;
        st->red_start_prev = red_start;
        st->cache_valid = true;
        return;
    }
}

/*------------------------------ Events --------------------------------------*/
static void rpm_bar_size_changed(lv_event_t *e)
{
    lv_obj_t *obj = static_cast<lv_obj_t*>(lv_event_get_target(e));
    rpm_bar_build(obj);
    rpm_bar_update_colors(obj);
}

static void rpm_bar_delete(lv_event_t *e)
{
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(static_cast<lv_obj_t*>(lv_event_get_target(e))));
    if (!st)
        return;
    lv_free(st);
}

lv_obj_t *rpm_bar_create(lv_obj_t *parent, const rpm_bar_cfg_t *cfg_opt)
{
    lv_obj_t *obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
    lv_obj_set_size(obj, 300, 90);

    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_malloc(sizeof(*st)));
    lv_memset(st, 0, sizeof(*st));
    st->cfg = rpm_bar_default_config();
    if (cfg_opt)
        st->cfg = *cfg_opt;
    st->value_rpm = st->cfg.min_rpm;

    lv_obj_set_user_data(obj, st);

    rpm_bar_build(obj);

    st->lbl = lv_label_create(obj);
    lv_obj_set_style_text_color(st->lbl, lv_color_white(), 0);
    lv_obj_set_style_text_opa(st->lbl, LV_OPA_COVER, 0);
    lv_obj_set_style_text_align(st->lbl, LV_TEXT_ALIGN_RIGHT, 0);
    lv_obj_align(st->lbl, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_label_set_text_fmt(st->lbl, "%u", static_cast<unsigned int>(st->value_rpm));
    lv_obj_set_style_text_font(st->lbl, &lv_font_montserrat_32, 0);
    st->lbl_is_red = false;

    lv_obj_add_event_cb(obj, rpm_bar_size_changed, LV_EVENT_SIZE_CHANGED, NULL);
    lv_obj_add_event_cb(obj, rpm_bar_delete, LV_EVENT_DELETE, NULL);

    st->lit_count_prev = 0;
    st->red_start_prev = (uint16_t)(((uint64_t)(clamp_u32(st->cfg.redline_rpm, st->cfg.min_rpm, st->cfg.max_rpm) - st->cfg.min_rpm) * st->cfg.segments) / (LV_MAX(st->cfg.max_rpm, st->cfg.min_rpm + 1) - st->cfg.min_rpm));
    for (uint16_t i = 0; i < RPM_BAR_MAX_SEGS; ++i)
        st->color_cache[i] = lv_color_black();

    rpm_bar_update_colors(obj);
    return obj;
}

void rpm_bar_set_value(lv_obj_t *obj, uint32_t rpm)
{
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;
    rpm = clamp_u32(rpm, st->cfg.min_rpm, LV_MAX(st->cfg.max_rpm, st->cfg.min_rpm + 1));
    if (rpm == st->value_rpm)
        return;
    st->value_rpm = rpm;
    if (st->lbl)
    {
        lv_label_set_text_fmt(st->lbl, "%u", static_cast<unsigned int>(st->value_rpm));
    }
    rpm_bar_update_colors(obj);
}

uint32_t rpm_bar_get_value(lv_obj_t *obj)
{
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(obj));
    return st ? st->value_rpm : 0;
}

void rpm_bar_set_config(lv_obj_t *obj, const rpm_bar_cfg_t *cfg)
{
    if (!cfg)
        return;
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(obj));
    if (!st)
        return;

    rpm_bar_cfg_t old = st->cfg;
    st->cfg = *cfg;

    if (st->cfg.segments > RPM_BAR_MAX_SEGS)
        st->cfg.segments = RPM_BAR_MAX_SEGS;

    bool geom_changed = false;
    geom_changed |= (old.segments != st->cfg.segments);
    geom_changed |= (old.gap_px != st->cfg.gap_px);
    geom_changed |= (old.corner_radius != st->cfg.corner_radius);
    geom_changed |= (old.band_height_left_permil != st->cfg.band_height_left_permil);
    geom_changed |= (old.band_height_right_permil != st->cfg.band_height_right_permil);
    geom_changed |= (old.baseline_permil != st->cfg.baseline_permil);

    st->value_rpm = clamp_u32(st->value_rpm, st->cfg.min_rpm, st->cfg.max_rpm);

    if (geom_changed)
        rpm_bar_build(obj);
    rpm_bar_update_colors(obj);
}

rpm_bar_cfg_t rpm_bar_default_config(void)
{
    rpm_bar_cfg_t c;
    c.min_rpm = 0;
    c.max_rpm = 8000;
    c.redline_rpm = 6500;
    c.segments = 30;
    c.gap_px = 3;
    c.corner_radius = 0;

    c.band_height_left_permil = 550;
    c.band_height_right_permil = 900;
    c.baseline_permil = 100; /* ~10% from top */

    c.col_inactive = lv_color_hex(0xB0B4BB);
    c.col_active = lv_color_hex(0xF2B400);
    c.col_red = lv_color_hex(0xD81E1E);

    c.col_bg = lv_color_hex(0x2A2A2A);
    c.bg_opa = 0;
    return c;
}

lv_obj_t *rpm_bar_get_label(lv_obj_t *obj)
{
    rpm_bar_state_t *st = static_cast<rpm_bar_state_t*>(lv_obj_get_user_data(obj));
    return st ? st->lbl : NULL;
}
