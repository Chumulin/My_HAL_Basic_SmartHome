#include "cal_led_device.h"
#include "driver_led.h"



int CAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{	
	return 0;
}


int CAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
	return HAL_LEDDeviceControl(ptLEDDevice, iStatus);
}
