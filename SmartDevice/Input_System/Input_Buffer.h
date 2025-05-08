#ifndef __INPUT_BUFFER_H
#define __INPUT_BUFFER_H

#include "input_system.h"

#define INPUT_BUFFER_SIZE 10        /* 环形缓冲区的大小 */
typedef struct
{
    InputEvent buffer[INPUT_BUFFER_SIZE];  /* 缓冲区空间 */
    volatile unsigned int pW;           /* 写地址 */
    volatile unsigned int pR;           /* 读地址 */
} InputEventBuffer;

int GetInputEvent(PInputEvent ptInputEvent);
int PutInputEvent(PInputEvent ptInputEvent);

#endif /* __INPUT_BUFFER_H */
