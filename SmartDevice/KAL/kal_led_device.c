#include "kal_led_device.h"
#include "cal_led_device.h"



int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{	
	return CAL_LEDDeviceInit(ptLEDDevice);
}


int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
	return CAL_LEDDeviceControl(ptLEDDevice, iStatus);
}

