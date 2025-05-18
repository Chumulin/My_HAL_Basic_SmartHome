
#include <stdio.h>
#include <string.h>

#include "display_device.h"

static PDisplayDevice g_ptDisplayDevices;

void DisplayDeviceRegister(PDisplayDevice ptDisplayDevice)
{
    ptDisplayDevice->pNext = g_ptDisplayDevices;
    g_ptDisplayDevices = ptDisplayDevice;
}


PDisplayDevice __GetDisplayDevice(char *name)
{
    PDisplayDevice pTmp = g_ptDisplayDevices;

    while(pTmp)
    {
        if(strcmp(pTmp->name,  name) == 0)
					return pTmp;
        else
					pTmp = pTmp->pNext;
    }
    return NULL;

}

