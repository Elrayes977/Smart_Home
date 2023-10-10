/*
 * HKEY_PAD_prg.c
 *
 *  Created on: May 31, 2023
 *      Author: elray
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "ERROR_STATES.h"

#include "HKEY_PAD_priv.h"
#include "HKEY_PAD_config.h"
#include "HKEY_PAD_init.h"
#include <avr/delay.h>


ErrorState_t HKEYPAD_enInt(void)
{
// config rows to be output
MDIO_SetPinDirection(HKEYPAD_R0_PIN, OUTPUT);

MDIO_SetPinDirection(HKEYPAD_R1_PIN, OUTPUT);
MDIO_SetPinDirection(HKEYPAD_R2_PIN, OUTPUT);
MDIO_SetPinDirection(HKEYPAD_R3_PIN, OUTPUT);


	//config columns to be input
MDIO_SetPinDirection(HKEYPAD_C0_PIN, INPUT);
MDIO_SetPinDirection(HKEYPAD_C1_PIN, INPUT);
MDIO_SetPinDirection(HKEYPAD_C2_PIN, INPUT);
MDIO_SetPinDirection(HKEYPAD_C3_PIN, INPUT);
//initial output rows(HIGH)  cause rows are the ground
MDIO_voidSetPinValue(HKEYPAD_R0_PIN, HIGH);
MDIO_voidSetPinValue(HKEYPAD_R1_PIN, HIGH);
MDIO_voidSetPinValue(HKEYPAD_R2_PIN, HIGH);
MDIO_voidSetPinValue(HKEYPAD_R3_PIN, HIGH);

#if(KIT_TYPE==SIM_KIT)
MDIO_voidSetPinValue(HKEYPAD_C0_PIN, HIGH);
MDIO_voidSetPinValue(HKEYPAD_C1_PIN, HIGH);
MDIO_voidSetPinValue(HKEYPAD_C2_PIN, HIGH);
MDIO_voidSetPinValue(HKEYPAD_C3_PIN, HIGH);
#endif
return SUCCES;
}


ErrorState_t HKEYPAD_enGetPressedKey(u8 * ptrKey)
{
	typedef enum{
		BKEY_STATE_IDLE,
		BKEY_STATE_PRESS,
		BKEY_STATE_REALESE

	}Bkeypad_Stat_t;

	u8 Local_u8PressedKey=HKEYPAD_NO_PRESSED_KEY;
u8 Local_u8PinRead;
u8	row_index;
u8	col_index;
u8 Local_u8ArrKeys[4][4]=HKEYPAD_KEYS;
u8 flag=0;
//cause the ports were in  sequence we can start and end the for by r0 till r3
//to make it generic

u8 rowArr[]={HKEYPAD_R0_PIN,HKEYPAD_R1_PIN,HKEYPAD_R2_PIN,HKEYPAD_R3_PIN};
u8 colArr[]={HKEYPAD_C0_PIN,HKEYPAD_C1_PIN,HKEYPAD_C2_PIN,HKEYPAD_C3_PIN};
for(row_index=0 ;row_index<=3&&flag==0 ;row_index++)
{	//output 0(ground) on row
	MDIO_voidSetPinValue(rowArr[row_index],LOW);
	for(col_index=0;col_index<=3 ;col_index++)
	{//read the colimn
		MDIO_voidGetPinValue(colArr[col_index],&Local_u8PinRead);

		if(Local_u8PinRead== HKEYPAD_KEY_PRESSED )
		{//for debpuncing
			_delay_ms(50);
			//socend read
			MDIO_voidGetPinValue(colArr[col_index],&Local_u8PinRead);
			if(Local_u8PinRead== HKEYPAD_KEY_PRESSED )
			{
				/*Bkeypad_Stat_t state=BKEY_STATE_PRESS;
				u16 counter=0;
			while(flag==0){
				MDIO_voidGetPinValue(colArr[col_index],&Local_u8PinRead);
				//for single press
				switch(state)
				{
				case BKEY_STATE_IDLE:

					if(Local_u8PinRead==HKEYPAD_KEY_PRESSED)
					{
						state=BKEY_STATE_PRESS;
						counter=0;

					}
					break;
				case BKEY_STATE_PRESS:
					if(Local_u8PinRead==HKEYPAD_KEY_PRESSED)
					{
						state=BKEY_STATE_REALESE;
						counter=0;

					}
					else if(counter<50)
					{
						counter++;
					}
					else
					{
					Local_u8PressedKey = Local_u8ArrKeys[row_index][col_index];
						state=BKEY_STATE_IDLE;
						flag++;
					}

					break;
				case BKEY_STATE_REALESE:
					if(Local_u8PinRead==HKEYPAD_KEY_PRESSED)
					{
							state=BKEY_STATE_PRESS;
							counter=0;

					}
					else if(counter <50)
					{
						counter++;
					}
					else
					{
						state=BKEY_STATE_IDLE;

					}
					break;


				}//end switch case
			}//end while*/
				while(Local_u8PinRead== HKEYPAD_KEY_PRESSED )
				{
					MDIO_voidGetPinValue(colArr[col_index],&Local_u8PinRead);
					//check if the button is still pressed or not

				}//end while
				Local_u8PressedKey=Local_u8ArrKeys[row_index][col_index];
				flag++;//flag for not intering the socend loop an return with the last update,
				//return SUCCES;
			}//end if socend problem
			else
			{

				//*ptrKey=HKEYPAD_NO_PRESSED_KEY;
			}
		}// end if debouncing
		else
						{

			//*ptrKey=HKEYPAD_NO_PRESSED_KEY;
						}//end else

//break;

	}//inner for

	MDIO_voidSetPinValue(rowArr[row_index], HIGH);

}//outer for
*ptrKey=Local_u8PressedKey;
return SUCCES;
}

