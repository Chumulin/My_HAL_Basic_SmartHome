#include "input_test.h"

void input_test(void)
{
	InputEvent event;
	
	AddInputDevices();
	InitInputDevices();
	for(;;)
	{
		if(GetInputEvent(&event) == 0)
		{
			printf("get input event:\r\n");
			printf("type:%d\r\n",event.eType);
			printf("time:%d\r\n",event.time);
			printf("key:%d\r\n",event.iKey);
			printf("press:%d\r\n",event.iPressure);
		}
	}
}
