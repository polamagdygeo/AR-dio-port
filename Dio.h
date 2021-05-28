/*
 * GPIO.h
 *
 * Created: 9/1/2016 5:38:11 PM
 *  Author: Pola Magdy
 */ 

#ifndef GPIO
#define GPIO

#include <avr/io.h>
#include <stdint.h>
#include "Dio_Cfg.h"
#include "Port.h"

#define STD_LOW 0x00
#define STD_HIGH 0x01

typedef enum{
	Port_A,
	Port_B,
	Port_C,
	Port_D
}Port_Name;

typedef uint32_t Dio_ChannelType;

typedef uint8_t Dio_PortType;

typedef struct  
{
	uint32_t mask;
	uint8_t offset;
	Dio_PortType port;
}Dio_ChannelGroupType;

typedef uint8_t Dio_LevelType;

typedef uint8_t Dio_PortLevelType;


Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

//void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);




#endif /* SET CLEAR TOGGLE CHECK_H_ */
