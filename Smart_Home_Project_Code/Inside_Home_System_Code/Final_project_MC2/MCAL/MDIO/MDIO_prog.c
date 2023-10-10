/*
 * MDIO_prog.c
 *
 *  Created on: May 28, 2023
 *      Author: Elrayes
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_priv.h"
#include "MDIO_int.h"

void MDIO_SetPinDirection(Pin_t copy_enPin, Direction_t copy_u8enDirection)
{
	u8 Local_u8port= copy_enPin /10; //1-4
	u8 Local_u8pin= copy_enPin % 10; //0-7
	/*****************************/
	switch(Local_u8port)
	{
	case PORTA:
		switch(copy_u8enDirection)
		{
		case INPUT :
			CLR_BIT(DDRA_REG,Local_u8pin);
			break;
		case OUTPUT :
					SET_BIT(DDRA_REG,Local_u8pin);
					break;
		}
		break;
		/*****************************/
	case PORTB:
		switch(copy_u8enDirection)
				{
				case INPUT :
					CLR_BIT(DDRB_REG,Local_u8pin);
					break;
				case OUTPUT :
							SET_BIT(DDRB_REG,Local_u8pin);
							break;
				}
			break;
			/*****************************/
	case PORTC:
		switch(copy_u8enDirection)
				{
				case INPUT :
					CLR_BIT(DDRC_REG,Local_u8pin);
					break;
				case OUTPUT :
					SET_BIT(DDRC_REG,Local_u8pin);
					break;
				}
			break;
			/*****************************/
		case PORTD:

		switch(copy_u8enDirection)
				{
				case INPUT :
					CLR_BIT(DDRD_REG,Local_u8pin);
					break;
				case OUTPUT :
					SET_BIT(DDRD_REG,Local_u8pin);
				break;
				}
			break;
			/*****************************/
		default: break;

	}
}

/////////////////////////////////////////////////////////////
void MDIO_voidSetPinValue(Pin_t copy_enPin,Value_t copy_enValue)
{
u8 Local_u8port= copy_enPin /10; //1-4
u8 Local_u8pin= copy_enPin % 10; //0-7


switch(Local_u8port)
	{
case PORTA:
	switch(copy_enValue)
	{
	case LOW :
		CLR_BIT(PRTA_REG,Local_u8pin);
	break;
	case HIGH :
		SET_BIT(PRTA_REG,Local_u8pin);
	break;
	}
	break;
	//PORTA_REG|=(copy_enValue<<Local_u8pin)
									/*****************************/
case PORTB:

	switch(copy_enValue)
		{
		case LOW :
		CLR_BIT(PRTB_REG,Local_u8pin);
	break;
	case HIGH  :
		SET_BIT(PRTB_REG,Local_u8pin);
	break;
		}
break;
	/*****************************/
case PORTC:
		switch(copy_enValue)
					{
		case HIGH  :
				SET_BIT(PRTC_REG,Local_u8pin);
				break;
		case LOW :
					CLR_BIT(PRTC_REG,Local_u8pin);
		break;

			}
	break;
	/*****************************/
case PORTD:

switch(copy_enValue)
				{
	case LOW :
	CLR_BIT(PRTD_REG,Local_u8pin);
	break;
	case HIGH  :
	SET_BIT(PRTD_REG,Local_u8pin);
break;
				}

			break;
										/*****************************/
	//default: break;




}
}

void MDIO_voidSetPortValue(Port_t copy_enPort, u8 copy_u8Value)
{
			u8 Local_u8port= copy_enPort /10; //1-4
			//u8 Local_u8pin= copy_enPort % 10; //0-7
			switch(Local_u8port)
				{
				case PORTA:
					PRTA_REG=copy_u8Value;
					break;
					/*****************************/
				case PORTB:

					switch(Local_u8port)
					PRTB_REG=copy_u8Value;
									break;
						/*****************************/
				case PORTC:
					switch(Local_u8port)
					PRTC_REG=copy_u8Value;
									break;
						/*****************************/
					case PORTD:

						PRTD_REG=copy_u8Value;
							break;
						/*****************************/
					default: break;
				}
}

void MDIO_voidGetPinValue(Pin_t copy_enPort, Value_t * ptrValue)
{
				u8 Local_u8port= copy_enPort /10; //1-4
				u8 Local_u8pin= copy_enPort % 10; //0-7

				switch(Local_u8port)
					{
					case PORTA:
						* ptrValue = GET_BIT(PINA_REG,Local_u8pin);
						break;
						/*****************************/
					case PORTB:

						switch(Local_u8port)
						* ptrValue = GET_BIT(PINB_REG,Local_u8pin);
										break;
							/*****************************/
					case PORTC:
						switch(Local_u8port)
						* ptrValue = GET_BIT(PINC_REG,Local_u8pin);
										break;
							/*****************************/
						case PORTD:

							* ptrValue = GET_BIT(PIND_REG,Local_u8pin);
								break;
							/*****************************/
						default: break;
}
}

void MDIO_voidTogglePinValue(Pin_t copy_enPin)
{
					u8 Local_u8port= copy_enPin /10; //1-4
					u8 Local_u8pin= copy_enPin % 10; //0-7
switch(Local_u8port)
{
case PORTA:
	TOG_BIT(PRTA_REG,Local_u8pin);
	break;
case PORTB:
	TOG_BIT(PRTB_REG,Local_u8pin);
	break;
case PORTC:
	TOG_BIT(PRTC_REG,Local_u8pin);
	break;
case PORTD:
	TOG_BIT(PRTD_REG,Local_u8pin);
	break;

}
}



void MDIO_voidGetPortValue(Pin_t copy_enPort,u8 * ptrPortValue)
{

	u8 Local_u8port= copy_enPort /10; //1-4
			//	u8 Local_u8pin= copy_enPort % 10; //0-7

				switch(Local_u8port)
					{
					case PORTA:
						* ptrPortValue = PRTA_REG;
						break;
						/*****************************/
					case PORTB:
											* ptrPortValue = PRTB_REG;
											break;
							/*****************************/
					case PORTC:
											* ptrPortValue = PRTC_REG;
											break;
							/*****************************/
					case PORTD:
											* ptrPortValue = PRTD_REG;
											break;
							/*****************************/
						default: break;

}

}

