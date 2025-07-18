#include "input_system.h"
#include "gpio_key.h"
#include "net_input.h"

static PInputDevice g_ptInputDevices;

void InputDeviceRegister(PInputDevice ptInputDevice)
{
    ptInputDevice->pNext = g_ptInputDevices;
    g_ptInputDevices = ptInputDevice;
}

void AddInputDevices(void)
{
    AddInputDeviceGPIOKey();
		AddInputDeviceNet();
    //此处添加别的设备
}

void InitInputDevices(void)
{
    PInputDevice pDev = g_ptInputDevices;

    while(pDev)
    {
        pDev->DeviceInit();
        pDev = pDev->pNext;
    }

}
