#ifndef __DISPLAY_DEVICE_H
#define __DISPLAY_DEVICE_H

typedef struct DisplayDevice
{
    char *name;
    void *FBBase;
    int iXres;
    int iYres;
    int iBpp;
    int iSize;
    int (*Init)(struct DisplayDevice *ptDev);
    void (*Flush)(struct DisplayDevice *ptDev);
    int (*SetPixel)(struct DisplayDevice *ptDev, int iX, int iY, unsigned int dwColor);
    struct DisplayDevice *pNext;
}DisplayDevice, *PDisplayDevice;

void DisplayDeviceRegister(PDisplayDevice ptDisplayDevice);

PDisplayDevice __GetDisplayDevice(char *name);


#endif /* __DISPLAY_DEVICE_H */
