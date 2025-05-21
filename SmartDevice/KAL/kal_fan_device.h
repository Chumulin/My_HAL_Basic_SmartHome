#ifndef __KAL_FAN_DEVICE_H
#define __KAL_FAN_DEVICE_H



#include "fan_device.h"



int KAL_FanDeviceInit(struct FanDevice *ptFanDevice);
int KAL_FanDeviceControl(struct FanDevice *ptFanDevice, int iSpeed);



#endif /* __KAL_FAN_DEVICE_H */
