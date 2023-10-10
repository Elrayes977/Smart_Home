/*

 * HSSD_prg.c
 *
 *  Created on: May 30, 2023
 *      Author: Elrayes
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "MDIO_int.h"
#include "HSSD_priv.h"
#include "HSSD_config.h"
#include "HSSD_int.h"


ErrorState_t HSSD_enInit(void)
{
	//Initialize all pins as output.
	MDIO_SetPinDirection(HSSD_LED_A_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_B_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_C_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_D_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_E_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_F_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_G_PIN, OUTPUT);
	MDIO_SetPinDirection(HSSD_LED_DP_PIN, OUTPUT);
	//TO MAKE THE PORT CONFIGRABLE AS MUCH AS POSSIBLE
		MDIO_SetPinDirection(HSSD_EN1_PIN, OUTPUT);
		MDIO_SetPinDirection(HSSD_EN2_PIN, OUTPUT);
		return SUCCES;
}


ErrorState_t HSSD_enDisplayNumber(u8 copy_u8NUMBER)//00-99
{
	ErrorState_t Local_enState =SUCCES;
	if(copy_u8NUMBER>99)
	{
		Local_enState =OUT_OF_RANGE;
	}//end if
	else
	{


u8 Local_u8Units =copy_u8NUMBER %10;
u8 Local_u8Tens =copy_u8NUMBER /10;
MDIO_voidSetPinValue(HSSD_LED_DP_PIN,LOW);
u16 i;
for(i=0;i<HSSD_DISPLAY_TIME;i++)
{

switch(Local_u8Units)
{
case 0:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,LOW);
	break;
case 1:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,LOW);
	break;
case 2:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_C_PIN,LOW);
		MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
		MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 3:
			MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
			MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
			MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 4:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 5:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 6:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 7:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,LOW);
	break;
case 8:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 9:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
default:break;
}//end switch
//Enable Dig1
MDIO_voidSetPinValue (HSSD_EN1_PIN , HIGH);
//Disable Gig2
MDIO_voidSetPinValue (HSSD_EN2_PIN ,LOW);
//delay fo the digit to be on
_delay_ms(1);
//disable Dig1
MDIO_voidSetPinValue (HSSD_EN1_PIN , LOW);
switch(Local_u8Tens)
{
case 0:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,LOW);
	break;
case 1:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,LOW);
	break;
case 2:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_C_PIN,LOW);
		MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
		MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
		MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 3:
			MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
			MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
			MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
			MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 4:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 5:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 6:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 7:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,LOW);
	break;
case 8:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
case 9:
	MDIO_voidSetPinValue(HSSD_LED_A_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_B_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_C_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_D_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_E_PIN,LOW);
	MDIO_voidSetPinValue(HSSD_LED_F_PIN,HIGH);
	MDIO_voidSetPinValue(HSSD_LED_G_PIN,HIGH);
	break;
}//end switch
//Enable Dig2
MDIO_voidSetPinValue (HSSD_EN2_PIN ,HIGH);
//Disable Gig1
MDIO_voidSetPinValue (HSSD_EN1_PIN ,LOW);
//delay fo the digit to be on
_delay_ms(1);
//disable Dig2
MDIO_voidSetPinValue (HSSD_EN2_PIN , LOW);
}//end for loop

/*the foor loop is Important to see the out for the display time ,
	the function must do all proprties ,hence IF i called it before
 * the while(1) or the while 1 has many function ,it wont work well
*/
	}//end else
	return Local_enState;
}
