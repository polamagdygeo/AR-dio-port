/*
 * Port.c
 *
 * Created: 05/01/2018 12:36:36
 *  Author: Pola Magdy
 */ 

#include "Port.h"

static uint8_t volatile*const Port_Dir[PORT_NO]={0x3A,0x37,0x34,0x31};
static uint8_t volatile*const Port_Port[PORT_NO]={0x3B,0x38,0x35,0x32};
static uint8_t fInit;

void Port_Init(const Port_ConfigType* ConfigPtr)
{
	uint8_t index,Port_No,level_init_value[PORT_NO];
	
	for (index=0;index<PORT_NO;index++)
	{
		level_init_value[index]=ConfigPtr->pin_level_init_value>>(index*Port_Pin_No);
	}
	
	for (index=0;index<PIN_NO;index++)
	{
		Port_No=index / Port_Pin_No;
		
		*Port_Dir[Port_No]|=(ConfigPtr->dir[index]<<(index-Port_No*Port_Pin_No));
		
		if (ConfigPtr->dir[index]==PORT_PIN_IN)
		{
			*Port_Port[Port_No]|=(ConfigPtr->pullup_activation[index]<<(index-Port_No*Port_Pin_No));
		}
		
		if (ConfigPtr->mode[index]==DIO_PIN)
		{	
			if(ConfigPtr->dir[index]==PORT_PIN_OUT)
			{
				*Port_Port[Port_No]=level_init_value[Port_No];
			}
		}
	}
	fInit=1;
}

void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{
	if (fInit==1)
	{
		uint8_t Port_No=Pin / Port_Pin_No;
		*Port_Dir[Port_No]|=(Direction<<(Pin-Port_No*Port_Pin_No));
	}
}

void Port_RefreshPortDirection(void)
{
	uint8_t index,Port_Direction[PORT_NO];
	
	for (index=0;index<PORT_NO;index++)
	{
		Port_Direction[index]=*Port_Dir[index];
	}
	
	for (index=0;index<PORT_NO;index++)
	{
		*Port_Dir[index]=Port_Direction[index];
	}
}

//void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
//{
//
//}

//void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
//{
	//
//}
