#ifndef __CAL_FAN_DEVICE_H
#define __CAL_FAN_DEVICE_H



#include "led_device.h"



int CAL_FanDeviceInit(struct FanDevice *ptFanDevice);
int CAL_FanDeviceControl(struct FanDevice *ptFanDevice, int iSpeed);



#endif /* __CAL_FAN_DEVICE_H */
