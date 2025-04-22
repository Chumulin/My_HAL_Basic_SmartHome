#ifndef __INPUT_SYSTEM_H
#define __INPUT_SYSTEM_H

#define TIME_T int
#define INPUT_BUF_LEN 20

typedef enum
{
	INPUT_EVENT_TYPE_KEY,
	INPUT_EVENT_TYPE_TOUCH,
	INPUT_EVENT_TYPE_NET,
	INPUT_EVENT_TYPE_STDIO
}INPUT_EVENT_TYPE;

typedef struct InputEvent{
	TIME_T time;	/* count++ */
	INPUT_EVENT_TYPE eType;
	int iX;
	int iY;
	int iKey;
	int iPressure;
	char str[INPUT_BUF_LEN];
}InputEvent, *PInputEvent;

typedef struct InputDevice{
	char *name;
	int (*GetInputEvent)(PInputEvent ptInputEvent);
	int (*DeviceInit)(void);
	int (*DeviceExit)(void);
	struct InputDevice *pNext;
}InputDevice, *PInputDevice;

void AddInputDevices(void);
void InitInputDevices(void);
void InputDeviceRegister(PInputDevice ptInputDevice);



#endif /* __INPUT_SYSTEM_H */
