#include "display_device.h"
#include "config.h"
#if defined (CONFIG_SUPPORT_HAL)
#include "driver_oled.h"
#include "driver_i2c.h"
#endif

int CAL_OLEDDeviceInit(struct DisplayDevice *ptDev)
{
    #if defined (CONFIG_SUPPORT_HAL)
    I2C_GPIO_ReInit();
    OLED_Init();
    return 0;
    #elif defined (CONFIG_NO_HAL)
    return NO_HAL_OLEDDeviceInit(ptDev);  
	
    #endif
}

void CAL_OLEDDeviceFlush(struct DisplayDevice *ptDev)
{
    #if defined (CONFIG_SUPPORT_HAL)
    OLED_Copy(ptDev->FBBase);
    #elif defined (CONFIG_NO_HAL)
    NO_HAL_OLEDDeviceInit(ptDev);
    
    #endif
}
