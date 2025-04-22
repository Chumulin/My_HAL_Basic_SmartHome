#include "Input_System.h"
#include "Gpio_Key.h"

static PInputDevice g_ptInputDevices;

void InputDeviceRegister(PInputDevice ptInputDevice)
{
    ptInputDevice->pNext = g_ptInputDevices;
    g_ptInputDevices = ptInputDevice;
}

void AddInputDevices(void)
{
    AddInputDeviceGPIOKey();
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
