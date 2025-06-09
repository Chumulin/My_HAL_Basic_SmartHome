#include <stdio.h>
#include <string.h>
#include "net_device.h"
#include "uart_device.h"
#include "kal_time.h"
#include "config.h"

#define ATINTERFACE_TIMEOUT 10

static PATInterfaceDevice g_ptATIntfDev;

static int isReturnOK(char *buff, int len)
{
    buff[len] = '\0';
    return  strstr(buff, "OK\r\n") ? 1 : 0;

}

static int isReturnERROR(char *buff, int len)
{
    buff[len] = '\0';
    return  strstr(buff, "ERROR\r\n") ? 1 : 0;

}

int ATInterfaceInit(void)
{
    g_ptATIntfDev = GetATInterfaceDevice();
    g_ptATIntfDev->Init(g_ptATIntfDev);
    return 0;
}

int ATCommandSend(char *cmd, int iTimeoutMS)
{
    char buf[100];
    int i = 0;
    int pre;
    int now;
    debug_printf("Send ATCommand: %s\r\n", cmd);
	
    g_ptATIntfDev->InvalidRecvBuf(g_ptATIntfDev);
    g_ptATIntfDev->Write(g_ptATIntfDev, cmd, strlen(cmd));
    g_ptATIntfDev->Write(g_ptATIntfDev, "\r\n", 2);

    pre = KAL_GetTime();
    while(iTimeoutMS)
    {
        if( g_ptATIntfDev->ReadByte(g_ptATIntfDev, &buf[i]) == 0)
        {
						debug_printf("%c", buf[i]);
            if((i != 0) && (buf[i-1] == '\r') && (buf[i] == '\n'))
            {
                if(isReturnOK(buf, i+1))
                {
                    debug_printf("OK\r\n");
                    return 0;
                }
                
                else if(isReturnERROR(buf, i+1))
                {
                    debug_printf("ERROR\r\n");
                    return -1;
                }
								else
								{
									i = 0;
								}
            }
            i++;
        }
        now = KAL_GetTime();
        if (now > pre)
        {
            iTimeoutMS--;
            pre = now;
        }
    }
    debug_printf("timeout\r\n");
    return -2;
}

int ATCommandSendAndRecv(char *cmd, char *pcRecvBuf, int iTimeoutMS)
{
	char *buf = pcRecvBuf;
	int i = 0;
	int pre;
	int now;

	g_ptATIntfDev->InvalidRecvBuf(g_ptATIntfDev);
	
	g_ptATIntfDev->Write(g_ptATIntfDev, cmd, strlen(cmd));
	g_ptATIntfDev->Write(g_ptATIntfDev, "\r\n", 2);

	pre = KAL_GetTime();
	while (iTimeoutMS)
	{
		if (g_ptATIntfDev->ReadByte(g_ptATIntfDev, &buf[i]) == 0)
		{
			/* 有没有碰到回车换行"\r\n" */
			if ((i != 0) && (buf[i-1] == '\r') && (buf[i] == '\n'))
			{
				if (isReturnOK(buf, i+1))
				{
					buf[i+1] = '\0';
					return 0;
				}
				else if(isReturnERROR(buf, i+1))
				{
					buf[i+1] = '\0';
					return -1;
				}
			}
			i++;
		}
		
		now = KAL_GetTime();
		if (now > pre)
		{
			iTimeoutMS--;
			pre = now;
		}
		
	}

	return -2;
}

int ATDataRecv(unsigned char *Data, int *piLen ,int iTimeoutMS)
{
    enum AT_STATUS
    {
        INIT_STATUS,
        LEN_STATUS,
        DATA_STATUS
    };
		
    enum AT_STATUS status = INIT_STATUS;
    char buf[100];
    int i = 0;
    int len = 0;
    int pre;
    int now;
		int m;


    pre = KAL_GetTime();
    while(iTimeoutMS)
    {
        if( g_ptATIntfDev->ReadByte(g_ptATIntfDev, &buf[i]) == 0)
        {
            switch (status)
            {
                case INIT_STATUS:
                {
                    buf[i + 1] = '\0';
                    if (strstr(buf, "+IPD," ))
                    {
                        status = LEN_STATUS;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                    break;
                }
                case LEN_STATUS:
                {
                    if (buf[i] == ':')
                    {
                        for(m = 0; m <i; m++)
                        {
                            len = len * 10 + buf[m] - '0';
                        }
                        status = DATA_STATUS;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
										break;
                }
                case DATA_STATUS:
                {
                    Data[i] = buf[i];
                    i++;
                    if(i == len)
                    {
                        if(piLen)
                        {
                            *piLen = len;
                        }
                        return 0;
                    }
                    break;
                }
            }
        }
        now = KAL_GetTime();
        if (now > pre)
        {
           iTimeoutMS--;
           pre = now;
        }
    }
    return -2;
}

