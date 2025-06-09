#include "cal_uart_device.h"

extern void USART3_SendBytes(char *buf, int len);

int CAL_UART3Write(char *Data, int iLen)
{
	USART3_SendBytes(Data, iLen);
	return 0;
}
