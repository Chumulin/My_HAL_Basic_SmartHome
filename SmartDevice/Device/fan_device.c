#include <stdio.h>
#include "kal_fan_device.h"
#include "fan_device.h"

static int FanDeviceInit(struct FanDevice *ptFanDevice)
{
    return 0;
}

static int FanDeviceControl(struct FanDevice *ptFanDevice, int iSpeed)
{
    return KAL_FanDeviceControl(ptFanDevice, iSpeed);
}

static FanDevice g_tFanDevice =
    {
        0,
        FanDeviceInit,
        FanDeviceControl,
};

PFanDevice GetFanDevice(void)
{
    return &g_tFanDevice;
}
