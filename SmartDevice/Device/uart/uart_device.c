#include "kal_uart_device.h"
#include "uart_device.h"

static ring_buffer g_UART3RingBuffer;

ring_buffer *GetUART3RingBuffer(void)
{
	return &g_UART3RingBuffer;
}

static int UART3Init(struct UARTDevice *ptDev)
{
	ring_buffer_init(&g_UART3RingBuffer);
	return 0;
}

static void UART3InvalidRecvBuf(struct UARTDevice *ptDev)
{
	g_UART3RingBuffer.pR = g_UART3RingBuffer.pW = 0;
}

static int UART3Write(struct UARTDevice *ptDev, char *Data, int iLen)
{
	return KAL_UART3Write(Data, iLen);
}

static int UART3ReadByte(struct UARTDevice *ptDev, char *Data)
{
	return ring_buffer_read((unsigned char *)Data, &g_UART3RingBuffer);
}

static UARTDevice g_tUART3Device = {
	"uart3",
	UART3Init,
	UART3InvalidRecvBuf,
	UART3Write,
	UART3ReadByte};

PUARTDevice GetATInterfaceDevice(void)
{
	return &g_tUART3Device;
}
