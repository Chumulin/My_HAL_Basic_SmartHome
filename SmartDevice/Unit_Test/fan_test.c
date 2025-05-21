#include <kal_time.h>
#include <fan_device.h>
#include <stdio.h>



void fan_test(void)
{
	PFanDevice p1 = GetFanDevice();
	

	p1->Init(p1);
	while (1)
	{
		p1->Control(p1, 1);
		

		KAL_Delay(4000);

		p1->Control(p1, -1);
		
		
		KAL_Delay(4000);
		
		p1->Control(p1, 0);
		
		
		KAL_Delay(4000);
	}
}
