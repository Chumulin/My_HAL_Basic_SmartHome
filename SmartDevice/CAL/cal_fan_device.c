#include "fan_device.h"
#include "driver_fan.h"


int CAL_FanDeviceInit(struct FanDevice *ptFanDevice)
{
	return 0;
}


int CAL_FanDeviceControl(struct FanDevice *ptFanDevice, int iSpeed)
{
	return HAL_FanDeviceControl(ptFanDevice, iSpeed);
}
