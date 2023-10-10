/*
 * HDC_MOTOR_prg.c
 *
 *  Created on: Jun 19, 2023
 *      Author: elray
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MDIO_int.h"
#include "MTIMER0_int.h"
#include "HDC_MOTOR_priv.h"
#include "HDC_MOTOR_config.h"
#include "HDC_MOTOR_init.h"

ErrorState_t HDCM_enInit(void){

	MDIO_SetPinDirection(PB3,OUTPUT);
	MDIO_SetPinDirection(PD7,OUTPUT);
#if (HBRIDGE_MODE==MOTOR_WITH_EN)
	MDIO_SetPinDirection(PD6,OUTPUT);
#endif
	MTIMER0_enInit();
	MTIMER0_enStart();
	MTIMER0_enSetFastPWM(0);

return SUCCES;
}
ErrorState_t HDCM_enStart(direction_t copy_enDirection,u8 copy_u8Duty)
{

ErrorState_t Local_enStauts=SUCCES;
//MTIMER0_enStart();
if(copy_u8Duty<=100&&copy_u8Duty>=0)
{


#if (HBRIDGE_MODE==MOTOR_WITHOUT_EN)
	//MTIMER0_enStart();
	switch(copy_enDirection){
	case forward:
		MTIMER0_enSetFastPWM(copy_u8Duty);
		MDIO_voidSetPinValue(PD7, LOW);
		break;
	case reverse:
				MTIMER0_enSetFastPWM(100-copy_u8Duty);
				MDIO_voidSetPinValue(PD7, HIGH);
				break;
	default:
		Local_enStauts=OUT_OF_RANGE;
		break;

	}
#else

		switch(copy_enDirection)
			{case forward:
				MTIMER0_enSetFastPWM(copy_u8Duty);
				MDIO_voidSetPinValue(PD7, LOW);
				MDIO_voidSetPinValue(PD6, HIGH);
				break;
			case reverse:
						MTIMER0_enSetFastPWM(copy_u8Duty);
						MDIO_voidSetPinValue(PD7, HIGH);
						MDIO_voidSetPinValue(PD6, LOW);
						break;
			default:
				Local_enStauts=OUT_OF_RANGE;
				break;
			}
#endif

		//MTIMER0_enStop();
}
else
{
	Local_enStauts=OUT_OF_RANGE;
}
return Local_enStauts;

}
ErrorState_t HDCM_enStop(void)
{
	//MTIMER0_enStop();

	MTIMER0_enSetFastPWM(0);
	//MDIO_voidSetPinValue(PB3, LOW);
	MDIO_voidSetPinValue(PD7, LOW);




return SUCCES;
}
