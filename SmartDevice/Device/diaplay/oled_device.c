#include "display_device.h"
#include "kal_oled_device.h"

static unsigned char g_OLEDFramebuffer[1024];

static int OLEDDeviceInit (struct DisplayDevice *ptDev)
{
    /* 初始化OLED硬件 */
    return KAL_OLEDDeviceInit(ptDev);

};
static void OLEDDeviceFlush (struct DisplayDevice *ptDev)
{

    /* 把g_tOLEDFramebuffer[]的数据搬到OLED自带显存里面 */
    KAL_OLEDDeviceFlush(ptDev);
};
 static int OLEDDeviceSetPixel (struct DisplayDevice *ptDev, int iX, int iY, unsigned int dwColor)
 {
    unsigned char *buf = ptDev->FBBase;
    int page,bit;
    unsigned char *byte;

    if (iX >= ptDev ->iXres || iY >= ptDev ->iYres)
    {
        return -1;
    }
    page = iY / 8;
    byte = buf + page * 128 + iX;
    bit = iY % 8;

    if (dwColor)
    {
        *byte |= (1<<bit);
    }
    else
    {
        *byte &= ~(1<<bit);
    }
    return 0;
    
    


 }



/* 128*64bits,1024bytes */
static unsigned char g_OLEDFramebuffer[1024];

static DisplayDevice g_tOLEDDevice =
{
    "OLED",
    g_OLEDFramebuffer,
    128,
    64,
    1,
    128*64*1/8,
    OLEDDeviceInit,
    OLEDDeviceFlush,
    OLEDDeviceSetPixel
};






void AddDisplayDeviceOLED(void)
{
    DisplayDeviceRegister(&g_tOLEDDevice);
}
