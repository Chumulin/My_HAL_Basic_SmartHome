#ifndef __CAL_TIME_H
#define __CAL_TIME_H



#include "Input_System.h"
#include "stm32f1xx_hal.h"



TIME_T CAL_GetTime(void);
void CAL_Delay(unsigned int DelayMS);



#endif /* __CAL_TIME_H */
