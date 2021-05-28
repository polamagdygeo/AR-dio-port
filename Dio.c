
/*
 * GPIO.c
 *
 * Created: 9/2/2016 12:18:28 AM
 *  Author: Pola Magdy
 */ 

#include "Dio.h"
static uint8_t volatile*const Port_Port[PORT_NO]={0x3B,0x38,0x35,0x32};
static uint8_t volatile*const Port_Pin[PORT_NO]={0x39,0x36,0x33,0x30};

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	uint8_t Port_No=ChannelId / Port_Pin_No;
	if (*Port_Pin[Port_No]&(1<<ChannelId-Port_No*Port_Pin_No))
	{
		return STD_HIGH;
	}
	else
	{
		return STD_LOW;
	}
}

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	uint8_t Port_No=ChannelId / Port_Pin_No;
	*Port_Port[Port_No]=Level<<(ChannelId-Port_No*Port_Pin_No)|*Port_Port[Port_No]&(~(1<<ChannelId-Port_No*Port_Pin_No));
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	return *Port_Pin[PortId];
}

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	*Port_Port[PortId]=Level;
}

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	return (*Port_Pin[ChannelGroupIdPtr->port]&ChannelGroupIdPtr->mask)>>ChannelGroupIdPtr->offset;
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
	*Port_Port[ChannelGroupIdPtr->port]=(Level<<(ChannelGroupIdPtr->offset))&(ChannelGroupIdPtr->mask)|*Port_Port[ChannelGroupIdPtr->port]&(~ChannelGroupIdPtr->mask);
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	uint8_t Port_No=ChannelId / Port_Pin_No;
	(*Port_Port[Port_No])^=(1<<ChannelId-Port_No*Port_Pin_No);
	return Dio_ReadChannel(ChannelId);
}

//void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
//{
//
//}




