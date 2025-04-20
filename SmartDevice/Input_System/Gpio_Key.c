#include "Input_System.h"
#include "Input_Buffer.h"

static InputDevice g_t_Key_Device={
	"gpio_key",
	NULL,
	int (*DeviceInit)(void);
	int (*DeviceExit)(void);
	struct InputDevice *pNext;
	}

