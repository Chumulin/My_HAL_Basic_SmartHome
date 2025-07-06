#ifndef __FAN_DEVICE_H
#define __FAN_DEVICE_H

typedef struct FanDevice
{
    int speed;
    int (*Init)(struct FanDevice *ptDev);
    int (*Control)(struct FanDevice *ptDev, int ispeed);
} FanDevice, *PFanDevice;

PFanDevice GetFanDevice(void);

#endif /* __FAN_DEVICE_H */
