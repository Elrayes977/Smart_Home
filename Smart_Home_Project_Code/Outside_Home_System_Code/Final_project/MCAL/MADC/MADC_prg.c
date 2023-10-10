/*
 * MADC_prg.c
 *
 *  Created on: Jun 5, 2023
 *      Author: elray
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MADC_priv.h"
#include "MADC_config.h"
#include "MADC_int.h"
/*
void MADC_Select(u8 channel)
{

ADMUX |=(1<<REFS0)|channel;

ADCSRA|=(1<<ADSC);
ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADATE);
}


u16 MADC_Read(){

	u32 adcValue=0,low,high;



	low =(int) ADCL;
	high=(int)(ADCH*256);
	adcValue = low+high;

	return adcValue;
}
*/

void M_ADC_void_Init(u8 copy_u8presclaer, u8 copy_vref)
{/*
	switch(copy_vref)
	{
	case vref_AREF:
		CLR_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
	break;
	case vref_AVCC:
		SET_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
	break;
	case vref_Internal:
			SET_BIT(ADMUX_REG,REFS0);
			SET_BIT(ADMUX_REG,REFS1);
	break;
	default:
		*/

ADMUX_REG|=(copy_vref<<6);
if(copy_u8presclaer<=7&&copy_u8presclaer>=0){

	ADCSRA_REG|=(copy_u8presclaer);
}


//Enable ADC
SET_BIT(ADCSRA_REG,ADEN);
//Start conversion
SET_BIT(ADCSRA_REG,ADSC);
//Auto Trig
#if(CONVERSION_MODE==FREE_RUNNING_MODE)

SET_BIT(ADCSRA_REG,ADATE);



#endif
}
u16 M_ADC_u16_adcRead(u8 copy_u8Channel )
{

ADMUX_REG|=(copy_u8Channel);
/*
u32 ADCvalue=0,low,high;
low=(u32)ADCL_REG;
high=(u32)(ADCH_REG*256);
ADCvalue=low+high;
*/
u16 ADCvalue=0,low,high;
low=ADCL_REG;
high=ADCH_REG<<8;
ADCvalue=low+high;
return ADCvalue;

}
