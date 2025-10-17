#include "flash/config_struct.h"

static const void *start_addr = reinterpret_cast<const void *>(0x081E0000);
dashConfig config __attribute__((section(".sdram"), aligned(8)));

void config_save(void)
{
    static FlashDataContainer config_flash;
    memcpy(&config_flash.data, &config, sizeof(config));
    crcObjectInit(&CRCD1);
    crcStart(&CRCD1, NULL);
    config_flash.crc = crcCalc(&CRCD1, sizeof(config_flash.data), (uint8_t *)&config_flash.data);
    crcStop(&CRCD1);
    config_flash.version = 1;
    Flash::EraseSector(7);
    Flash::Write((flashaddr_t)start_addr, reinterpret_cast<const char *>(&config_flash), sizeof(config_flash));
}

void load_default(void)
{
    memset(&config, 0, sizeof(config));
    dashConfig tempConf;
    memset(&tempConf, 0, sizeof(dashConfig));
    tempConf.broadcastType = BroadcastType::Fome;
    tempConf.layoutType = LayoutType::Default;
    auto tmp = gauge_default_config();
    memcpy(&tempConf.mainGauge, &tmp, sizeof(tmp));
    tempConf.mainGauge.min = 0;
    tempConf.mainGauge.max = 400;
    tempConf.mainGauge.type = SensorEnum::MAP;
    value_bar_cfg_t slidesCfg[8];
    for(size_t i = 0; i <= 7; i++)
    {
        slidesCfg[i] = value_bar_default_config();
        auto pair = getMinMax(static_cast<SensorEnum>(i));
        slidesCfg[i].min = pair.first;
        slidesCfg[i].max = pair.second;
        slidesCfg[i].type = static_cast<SensorEnum>(i);
    }
    memcpy(tempConf.slideGauges, slidesCfg, sizeof(slidesCfg));
    auto tmp2 = rpm_bar_default_config();
    memcpy(&tempConf.rpmBarCfg, &tmp2, sizeof(tmp2));
    memcpy(&config, &tempConf, sizeof(config));

    config_save();
}

void config_load(void)
{
    FlashDataContainer raw{};
    memcpy(&raw, start_addr, sizeof(raw));

    bool all_ff = true, all_00 = true;
    const uint8_t* p = reinterpret_cast<const uint8_t*>(&raw.data);
    for (size_t i = 0; i < sizeof(raw.data); ++i) {
        all_ff &= (p[i] == 0xFF);
        all_00 &= (p[i] == 0x00);
    }
    bool is_empty = all_ff || all_00;

    crcObjectInit(&CRCD1);
    crcStart(&CRCD1, NULL);
    uint32_t crc = crcCalc(&CRCD1, sizeof(raw.data),
                           reinterpret_cast<const uint8_t*>(&raw.data));
    crcStop(&CRCD1);
    bool crc_ok = (crc == raw.crc);

    if (is_empty || !crc_ok) {
        load_default();
    } else {
        memcpy(&config, &raw.data, sizeof(config));     // trust only when CRC passes
    }
}