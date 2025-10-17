#pragma once

#include "hal_usb_lld.h"
#include "hal_serial_usb.h"
#include "ch.h"
#include "hal.h"
#include "util/usbcfg.h"   // Contains board-specific USB configuration.
#include "util/api.h"

void startUsb(void);