#include "kal_fan_device.h"
#include "cal_fan_device.h"






int KAL_FanDeviceControl(struct FanDevice *ptFanDevice, int iSpeed)
{
	return CAL_FanDeviceControl(ptFanDevice, iSpeed);
}

