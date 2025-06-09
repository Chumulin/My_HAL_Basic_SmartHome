#ifndef __AT_COMMAND_H
#define __AT_COMMAND_H

#include "net_device.h"

int ATInterfaceInit(void);
int ATCommandSend(char *cmd, int iTimeoutMS);
int ATCommandSendAndRecv(char *cmd, char *pcRecvBuf, int iTimeoutMS);
int ATDataRecv(unsigned char *Data, int *piLen, int iTimeoutMS);


#endif /* __AT_COMMAND_H */
