#include <string.h>
#include "input_system.h"
#include "kal_time.h"
#include "net_input.h"
#include "input_buffer.h"

typedef void (*NetInputProcessCallback)(char c);
extern void SetNetInputProcessCallback(NetInputProcessCallback func);

static char g_ESP8266DataBuff[INPUT_BUF_LEN];

enum AT_STATUS
{
	INIT_STATUS,
	LEN_STATUS,
	DATA_STATUS
};

static enum AT_STATUS g_status = INIT_STATUS;
static int g_DataBuffIndex = 0;
static int g_DataLen = 0;

static void ESP8266DataProcessCallback(char c)
{
	char *buf = g_ESP8266DataBuff;
	int i = g_DataBuffIndex;

	buf[i] = c;
	int m;
	InputEvent event;
	g_DataBuffIndex++;
	switch (g_status)
	{
	case INIT_STATUS:
	{
		if (buf[0] != '+')
		{
			g_DataBuffIndex = 0;
		}		
		else if (i == 4)
		{
			if (strncmp(buf, "+IPD,", 5) == 0)
			{
				g_status = LEN_STATUS;
			}
			g_DataBuffIndex = 0;
		}
		break;
	}
	case LEN_STATUS:
	{
		if (buf[i] == ':')
		{
			for (m = 0; m < i; m++)
			{
				g_DataLen = g_DataLen * 10 + buf[m] - '0';
			}
			g_status = DATA_STATUS;
			g_DataBuffIndex = 0;
		}
		break;
	}
	case DATA_STATUS:
	{
		if (g_DataBuffIndex == g_DataLen)
		{

			event.time = KAL_GetTime();
			event.eType = INPUT_EVENT_TYPE_NET;
			strncpy(event.str, buf, g_DataLen);
			event.str[g_DataLen] = '\0';
			PutInputEvent(&event);

			g_status = INIT_STATUS;
			g_DataBuffIndex = 0;
			g_DataLen = 0;
		}
		break;
	}
	}
}

static int ESP8266NetInputInit(void)
{
	SetNetInputProcessCallback(ESP8266DataProcessCallback);
	return 0;
}

static InputDevice g_t_NetInput_Device =
	{
		"esp_8266",
		NULL,
		ESP8266NetInputInit,
		NULL,
};

void AddInputDeviceNet(void)
{
	InputDeviceRegister(&g_t_NetInput_Device);
}
