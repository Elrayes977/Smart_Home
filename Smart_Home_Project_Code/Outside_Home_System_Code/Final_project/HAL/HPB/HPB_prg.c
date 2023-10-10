/*
 * HPB_prg.c
 *
 *  Created on: May 30, 2023
 *      Author: Elrayes
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "MDIO_int.h"
#include  "HPB_priv.h"
#include "HPB_config.h"
#include "HPB_init.h"

 ErrorState_t HPB_enInit(PB_t * ptrPB)
{
	 ErrorState_t Local_enState = SUCCES;

MDIO_SetPinDirection(ptrPB->PushButtonPin , INPUT);

if(ptrPB->PushButtonID>=1&&ptrPB->PushButtonID<=4)
{

#if(KIT_TYPE==SIM_KIT)
MDIO_voidSetPinValue(ptrPB->PushButtonPin, HIGH);

#endif
}//end if
else
{
 Local_enState = SUCCES;

}
//end else

/*	switch(copy_enPBID)
	{
	case HPB_PB1_ID:
		MDIO_SetPinDirection(HPB_PB1_PIN, INPUT);
		break;
	case HPB_PB2_ID:
		MDIO_SetPinDirection(HPB_PB2_PIN, INPUT);
			break;
	case HPB_PB3_ID:
		MDIO_SetPinDirection(HPB_PB3_PIN, INPUT);
			break;
	case HPB_PB4_ID:
		MDIO_SetPinDirection(HPB_PB4_PIN, INPUT);
			break;
	defult:
	Local_enState =OUT_OF_RANGE;
	}//end switch

#if(KIT_TYPE == SIM_KIT)
	switch(copy_enPBID)
		{
		case HPB_PB1_ID:
			MDIO_voidSetPinValue(HPB_PB1_PIN,HIGH);
			break;
		case HPB_PB2_ID:
			MDIO_voidSetPinValue(HPB_PB2_PIN,HIGH);
				break;
		case HPB_PB3_ID:
			MDIO_voidSetPinValue(HPB_PB3_PIN,HIGH);
				break;
		case HPB_PB4_ID:
			MDIO_voidSetPinValue(HPB_PB4_PIN,HIGH);
				break;
		}//end switcj


#endif*/

return Local_enState;
}//end init

 ErrorState_t HPB_enRead(PB_t *ptrPB,PBState_t * ptrState)
{
	ErrorState_t Local_enState = SUCCES;

	u8 Local_u8PinRead = PB_RELEASED;


			MDIO_voidGetPinValue(ptrPB->PushButtonPin,&Local_u8PinRead);
			if(Local_u8PinRead==PB_PRESSED)
			{//for debpuncing
				_delay_ms(50);
				//socend read
				MDIO_voidGetPinValue(ptrPB->PushButtonPin,&Local_u8PinRead);
				if(Local_u8PinRead==PB_PRESSED)
				{
					//for single press
					while(Local_u8PinRead==PB_PRESSED)
					{
						MDIO_voidGetPinValue(ptrPB->PushButtonPin,&Local_u8PinRead);
						//check if the button is still pressed or not

					}//end while
					*ptrState=PB_PRESSED;
				}//end if socend problem
				else
				{

					*ptrState=PB_RELEASED;
				}
			}// end if debouncing
			else
							{

								*ptrState=PB_RELEASED;
							}

		//Local_enState =OUT_OF_RANGE;


return Local_enState;
}
