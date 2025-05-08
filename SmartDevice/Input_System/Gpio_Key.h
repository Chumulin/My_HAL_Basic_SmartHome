#ifndef __GPIO_KEY_H
#define __GPIO_KEY_H

#include <stdio.h>
#include "input_system.h"
#include "input_buffer.h"
#include "kal_gpio_key.h"

#define K1_CODE 1
#define K2_CODE 2

void AddInputDeviceGPIOKey(void);

#endif /* __GPIO_KEY_H */
