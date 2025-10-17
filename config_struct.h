#ifndef CONFIG_STRUCT_H
#define CONFIG_STRUCT_H

#include "ch.h"
#include "hal.h"
#include "canbroadcast.h"
#include "layout.h"
#include "gauge.h"

typedef struct dashConfig
{
    BroadcastType broadcastType;
    LayoutType layoutType;
    gauge_cfg_t mainGauge;
    value_bar_cfg_t slideGauges[8];
    rpm_bar_cfg_t rpmBarCfg;
} dashConfig;

constexpr size_t TotalSize = 512;

typedef struct FlashDataContainer
{
    dashConfig data;
    uint32_t crc;
    uint16_t version;
    char padding[TotalSize - sizeof(dashConfig) - sizeof(uint32_t) - sizeof(uint16_t)];
} FlashDataContainer;

static_assert(sizeof(FlashDataContainer) == TotalSize, "FlashDataContainer size mismatch");

extern dashConfig config;

void config_load(void);
void config_save(void);
void load_default(void);

#endif // CONFIG_STRUCT_H