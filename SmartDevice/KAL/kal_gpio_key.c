#include "kal_gpio_key.h"

void KAL_KeyInit(void)
{
	/* 对于裸机：注册中断 */
	CAL_GPIOKeyInit();
	

}
