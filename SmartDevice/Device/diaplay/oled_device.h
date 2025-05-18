#ifndef __OLED_DEVICE_H
#define __OLED_DEVICE_H

#include "display_device.h"

int OLEDDeviceInit (struct DisplayDevice *ptDev);
void OLEDDeviceFlush (struct DisplayDevice *ptDev);
void AddDisplayDeviceOLED(void);


#endif /* __OLED_DEVICE_H */
