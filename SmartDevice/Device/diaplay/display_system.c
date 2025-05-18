#include "display_device.h"
#include "oled_device.h"



void AddDisplayDevices(void)
{
    AddDisplayDeviceOLED();
    //此处添加别的设备
}


PDisplayDevice GetDisplayDevice(char *name)
{

    return __GetDisplayDevice(name);
}
