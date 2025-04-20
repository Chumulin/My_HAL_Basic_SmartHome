#include "Input_Buffer.h"

static InputEventBuffer g_tInputBuffer;

int GetInputEvent(PInputEvent ptInputEvent);
int PutInputEvent(PInputEvent ptInputEvent);


int PutInputEvent(PInputEvent ptInputEvent)
{
    int i = (ptInputEvent->pW + 1) % BUFFER_SIZE;


	if(!ptInputEvent)
		return -1;
	
    if(i != ptInputEvent->pR)    // 环形缓冲区没有写满
    {
        ptInputEvent->buffer[ptInputEvent->pW] = *ptInputEvent;
        ptInputEvent->pW = i;
		return 0;
    }
	return -1;
}


int GetInputEvent(PInputEvent ptInputEvent)
{
	if(!ptInputEvent)
		return -1;
    if(ptInputEvent->pR == ptInputEvent->pW)
    {
        return -1;
    }
    else
    {
        *ptInputEvent = ptInputEvent->buffer[ptInputEvent->pR];
        ptInputEvent->pR = (ptInputEvent->pR + 1) % BUFFER_SIZE;
        return 0;
    }
}
