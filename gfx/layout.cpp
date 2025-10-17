#include "layout.h"
#include "flash/config_struct.h"

static DefaultLayoutStruct defaultLayoutTable;

static void createMainGauge(lv_obj_t *parent)
{
    config.mainGauge.unit = getSensorUnitString(config.mainGauge.type);
    config.mainGauge.name = getSensorNameString(config.mainGauge.type);
    defaultLayoutTable.mainGauge = gauge_create(parent, &config.mainGauge);
    lv_obj_set_size(defaultLayoutTable.mainGauge, 500, 490);
    lv_obj_set_pos(defaultLayoutTable.mainGauge, 261, 110);
}

static void createSlideGauges(lv_obj_t *parent)
{
    value_bar_cfg_t gaugeCfgs[8] = {0};
    for(size_t i = 0; i < 8; ++i)
    {
        gaugeCfgs[i] = config.slideGauges[i];
        gaugeCfgs[i].name = getSensorNameString(config.slideGauges[i].type);
        gaugeCfgs[i].unit = getSensorUnitString(config.slideGauges[i].type);
    }

    for(size_t j = 0; j < 8; ++j)
    {
        defaultLayoutTable.slideGauge[j] = value_bar_create(parent, &gaugeCfgs[j]);
    }

    lv_obj_set_size(defaultLayoutTable.slideGauge[0], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[0], 0, 111);

    lv_obj_set_size(defaultLayoutTable.slideGauge[1], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[1], 0, 232);

    lv_obj_set_size(defaultLayoutTable.slideGauge[2], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[2], 0, 353);

    lv_obj_set_size(defaultLayoutTable.slideGauge[3], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[3], 0, 474);

    lv_obj_set_size(defaultLayoutTable.slideGauge[4], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[4], 761, 111);

    lv_obj_set_size(defaultLayoutTable.slideGauge[5], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[5], 761, 232);

    lv_obj_set_size(defaultLayoutTable.slideGauge[6], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[6], 761, 353);

    lv_obj_set_size(defaultLayoutTable.slideGauge[7], 260, 120);
    lv_obj_set_pos(defaultLayoutTable.slideGauge[7], 761, 474);
}

static void createRpmBar(lv_obj_t *parent)
{
    defaultLayoutTable.rpmBar = rpm_bar_create(parent, &config.rpmBarCfg);
    lv_obj_set_pos(defaultLayoutTable.rpmBar, 0, 0);
    lv_obj_set_size(defaultLayoutTable.rpmBar, 1024, 110);
}

DefaultLayoutStruct *createDefaultLayout(lv_obj_t *parent)
{
    createMainGauge(parent);
    createSlideGauges(parent);
    createRpmBar(parent);
    return &defaultLayoutTable;
}