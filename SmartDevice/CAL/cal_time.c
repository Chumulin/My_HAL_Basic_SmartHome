#include "cal_time.h"



TIME_T CAL_GetTime(void)
{
    /* tick中断里面：count++ */
    return HAL_GetTick();
}


void CAL_Delay(unsigned int DelayMS)
{
	/* HAL函数里是1ms发生一次中断 */
	HAL_Delay(DelayMS);
}
