/*
 * Port.h
 *
 * Created: 05/01/2018 12:35:38
 *  Author: Pola Magdy
 */ 


#ifndef PORT_H_
#define PORT_H_

#include "Port_Cfg.h"
#include <stdint.h>

typedef enum
{
	STD_OFF,
	STD_ON
}Std_Bool;

typedef enum
{
	DIO_PIN=1,
}Pin_Mode;

typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef uint8_t Port_PinModeType;

typedef struct
{
	Port_PinModeType mode[32];
	Port_PinDirectionType dir[32];
	Std_Bool pullup_activation[32];
	uint32_t pin_level_init_value;
}Port_ConfigType;

typedef unsigned char Port_PinType;

void Port_Init(const Port_ConfigType* ConfigPtr);

void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);

void Port_RefreshPortDirection(void);

//void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);

//void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);



#endif /* PORT_H_ */
