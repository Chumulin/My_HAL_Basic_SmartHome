#include "display_device.h"
#include "cal_oled_device.h"
#include "config.h"


int KAL_OLEDDeviceInit(struct DisplayDevice *ptDev)
{
    #if defined (CONFIG_NOOS)
    return CAL_OLEDDeviceInit(ptDev);
    #elif defined (CONFIG_FREERTOS)
    return FREERTOS_OLEDDeviceInit(ptDev);
    #elif defined (CONFIG_RTTHREAD)
     return RTThread_OLEDDeviceInit(ptDev);
    #endif

    
}

void KAL_OLEDDeviceFlush(struct DisplayDevice *ptDev)
{
    
    #if defined (CONFIG_NOOS)
    CAL_OLEDDeviceFlush(ptDev);
    #elif defined (CONFIG_FREERTOS)
    FREERTOS_OLEDDeviceInit(ptDev);
    FREERTOS_OLEDDeviceFlush(ptDev);
    #elif defined (CONFIG_RTTHREAD)
    RTThread__OLEDDeviceFlush(ptDev);
    #endif
}
