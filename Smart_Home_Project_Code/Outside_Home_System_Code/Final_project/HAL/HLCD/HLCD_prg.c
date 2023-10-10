/*
 * HLCD_prg.c
 *
 *  Created on: Jun 1, 2023
 *      Author: elrayes
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "HLCD_priv.h"
#include "HLCD_config.h"
#include "HLCD_init.h"


ErrorState_t HLCD_Init(void)
{
//set direction
MDIO_SetPinDirection(HLCD_RS_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_EN_PIN, OUTPUT);

MDIO_SetPinDirection(HLCD_D7_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_D6_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_D5_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_D4_PIN, OUTPUT);

#if (HLCD_MODE==_8BIT_)
MDIO_SetPinDirection(HLCD_D3_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_D2_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_D1_PIN, OUTPUT);
MDIO_SetPinDirection(HLCD_D0_PIN, OUTPUT);

_delay_ms(35);

HLCD_SendCommand(HLCD_FUNCTION_SET_8Bit_2Lines_5X7);
#elif (HLCD_MODE==_4BIT_)
_delay_ms(35);
//send 0010
MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);

MDIO_voidSetPinValue(HLCD_D7_PIN, 0);
MDIO_voidSetPinValue(HLCD_D6_PIN, 0);
MDIO_voidSetPinValue(HLCD_D5_PIN, 1);
MDIO_voidSetPinValue(HLCD_D4_PIN, 0);
MDIO_voidSetPinValue(HLCD_EN_PIN, HIGH);
		_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);
		_delay_ms(30);
		HLCD_SendCommand(HLCD_FUNCTION_SET_4Bit_2Lines_5X7);

#endif
		//perfom Init sequence
		//display on of
		HLCD_SendCommand(HLCD_DISPLAY_ON_CURSOS_ON_BLINK_OFF);
		//DSPLAY CLEAR
		HLCD_SendCommand(HLCD_CLEAR);
		//ENTRY MODE
		HLCD_SendCommand(HLCD_ENTRY_MODE_SET_INC_NO_SHIFT);

		return SUCCES;
}

static void HLCD_voidNLatch(u8 copy_u8Byte)
{


#if(HLCD_MODE== _8BIT_)
	u8 LCdPinArr[]={HLCD_D0_PIN,HLCD_D1_PIN,HLCD_D2_PIN,HLCD_D3_PIN,HLCD_D4_PIN,
						HLCD_D5_PIN,HLCD_D6_PIN,HLCD_D7_PIN};
	//MDIO_voidSetPinValue(HLCD_D0_PIN, GET_BIT(copy_u8Byte,0));
	MDIO_voidGetPinValue(HLCD_EN_PIN,LOW);
	for(u8 i =0;i<=7;i++)
	{
		MDIO_voidSetPinValue(LCdPinArr[i], GET_BIT(copy_u8Byte,i));


	}
	MDIO_voidSetPinValue(HLCD_EN_PIN, HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);
	_delay_ms(30);
#elif (HLCD_MODE== _4BIT_)
	u8 LCdPinArr[]={HLCD_D4_PIN,HLCD_D5_PIN,HLCD_D6_PIN,HLCD_D7_PIN};
	//send upper 4 bits
	MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);
	for(u8 i=0;i<=3;i++)
	{
		MDIO_voidSetPinValue(LCdPinArr[i], GET_BIT(copy_u8Byte,i+4));
	}

	MDIO_voidSetPinValue(HLCD_EN_PIN, HIGH);
		_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);
		_delay_ms(30);
		//send lower 4 bits
		MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);
		for(u8 i=0;i<=3;i++)
		{
			MDIO_voidSetPinValue(LCdPinArr[i], GET_BIT(copy_u8Byte,i));
		}

		MDIO_voidSetPinValue(HLCD_EN_PIN, HIGH);
			_delay_ms(1);
		MDIO_voidSetPinValue(HLCD_EN_PIN, LOW);
			_delay_ms(30);
#else
#error("wrong LCD MODE")
#endif
		//	return SUCCES;
}

ErrorState_t HLCD_SendData(u8 copy_u8Data)
{

//SEND RS=1
	MDIO_voidSetPinValue(HLCD_RS_PIN, HIGH);
	//send data as a byte to NLATCH

	HLCD_voidNLatch(copy_u8Data);

	return SUCCES;
}

ErrorState_t HLCD_SendCommand(u8 copy_u8Command)
{
//SEND RS low
	MDIO_voidSetPinValue(HLCD_RS_PIN, LOW);
	HLCD_voidNLatch(copy_u8Command);
	return SUCCES;
}
ErrorState_t HLCD_SendString(char * str)
{

while (*str !='\0')
{
	HLCD_SendData(*str);

	str++;

}

return SUCCES;

}
ErrorState_t HLCD_ClearDisplay(void)
{
	HLCD_SendCommand(HLCD_CLEAR);

	return SUCCES;
}

ErrorState_t HLCD_sendIntNum(s32 copy_u32Num)
{

char  str[50],temp;
s32 i=0,j=0,negativeFlag=0;

if(copy_u32Num<0){
	negativeFlag=1;
	copy_u32Num*=-1;
}//end if

do{
str[i++]=(copy_u32Num%10 )+ '0';
copy_u32Num/=10;
}while(copy_u32Num>0);

if(negativeFlag==1)
{
str[i++]='-';
}

str[i]='\0';//null
for(j=0;j<i/2;j++)
{
	temp=str[j];
	str[j]=str[i-j-1];
	str[i-j-1]=temp;
}
HLCD_SendString(str);

return SUCCES;
}

ErrorState_t HLCD_gotoXY(u8 copy_u8Row,u8 copy_u8Column)
{
switch(copy_u8Row)
{
case ROW_1:HLCD_SendCommand(HLCD_SET_ROW1+(copy_u8Column-1));
break;
case ROW_2:HLCD_SendCommand(HLCD_SET_ROW2+(copy_u8Column-1));
break;
default:
	HLCD_SendCommand(HLCD_SET_ROW1);
}

	return SUCCES;
}

ErrorState_t HLCD_SendCustomChar(u8 copy_u8CharCode,u8 * ptrPatterCode)
{
	u8 i=0;
	if(copy_u8CharCode<8&&copy_u8CharCode>=0)
	{
		HLCD_SendCommand(HLCD_GCRAM_SET+(copy_u8CharCode* GCRAM_ROW_INC));
		for(i=0;i<8;i++)
		{
			HLCD_SendData(ptrPatterCode[i]);
		}

	}

	return SUCCES;
}
ErrorState_t HLCD_DisplayCustomeChar(u8 copy_u8CharCode)
{
	HLCD_SendData(copy_u8CharCode);
	return SUCCES;
}

