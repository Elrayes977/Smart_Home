/*
 * HULTRASONIC_prg.c
 *
 *  Created on: Jun 21, 2023
 *      Author: elray
 */

#include <math.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MDIO_int.h"
#include "MGIE_int.h"
#include "MTIMER1_int.h"
#include "HULTRASONIC_priv.h"
#include "HULTRASONIC_config.h"
#include "HULTRASONIC_int.h"


	void OVF_INC(void)
		{
			//MDIO_voidTogglePinValue(PC6);
			g_T1OVFint++;

		}

		void ICU_HW(void) // fn to check if ICU work and read the signal
		{	//MDIO_voidTogglePinValue(PC5);
			//if(flag!=0){
			if(g_State == STATE1)
			{
				MTIMER1_ICU_enRead(&g_Reading1);
				MTIMER1_ICU_enSetTrigger(MTIMER1_ICU_FALL_EDGE_TRIG);
				g_T1OVFint_Multfact1=g_T1OVFint;
				g_State = STATE2;
			}
			else if(g_State == STATE2)
			{
				// change trigger

				MTIMER1_ICU_enRead(&g_Reading2);
				g_T1OVFint_Multfact2=g_T1OVFint;

				g_State = STATE3;

				MTIMER1_ICU_enSetTrigger(MTIMER1_ICU_RAIS_EDGE_TRIG);
				g_T1OVFint=0;

			//MTIMER1_enStop();

			//MTIMER1_ICU_enDisableInt()		}
			}
		}



ErrorState_t HUltrasonic_enInit(Pin_t copy_enTrigPin)
{





	//	MDIO_SetPinDirection(PC5, OUTPUT);
	//	MDIO_SetPinDirection(PC6, OUTPUT);
		MDIO_SetPinDirection(ECHO_PIN, INPUT);//echo
		MDIO_SetPinDirection(copy_enTrigPin, OUTPUT);//trig
		MTIMER1_enInit();
		MTIMER1_ICU_enInit();
		MTIMER1_ICU_enEnableInt();
		MTIMER1_OVF_enEnableInt();
		MTIMER1_enStart();
		MGIE_enEnable();
		MTIMER1_ICU_enSetCallBack(MTIME1_CAPT_ID,ICU_HW);
		MTIMER1_ICU_enSetCallBack(MTIME1_OVF_ID,OVF_INC);
return SUCCES;
}

ErrorState_t HUltrasonic_enStartReading(Pin_t copy_enTrigPin,u32 * copy_u8Distance)
{

	    _delay_us(20);
	MDIO_voidSetPinValue(copy_enTrigPin, HIGH);
		_delay_us(20);
	MDIO_voidSetPinValue(copy_enTrigPin,LOW);
	   // _delay_us(10);


	while(g_State != STATE3)
		{

		}
		g_State=STATE1;

		u32 TimeTicks;
		//TimeTicks=((u32)g_Reading2+((u32)g_T1OVFint_Multfact2*OVF_VALUE))-((u32)g_Reading1+((u32)g_T1OVFint_Multfact1*OVF_VALUE));
		TimeTicks=(u32)g_Reading2-(u32)g_Reading1;


			f32 tickTime = PRESCALER1024/FCPU; //prescaler/FCPU
	 	    f32	Time = (TimeTicks * tickTime)/1000000.0;//convert to micro
			u32 Distance = ceil( SPEED_OF_SOUND*(Time/2));
		if(Distance<=400&&Distance>=2){
			*copy_u8Distance=Distance;
		}
			g_Reading1=0;
			g_Reading2=0;

return SUCCES;
}


