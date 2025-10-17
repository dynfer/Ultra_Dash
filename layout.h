#pragma once
#include "ch.h"
#include "hal.h"
#include "lvgl.h"
#include "rpm_bar.h"
#include "value_bar.h"
#include "canbroadcast.h"

enum class LayoutType : uint8_t
{
    Default = 0,
};

struct DefaultLayoutStruct
{
    lv_obj_t *mainGauge;
    lv_obj_t *slideGauge[8];
    lv_obj_t *rpmBar;
};

DefaultLayoutStruct *createDefaultLayout(lv_obj_t *parent);