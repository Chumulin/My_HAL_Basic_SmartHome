#include "fan_device.h"
#include "driver_fan.h"





int CAL_FanDeviceControl(struct FanDevice *ptFanDevice, int iSpeed)
{
	return HAL_FanDeviceControl(ptFanDevice, iSpeed);
}
