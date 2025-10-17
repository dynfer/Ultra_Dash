#include "can.h"
#include "can_demo.h"

static THD_WORKING_AREA(waCanRxThread, 512);
static THD_FUNCTION(CanRxThread, p)
{
    chRegSetThreadName("can_RX_Thread");
    CANRxFrame canRxMsg;

    while (true)
    {
        msg_t msg = canReceive(&CAND2, CAN_ANY_MAILBOX, &canRxMsg, TIME_MS2I(50));
        if (msg == MSG_OK) {
            setSensorValue(canRxMsg, static_cast<sensorContainer*>(p));
        }

        chThdSleepMilliseconds(10);
    }
}

static THD_WORKING_AREA(waCanTxThread, 128);
static THD_FUNCTION(CanTxThread, p)
{
    (void)p;
    chRegSetThreadName("can_TX_Thread");
    while (true)
    {
        can_broadcast_demo_step(&CAND2);
        chThdSleepMilliseconds(50);
    }
}

void initCan(sensorContainer* sensors)
{
    palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(4));
    palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(4));
    canStart(&CAND2, &canConfig500);
    chThdCreateStatic(waCanRxThread, sizeof(waCanRxThread), NORMALPRIO + 16, CanRxThread, sensors);
    chThdCreateStatic(waCanTxThread, sizeof(waCanTxThread), NORMALPRIO + 8, CanTxThread, NULL);
}