#include "util.h"

std::pair<float,float> getMinMax(SensorEnum type)
{
    std::pair pair = {0,0};
    switch (type)
    {
    case SensorEnum::RPM:
        pair.first = 0;
        pair.second = 8000;
        break;
    case SensorEnum::Timing:
        pair.first = 0;
        pair.second = 45;
        break;
    case SensorEnum::InjDuty:
        pair.first = 0;
        pair.second = 100;
        break;
    case SensorEnum::VSS:
        pair.first = 0;
        pair.second = 250;
        break;
    case SensorEnum::FlexPct:
        pair.first = 0;
        pair.second = 100;
        break;
    case SensorEnum::TPS:
        pair.first = 0;
        pair.second = 100;
        break;
    case SensorEnum::MAP:
        pair.first = 0;
        pair.second = 400;
        break;
    case SensorEnum::CLT:
        pair.first = -30;
        pair.second = 150;
        break;
    case SensorEnum::IAT:
        pair.first = -30;
        pair.second = 80;
        break;
    case SensorEnum::FuelLevel:
        pair.first = 0;
        pair.second = 100;
        break;
    case SensorEnum::OilPress:
        pair.first = 0;
        pair.second = 10;
        break;
    case SensorEnum::OilTemp:
        pair.first = -30;
        pair.second = 150;
        break;
        case SensorEnum::FuelTemp:
        pair.first = -30;
        pair.second = 150;
        break;
    case SensorEnum::BattVolt:
        pair.first = 0;
        pair.second = 16;
        break;
    case SensorEnum::KnockCnt:
        pair.first = 0;
        pair.second = 200;
        break;
    case SensorEnum::FuelPress:
        pair.first = 0;
        pair.second = 1000;
        break;
    case SensorEnum::Afr:
        pair.first = 8;
        pair.second = 20;
        break;
    case SensorEnum::Lambda:
        pair.first = 0.5f;
        pair.second = 1.5f;
        break;
    default:
        break;
    }
    return pair;
}