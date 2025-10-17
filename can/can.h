#pragma once
#include "ch.h"
#include "hal.h"
#include "canbroadcast.h"

static constexpr CANConfig canConfig500 = {
    .op_mode = OPMODE_CAN,
    .NBTP = 0x06090C01,
    .DBTP = 0x00090C13,
    .TDCR = 0,
    .CCCR = (1 << 7) | (1 << 5), // test (1 << 7)
    .TEST = (1 << 4), // test (1 << 7)
    .RXGFC = 0
};

void initCan(sensorContainer* sensors);