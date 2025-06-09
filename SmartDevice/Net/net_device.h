#ifndef __NET_DEVICE_H
#define __NET_DEVICE_H


typedef struct NetDevice{
	char* name;
	char ip[20];
	char mac[6];
	int (*Init)(struct NetDevice *ptDev);
	int (*Connect)(struct NetDevice *ptDev, char *SSID, char *password);
	int (*GetInfo)(struct NetDevice *ptDev, char *ip);
	int (*CreateTransfer)(struct NetDevice *ptDev, char *Type, int iLocalPort);
	void (*CloseTransfer)(struct NetDevice *ptDev);
	int (*Send)(struct NetDevice *ptDev, char * Type, char *pDestIP, int iDestPort, unsigned char *Data, int iLen);
	int (*Recv)(struct NetDevice *ptDev, unsigned char *Data, int *piLen ,int iTimeoutMS);
	struct NetDevice *pNext;
}NetDevice, *PNetDevice;


void NetDeviceRegister(PNetDevice ptNetDevice);
PNetDevice __GetNetDevice(char *name);



#endif /* __NET_DEVICE_H */
