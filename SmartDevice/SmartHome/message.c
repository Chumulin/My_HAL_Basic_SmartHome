#include <stdio.h>
#include <string.h>
#include "input_system.h"
#include "gpio_key.h"

int ConvertInputEventToJson(PInputEvent ptEvent, char *pcJson)
{
	if (ptEvent->eType == INPUT_EVENT_TYPE_NET)
	{
		strcpy(pcJson, ptEvent->str);
		return 0;
	}
	else if (ptEvent->eType == INPUT_EVENT_TYPE_KEY)
	{
		if (ptEvent->iPressure)
		{
			return -1;
		}

		/* KEY1-->lamp1 : {"dev":"lamp1","status":"2"} */
		/* KEY2-->lamp2 : {"dev":"lamp2","status":"2"} */
		if (ptEvent->iKey == K1_CODE)
			strcpy(pcJson, "{\"dev\":\"lamp1\",\"status\":\"2\"}");
		else if (ptEvent->iKey == K2_CODE)
			strcpy(pcJson, "{\"dev\":\"lamp2\",\"status\":\"2\"}");
		else
			return -1;
		return 0;
	}

	return -1;
}
