#include "util/usb_config.h"

static THD_WORKING_AREA(waUsbThread, 4096);
static THD_FUNCTION(UsbThread, arg)
{

    (void)arg;
    chRegSetThreadName("USB Thread");
    while (true)
    {
        if (usbGetDriverStateI(serusbcfg.usbp) == USB_ACTIVE)
        {
            read_command();
        }
        chThdSleepMilliseconds(10);
    }
}

void startUsb()
{
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1500); // Wait for host to recognize disconnect
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    chThdCreateStatic(waUsbThread, sizeof(waUsbThread), NORMALPRIO + 2, UsbThread, NULL);
}