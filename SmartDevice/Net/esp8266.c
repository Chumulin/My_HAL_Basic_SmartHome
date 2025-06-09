#include <stdio.h>
#include <string.h>
#include "net_device.h"
#include "at_command\at_command.h"


#define ESP8266_DEFAULT_TIMEOUT 10

static int ESP8266Init(struct NetDevice *ptDev)
{
	ATInterfaceInit();
	ATCommandSend("AT+CWMODE=3", ESP8266_DEFAULT_TIMEOUT);
	
	ATCommandSend("AT+CIPMUX=0", ESP8266_DEFAULT_TIMEOUT);

    return 0;
}

static int ESP8266Connect(struct NetDevice *ptDev, char *SSID, char *password)
{
	char cmd[100];
	sprintf(cmd, "AT+CWJAP=\"%s\",\"%s\"",SSID, password);
	return ATCommandSend(cmd, ESP8266_DEFAULT_TIMEOUT*1000);
}

static void ESP8266CloseTransfer(struct NetDevice *ptDev)
{
	ATCommandSend("AT+CIPCLOSE", ESP8266_DEFAULT_TIMEOUT);
}

static int ESP8266Send(struct NetDevice *ptDev, char * Type, char *pDestIP, int iDestPort, unsigned char *Data, int iLen)
{
	return 0;
}
static int ESP8266Recv(struct NetDevice *ptDev, unsigned char *Data, int *piLen ,int iTimeoutMS)
{
	return ATDataRecv(Data, piLen, iTimeoutMS);
}

static int ESP8266GetInfo(struct NetDevice *ptDev, char *ip_buf)
{
	char buf[200];
	int ret;
	char *ip;
	int i;
	
	/* 发出AT命令:AT+CIFSR */
	/* 从得到的数据里解析出IP
	 * 
	 +CIFSR:APIP,"192.168.4.1"
	 +CIFSR:APMAC,"1a:fe:34:a5:8d:c6"
	 +CIFSR:STAIP,"192.168.3.133"
	 +CIFSR:STAMAC,"18:fe:34:a5:8d:c6"
	 OK

	 */
	ret = ATCommandSendAndRecv("AT+CIFSR", buf, ESP8266_DEFAULT_TIMEOUT*1000);
	if (!ret)
	{
		/* 解析出IP */
		ip = strstr(buf, "+CIFSR:STAIP,\"");
		if (ip)
		{
			ip += strlen("+CIFSR:STAIP,\"");
			for (i = 0; ip[i] != '\"'; i++)
			{
				ptDev->ip[i] = ip[i];
			}
			ptDev->ip[i] = '\0';
			strcpy(ip_buf, ptDev->ip);
			return 0;
		}
	}

	return -1;

}

static int ESP8266CreateTransfer(struct NetDevice *ptDev, char *Type, int iLocalPort)
{
	char cmd[100];
	/* 只支持udp */
	/* AT+CIPSTART="UDP","192.168.101.110",8080,1112,2 */

	sprintf(cmd, "AT+CIPSTART=\"UDP\",\"192.168.1.1\",8080,%d,2", iLocalPort);
	
	return ATCommandSend(cmd, ESP8266_DEFAULT_TIMEOUT);

}

static NetDevice g_tESP8266NetDevice = {
	"esp8266",
	"0.0.0.0",
	{0,0,0,0,0,0},
	ESP8266Init,
	ESP8266Connect,
	ESP8266GetInfo,
	ESP8266CreateTransfer,
	ESP8266CloseTransfer,
	ESP8266Send,
	ESP8266Recv
};

void AddNetDeviceESP8266(void)
{
	NetDeviceRegister(&g_tESP8266NetDevice);
}
