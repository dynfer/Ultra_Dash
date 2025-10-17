#pragma once
#include "ch.h"
#include "hal.h"
#include <array>

enum class BroadcastType : uint8_t
{
    Fome = 0,
    RusEFI,
    EMU,
    MaxxEcu,
};

enum class SensorEnum : uint8_t
{
    RPM = 0,
    Timing,
    InjDuty,
    VSS,
    FlexPct,
    TPS,
    MAP,
    CLT,
    IAT,
    FuelLevel,
    OilPress,
    OilTemp,
    FuelTemp,
    BattVolt,
    KnockCnt,
    FuelPress,
    Afr,
    Lambda,
    Count
};

inline const char *getSensorNameString(SensorEnum sensor)
{
    switch (sensor)
    {
    case SensorEnum::RPM:
        return "RPM";
    case SensorEnum::Timing:
        return "Timing";
    case SensorEnum::InjDuty:
        return "Injection Duty";
    case SensorEnum::VSS:
        return "Vehicle Speed";
    case SensorEnum::FlexPct:
        return "Flex Percentage";
    case SensorEnum::TPS:
        return "Throttle Position";
    case SensorEnum::MAP:
        return "Manifold Pressure";
    case SensorEnum::CLT:
        return "Coolant Temp";
    case SensorEnum::IAT:
        return "Intake Air Temp";
    case SensorEnum::FuelLevel:
        return "Fuel Level";
    case SensorEnum::OilPress:
        return "Oil Pressure";
    case SensorEnum::OilTemp:
        return "Oil Temp";
    case SensorEnum::FuelTemp:
        return "Fuel Temp";
    case SensorEnum::BattVolt:
        return "Battery Voltage";
    case SensorEnum::KnockCnt:
        return "Knock Count";
    case SensorEnum::FuelPress:
        return "Fuel Pressure";
    case SensorEnum::Afr:
        return "AFR";
    case SensorEnum::Lambda:
        return "Lambda";
    default:
        return "Unknown";
    }
}
inline const char *getSensorUnitString(SensorEnum sensor)
{
    switch (sensor)
    {
    case SensorEnum::RPM:
        return "rpm";
    case SensorEnum::Timing:
        return "deg";
    case SensorEnum::InjDuty:
        return "%";
    case SensorEnum::VSS:
        return "km/h";
    case SensorEnum::FlexPct:
        return "%";
    case SensorEnum::TPS:
        return "%";
    case SensorEnum::MAP:
        return "kPa";
    case SensorEnum::CLT:
        return "C";
    case SensorEnum::IAT:
        return "C";
    case SensorEnum::FuelLevel:
        return "%";
    case SensorEnum::OilPress:
        return "kPa";
    case SensorEnum::OilTemp:
        return "C";
    case SensorEnum::FuelTemp:
        return "C";
    case SensorEnum::BattVolt:
        return "V";
    case SensorEnum::KnockCnt:
        return "";
    case SensorEnum::FuelPress:
        return "kPa";
    case SensorEnum::Afr:
        return "";
    case SensorEnum::Lambda:
        return "";
    default:
        return "";
    }
}

class Sensor
{
public:
    Sensor(SensorEnum type)
        : m_type(type),
          m_value(0.0f)
    {
    }
    float getValue() const { return m_value; }
    void setValue(float v) { m_value = v; }
    const char *getName() const { return getSensorNameString(m_type); }
    const char *getUnit() const { return getSensorUnitString(m_type); }
private:
    SensorEnum m_type;
    float m_value;
};

struct sensorContainer
{
    Sensor rpm{SensorEnum::RPM};
    Sensor timing{SensorEnum::Timing};
    Sensor injDuty{SensorEnum::InjDuty};
    Sensor vss{SensorEnum::VSS};
    Sensor flexPct{SensorEnum::FlexPct};
    Sensor tps{SensorEnum::TPS};
    Sensor map{SensorEnum::MAP};
    Sensor clt{SensorEnum::CLT};
    Sensor iat{SensorEnum::IAT};
    Sensor fuelLevel{SensorEnum::FuelLevel};
    Sensor oilPress{SensorEnum::OilPress};
    Sensor oilTemp{SensorEnum::OilTemp};
    Sensor fuelTemp{SensorEnum::FuelTemp};
    Sensor battVolt{SensorEnum::BattVolt};
    Sensor knockCnt{SensorEnum::KnockCnt};
    Sensor fuelPress{SensorEnum::FuelPress};
    Sensor afr{SensorEnum::Afr};
    Sensor lambda{SensorEnum::Lambda};
};

inline Sensor* getSensorPtr(sensorContainer& sc, SensorEnum which) noexcept {
    switch (which) {
        case SensorEnum::RPM:        return &sc.rpm;
        case SensorEnum::Timing:     return &sc.timing;
        case SensorEnum::InjDuty:    return &sc.injDuty;
        case SensorEnum::VSS:        return &sc.vss;
        case SensorEnum::FlexPct:    return &sc.flexPct;
        case SensorEnum::TPS:        return &sc.tps;
        case SensorEnum::MAP:        return &sc.map;
        case SensorEnum::CLT:        return &sc.clt;
        case SensorEnum::IAT:        return &sc.iat;
        case SensorEnum::FuelLevel:  return &sc.fuelLevel;
        case SensorEnum::OilPress:   return &sc.oilPress;
        case SensorEnum::OilTemp:    return &sc.oilTemp;
        case SensorEnum::FuelTemp:   return &sc.fuelTemp;
        case SensorEnum::BattVolt:   return &sc.battVolt;
        case SensorEnum::KnockCnt:   return &sc.knockCnt;
        case SensorEnum::FuelPress:  return &sc.fuelPress;
        case SensorEnum::Afr:        return &sc.afr;
        case SensorEnum::Lambda:     return &sc.lambda;
        default:                     return nullptr;
    }
}

inline Sensor* getSensorPtr(sensorContainer* sc, SensorEnum which) noexcept {
    return sc ? getSensorPtr(*sc, which) : nullptr;
}

void setSensorValue(CANRxFrame frame, sensorContainer *sensors);