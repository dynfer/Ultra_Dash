#ifndef USB_CONFIG_H
#define USB_CONFIG_H

#include "hal_usb_lld.h"
#include "hal_serial_usb.h"
#include "ch.h"
#include "hal.h"
#include "util/usbcfg.h"   // Contains board-specific USB configuration.

void startUsb(void);

#endif