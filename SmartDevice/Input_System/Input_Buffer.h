#ifndef __INPUT_BUFFER_H
#define __INPUT_BUFFER_H

#include "input_system.h"

#ifndef NULL
#define NULL (void*)0
#endif

#include "Input_System.h"

#define BUFFER_SIZE 20        /* 环形缓冲区的大小 */
typedef struct
{
    InputEvent buffer[BUFFER_SIZE];  /* 缓冲区空间 */
    volatile unsigned int pW;           /* 写地址 */
    volatile unsigned int pR;           /* 读地址 */
} InputEventBuffer;

int GetInputEvent(PInputEvent ptInputEvent);
int PutInputEvent(PInputEvent ptInputEvent);

#endif /* __INPUT_BUFFER_H */
