#include "Gpio_Key.h"

static int GPIOKeyInit(void)
{
	KAL_KeyInit();
	return 0;
}

static InputDevice g_t_Key_Device=
{
	"gpio_key",
	NULL,
	GPIOKeyInit,
	NULL,
};

void AddInputDeviceGPIOKey(void)
{
	InputDeviceRegister(&g_t_Key_Device);
}
