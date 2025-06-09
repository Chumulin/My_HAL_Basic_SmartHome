#ifndef __UART_DEVICE_H
#define __UART_DEVICE_H

#include "ring_buffer.h"

#define ATInterfaceDevice  UARTDevice
#define PATInterfaceDevice PUARTDevice

typedef struct UARTDevice {
	char *name;
	int (*Init)(struct UARTDevice *ptDev);
	void (*InvalidRecvBuf)(struct UARTDevice *ptDev);
	int (*Write)(struct UARTDevice *ptDev, char *Data, int iLen);
	int (*ReadByte)(struct UARTDevice *ptDev, char *Data);
}UARTDevice, *PUARTDevice;

ring_buffer *GetUART3RingBuffer(void);

PATInterfaceDevice GetATInterfaceDevice(void);


#endif /* __UART_DEVICE_H */
