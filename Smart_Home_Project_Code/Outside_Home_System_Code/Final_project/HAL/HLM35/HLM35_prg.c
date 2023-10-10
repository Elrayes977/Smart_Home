/*
 * HLM35_prg.c
 *
 *  Created on: Jun 14, 2023
 *      Author: elray
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "HLM35_priv.h"
#include "HLM35_config.h"
#include "HLM35_int.h"
#include "MADC_int.h"
#include "MDIO_int.h"
ErrorState_t HLM35_enInit(void)
{

//step 1 set pin input
	MDIO_SetPinDirection(HLM35_PIN, INPUT);
	//init adc
	M_ADC_void_Init(prescaler_128,vref_AVCC);

	return SUCCES;

}
ErrorState_t HLM35_enTempRead(u8 *pTempValue)
{
	ErrorState_t Local_enState=SUCCES;
	if(pTempValue !=NULL){
u16 Local_ADC_DigitalValue;

Local_ADC_DigitalValue=M_ADC_u16_adcRead(HLM35_CHANNEL);


//convert
u32 Local_u32Readmv =((u32)Local_ADC_DigitalValue*5000)/1024;//DCA 5mV/resulution ==> value in mvolt
*pTempValue=Local_u32Readmv/10; //==>50mV =5 C

	}//end if
	else
	{
		ErrorState_t Local_enState=NULL_PTR_ERR;
	}

	return Local_enState;
}

