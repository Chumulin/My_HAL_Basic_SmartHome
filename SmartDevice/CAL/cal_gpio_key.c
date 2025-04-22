#include "cal_gpio_key.h"

void CAL_GPIOKeyInit(void)
{
	/* 调用芯片相关的代码，注册GPIO中断 */
	KEY_GPIO_ReInit();

}

