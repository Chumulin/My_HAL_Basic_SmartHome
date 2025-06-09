#include <stdio.h>
#include <string.h>
#include "net_device.h"

static PNetDevice g_ptNetDevices;

void NetDeviceRegister(PNetDevice ptNetDevice)
{
    ptNetDevice->pNext = g_ptNetDevices;
    g_ptNetDevices = ptNetDevice;
}



PNetDevice __GetNetDevice(char *name)
{
    PNetDevice pTmp = g_ptNetDevices;

    while(pTmp)
    {
        if(strcmp(pTmp->name,  name) == 0)
        return pTmp;
        else
        pTmp = pTmp->pNext;
    }
    return NULL;

}

