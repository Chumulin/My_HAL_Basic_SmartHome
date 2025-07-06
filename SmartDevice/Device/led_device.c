#include <stdio.h>
#include "kal_led_device.h"
#include "led_device.h"



static int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
	return KAL_LEDDeviceInit(ptLEDDevice);
}

static int LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
	return KAL_LEDDeviceControl(ptLEDDevice, iStatus);
}


static LEDDevice g_tLEDDevices[] = {
	{LED_WHITE, 0, LEDDeviceInit, LEDDeviceControl},
	{LED_BLUE, 0,  LEDDeviceInit, LEDDeviceControl},
	{LED_GREEN, 0, LEDDeviceInit, LEDDeviceControl},
};


PLEDDevice GetLEDDevice(int which)
{
	if (which >= LED_WHITE && which <= LED_GREEN)
		return &g_tLEDDevices[which];
	else
		return NULL;
}

