#include "canbroadcast.h"
#include "flash/config_struct.h"

void setSensorValue(CANRxFrame frame, sensorContainer *sensors)
{
    switch (config.broadcastType)
    {
    case BroadcastType::Fome:
    {
        if (frame.std.SID == 0x201)
        {
            getSensorPtr(sensors, SensorEnum::RPM)->setValue(frame.data16[0]);
            getSensorPtr(sensors, SensorEnum::Timing)->setValue(frame.data16[1] * 50.0f);
            getSensorPtr(sensors, SensorEnum::InjDuty)->setValue(frame.data8[4] * 2.0f);
            getSensorPtr(sensors, SensorEnum::VSS)->setValue(frame.data8[5]);
            getSensorPtr(sensors, SensorEnum::FlexPct)->setValue(frame.data8[6]);
            return;
        }
        else if (frame.std.SID == 0x202)
        {
            getSensorPtr(sensors, SensorEnum::TPS)->setValue(frame.data16[1] / 100.0f);
        }
        else if (frame.std.SID == 0x203)
        {
            getSensorPtr(sensors, SensorEnum::MAP)->setValue(frame.data16[0] / 30.0f);
            getSensorPtr(sensors, SensorEnum::CLT)->setValue(frame.data8[2] - 40.0f);
            getSensorPtr(sensors, SensorEnum::IAT)->setValue(frame.data8[3] - 40.0f);
            getSensorPtr(sensors, SensorEnum::FuelLevel)->setValue(frame.data8[7] / 2.0f);
        }
        else if (frame.std.SID == 0x204)
        {
            getSensorPtr(sensors, SensorEnum::OilPress)->setValue(frame.data16[1] / 30.0f);
            getSensorPtr(sensors, SensorEnum::OilTemp)->setValue(frame.data16[2] - 40.0f);
            getSensorPtr(sensors, SensorEnum::FuelTemp)->setValue(frame.data16[3] - 40.0f);
            getSensorPtr(sensors, SensorEnum::BattVolt)->setValue(frame.data16[4] / 10.0f);
        }
        else if (frame.std.SID == 0x205)
        {
            getSensorPtr(sensors, SensorEnum::InjDuty)->setValue(frame.data16[2] / 300.0f);
            getSensorPtr(sensors, SensorEnum::KnockCnt)->setValue(frame.data16[3]);
        }
        else if (frame.std.SID == 0x206)
        {
            getSensorPtr(sensors, SensorEnum::Lambda)->setValue(frame.data16[0] / 10000.0f);
            getSensorPtr(sensors, SensorEnum::Afr)->setValue(getSensorPtr(sensors, SensorEnum::Lambda)->getValue() * 14.7f);
            getSensorPtr(sensors, SensorEnum::FuelPress)->setValue(frame.data16[2] / 30.0f);
        }
        break;
    }
    case BroadcastType::EMU:
    {
        break; // TODO
    }
    case BroadcastType::MaxxEcu:
    {
        break; // TODO
    }
    case BroadcastType::RusEFI:
    {
        if (frame.std.SID == 0x201)
        {
            getSensorPtr(sensors, SensorEnum::RPM)->setValue(frame.data16[0]);
            getSensorPtr(sensors, SensorEnum::Timing)->setValue(frame.data16[1] * 50.0f);
            getSensorPtr(sensors, SensorEnum::InjDuty)->setValue(frame.data8[4] * 2.0f);
            getSensorPtr(sensors, SensorEnum::VSS)->setValue(frame.data8[5]);
            getSensorPtr(sensors, SensorEnum::FlexPct)->setValue(frame.data8[6]);
            return;
        }
        else if (frame.std.SID == 0x202)
        {
            getSensorPtr(sensors, SensorEnum::TPS)->setValue(frame.data16[1] / 100.0f);
        }
        else if (frame.std.SID == 0x203)
        {
            getSensorPtr(sensors, SensorEnum::MAP)->setValue(frame.data16[0] / 30.0f);
            getSensorPtr(sensors, SensorEnum::CLT)->setValue(frame.data8[2] - 40.0f);
            getSensorPtr(sensors, SensorEnum::IAT)->setValue(frame.data8[3] - 40.0f);
            getSensorPtr(sensors, SensorEnum::FuelLevel)->setValue(frame.data8[7] / 2.0f);
        }
        else if (frame.std.SID == 0x204)
        {
            getSensorPtr(sensors, SensorEnum::OilPress)->setValue(frame.data16[1] / 30.0f);
            getSensorPtr(sensors, SensorEnum::OilTemp)->setValue(frame.data16[2] - 40.0f);
            getSensorPtr(sensors, SensorEnum::FuelTemp)->setValue(frame.data16[3] - 40.0f);
            getSensorPtr(sensors, SensorEnum::BattVolt)->setValue(frame.data16[4] / 10.0f);
        }
        else if (frame.std.SID == 0x205)
        {
            getSensorPtr(sensors, SensorEnum::InjDuty)->setValue(frame.data16[2] / 300.0f);
            getSensorPtr(sensors, SensorEnum::KnockCnt)->setValue(frame.data16[3]);
        }
        else if (frame.std.SID == 0x206)
        {
            getSensorPtr(sensors, SensorEnum::Lambda)->setValue(frame.data16[0] / 10000.0f);
            getSensorPtr(sensors, SensorEnum::Afr)->setValue(getSensorPtr(sensors, SensorEnum::Lambda)->getValue() * 14.7f);
            getSensorPtr(sensors, SensorEnum::FuelPress)->setValue(frame.data16[2] / 30.0f);
        }
        break;
    }
    default:
        break;
    }
}