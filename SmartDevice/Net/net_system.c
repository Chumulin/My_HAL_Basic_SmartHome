#include "net_device.h"
#include "esp8266.h"

void AddNetDevices(void)
{
    AddNetDeviceESP8266();
    //此处添加别的设备
}

PNetDevice GetNetDevice(char *name)
{
    return __GetNetDevice(name);
}
