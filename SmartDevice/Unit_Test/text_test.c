#include <stdio.h>
#include <string.h>
#include "display_system.h"
#include "font_system.h"
#include "show_text.h"




void text_test(void)
{
    char *str = "www.100ask.net";
    PDisplayDevice ptDevice;
	char *display_name = "OLED";
    char *font_name = "ascii";

    AddFontLibs();
    SetDefaultFontLib(font_name);
    InitDefaultFontLib();

	
	AddDisplayDevices();
	ptDevice = GetDisplayDevice(display_name);

	if (!ptDevice)
	{
		printf("Can not get DisplayDevice %s\r\n", display_name);
	}

	/* 1. 初始化设备 */
	ptDevice->Init(ptDevice);

	/* 2. 清除屏幕 */
	memset(ptDevice->FBBase, 0, ptDevice->iSize);

    ShowTextInDisplayDevice(ptDevice ,16, 15, str);

}
