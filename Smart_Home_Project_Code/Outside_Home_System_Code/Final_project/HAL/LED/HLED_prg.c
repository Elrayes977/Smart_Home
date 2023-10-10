/*
 * HLED_prg.c
 *
 *  Created on: May 29, 2023
 *      Author: Elrayes
 */

#include "STD_TYPES.h"
#include "MDIO_int.h"
#include "ERROR_STATES.h"

#include "HLED_priv.h"
#include "HLED_config.h"
#include "HLED_int.h"


/****************/
ErrorState_t HLED_enInit(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
	switch(copy_u8LedId)
	{
	case HLED_RED_ID:
		MDIO_SetPinDirection(HLED_RED_LED_PIN,OUTPUT);
		break;
		case HLED_BLUE_ID:
		MDIO_SetPinDirection(HLED_BLUE_LED_PIN,OUTPUT);
		break;
		case HLED_GRN_ID:
		MDIO_SetPinDirection(HLED_GRN_LED_PIN,OUTPUT);
		break;
default:
	Local_State=OUT_OF_RANGE;
	}
return Local_State;
}
/****************/
ErrorState_t HLED_enSetON(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
	switch(copy_u8LedId)
	{
	case HLED_RED_ID:
#if(HLED_RED_LED_DIR==HLED_LED_FORWARD)
		MDIO_voidSetPinValue(HLED_RED_LED_PIN,HIGH);
#elif(HLED_RED_LED_DIR==HLED_LED_REVERSE)
		MDIO_enSetPinValue(HLED_RED_LED_PIN,LOW);//dimmed cause it's false
#else
	#error  ("wrong led Red Direction")
#endif
		break;
	case HLED_BLUE_ID:
#if(HLED_BLUE_LED_DIR==HLED_LED_FORWARD)
		MDIO_voidSetPinValue(HLED_BLUE_LED_PIN,HIGH);
#elif(HLED_BLUE_LED_DIR==HLED_LED_REVERSE)
		MDIO_enSetPinValue(HLED_BLUE_LED_PIN,LOW);//dimmed cause it's false
#else
	#error  ("wrong led Red Direction")
#endif
		break;


	case HLED_GRN_ID:
#if(HLED_GRN_LED_DIR==HLED_LED_FORWARD)
		MDIO_voidSetPinValue(HLED_GRN_LED_PIN,HIGH);
#elif(HLED_GRN_LED_DIR==HLED_LED_REVERSE)
		MDIO_enSetPinValue(HLED_GRN_LED_PIN,LOW);//dimmed cause it's false
#else
	#error  ("wrong led Red Direction")
#endif

break;
default:
	Local_State=OUT_OF_RANGE;
	}
return Local_State;

}
/****************/
ErrorState_t HLED_enSetOFF(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
		switch(copy_u8LedId)
		{
		case HLED_RED_ID:
	#if(HLED_RED_LED_DIR==HLED_LED_FORWARD)
			MDIO_voidSetPinValue(HLED_RED_LED_PIN,LOW);
	#elif(HLED_RED_LED_DIR==HLED_LED_REVERSE)
			MDIO_enSetPinValue(HLED_RED_LED_PIN,HIGH);//dimmed cause it's false
	#else
		#error  ("wrong led Red Direction")
	#endif
			break;
		case HLED_BLUE_ID:
	#if(HLED_BLUE_LED_DIR==HLED_LED_FORWARD)
			MDIO_voidSetPinValue(HLED_BLUE_LED_PIN,LOW);
	#elif(HLED_BLUE_LED_DIR==HLED_LED_REVERSE)
			MDIO_enSetPinValue(HLED_BLUE_LED_PIN,HIGH);//dimmed cause it's false
	#else
		#error  ("wrong led Red Direction")
	#endif
			break;


		case HLED_GRN_ID:
	#if(HLED_GRN_LED_DIR==HLED_LED_FORWARD)
			MDIO_voidSetPinValue(HLED_GRN_LED_PIN,LOW);
	#elif(HLED_GRN_LED_DIR==HLED_LED_REVERSE)
			MDIO_enSetPinValue(HLED_GRN_LED_PIN,HIGH);//dimmed cause it's false
	#else
		#error  ("wrong led Red Direction")
	#endif

	break;
	default:
		Local_State=OUT_OF_RANGE;
		}
	return Local_State;


}
ErrorState_t HLED_enToggle(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
	switch(copy_u8LedId)
	{
	case HLED_RED_ID:
		MDIO_voidTogglePinValue(HLED_RED_LED_PIN);
		break;
	case HLED_BLUE_ID:
		MDIO_voidTogglePinValue(HLED_BLUE_LED_PIN);
		break;

	case HLED_GRN_ID:
		MDIO_voidTogglePinValue(HLED_GRN_LED_PIN);
		break;
default:
	Local_State=OUT_OF_RANGE;

	}
return Local_State;

}
