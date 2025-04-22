#include "cal_time.h"

TIME_T CAL_GetTime(void)
{
    /* tick中断里面：count++ */
    return HAL_GetTick();
}
