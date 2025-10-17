#include "can_demo.h"


static inline uint16_t uround16(float x) {
    if (x < 0.0f) x = 0.0f;
    if (x > 65535.0f) x = 65535.0f;
    return (uint16_t)(x + 0.5f);
}
static inline uint8_t uround8(float x) {
    if (x < 0.0f) x = 0.0f;
    if (x > 255.0f) x = 255.0f;
    return (uint8_t)(x + 0.5f);
}
static inline void tx_common(CANTxFrame *tx) {
    tx->DLC = 8;
    tx->data32[0] = 0;
    tx->data32[1] = 0;
}

void can_broadcast_demo_step(CANDriver *canp) {
    static uint32_t t = 0;
    t++;

    float rpm       = (float)((t % 81) * 100);                  // 0..8000
    float timing    = 10.0f + 5.0f * ((t / 5) % 10);            // 10..55 deg
    float injDuty   = (float)((t % 81));                        // 0..80 %
    float vss       = (float)((t / 2) % 121);                   // 0..120 km/h
    float flexPct   = (float)((t / 8) % 101);                   // 0..100 %
    float tps       = (float)((t % 101));                       // 0..100 %
    float map_kpa   = 30.0f + (float)((t % 171));               // 30..200 kPa
    float clt_c     = 85.0f;                                    // steady 85°C
    float iat_c     = 25.0f + (float)((t % 11) - 5);            // 20..30°C
    float fuelLevel = (float)((t % 101));                       // 0..100 %
    float oilPress  = 300.0f + (float)((t % 121));              // 300..420 kPa
    float oilTemp   = 95.0f;                                    // steady 95°C
    float fuelTemp  = 30.0f + (float)((t % 11) - 5);            // 25..35°C
    float battVolt  = 13.8f;                                    // steady 13.8 V
    float knockCnt  = (float)((t / 16) % 1000);                 // 0..999
    float lambda    = 0.95f + 0.10f * ((t % 40) / 39.0f);       // 0.95..1.05
    float fuelPress = 300.0f + (float)((t % 61));               // 300..360 kPa

    CANTxFrame tx;

    // 0x201
    tx_common(&tx);
    tx.std.SID        = 0x201;
    tx.data16[0]  = uround16(rpm);                 // RPM (raw)
    tx.data16[1]  = uround16(timing / 50.0f);      // timing => raw*50 => raw=tim/50
    tx.data8[4]   = uround8(injDuty / 2.0f);       // inj duty => raw*2
    tx.data8[5]   = uround8(vss);                  // vss (km/h)
    tx.data8[6]   = uround8(flexPct);              // flex %
    (void)canTransmitTimeout(canp, CAN_ANY_MAILBOX, &tx, TIME_MS2I(2));

    // 0x202
    tx_common(&tx);
    tx.std.SID        = 0x202;
    tx.data16[1]  = uround16(tps * 100.0f);        // tps => raw/100
    (void)canTransmitTimeout(canp, CAN_ANY_MAILBOX, &tx, TIME_MS2I(2));

    // 0x203
    tx_common(&tx);
    tx.std.SID        = 0x203;
    tx.data16[0]  = uround16(map_kpa * 30.0f);     // map => raw/30
    tx.data8[2]   = uround8(clt_c + 40.0f);        // clt => raw-40
    tx.data8[3]   = uround8(iat_c + 40.0f);        // iat => raw-40
    tx.data8[7]   = uround8(fuelLevel * 2.0f);     // fuel level => raw/2
    (void)canTransmitTimeout(canp, CAN_ANY_MAILBOX, &tx, TIME_MS2I(2));

    // 0x204
    tx_common(&tx);
    tx.std.SID        = 0x204;
    tx.data16[1]  = uround16(oilPress * 30.0f);    // oil press => raw/30
    tx.data16[2]  = uround16(oilTemp + 40.0f);     // oil temp  => raw-40
    tx.data16[3]  = uround16(fuelTemp + 40.0f);    // fuel temp => raw-40
    tx.data16[4]  = uround16(battVolt * 10.0f);    // batt V    => raw/10
    (void)canTransmitTimeout(canp, CAN_ANY_MAILBOX, &tx, TIME_MS2I(2));

    // 0x205
    tx_common(&tx);
    tx.std.SID        = 0x205;
    tx.data16[2]  = uround16(injDuty * 300.0f);    // inj duty => raw/300
    tx.data16[3]  = uround16(knockCnt);            // knock count (raw)
    (void)canTransmitTimeout(canp, CAN_ANY_MAILBOX, &tx, TIME_MS2I(2));

    // 0x206
    tx_common(&tx);
    tx.std.SID        = 0x206;
    tx.data16[0]  = uround16(lambda * 10000.0f);   // lambda => raw/10000
    tx.data16[2]  = uround16(fuelPress * 30.0f);   // fuel press => raw/30
    (void)canTransmitTimeout(canp, CAN_ANY_MAILBOX, &tx, TIME_MS2I(2));
}
