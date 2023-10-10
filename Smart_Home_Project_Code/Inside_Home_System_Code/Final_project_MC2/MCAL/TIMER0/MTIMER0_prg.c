/*
 * MTIMER0_prg.c
 *
 *  Created on: Jun 11, 2023
 *      Author: elray
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MTIMER0_priv.h"
#include "MTIMER0_config.h"
#include "MTIMER0_int.h"
#include <avr/interrupt.h>
#include <stdlib.h>
static void (*CallBackArr[2])(void)={NULL,NULL};
static u32 g_u32NumberOfOverflows =0;
static u8  g_u8NumberOfRemainingcounts=0;
static u32 g_u32NumOfCmpMatches=0;
ErrorState_t MTIMER0_enInit(void)
{
#if(MTIMER0_MODE==MTIMER0_MODE_CTC||MTIMER0_MODE==MTIMER0_MODE_NORMAL||MTIMER0_MODE==MTIMER0_MODE_FAST_PWM||MTIMER0_MODE==MTIMER0_MODE_PHASE_CORRECT_PWM)
	//timer mode
	//step1 :clear bits by applying Mask
		TCCR0_REG &= MTIMER0_MODE_MASK;
	//step 2 :set insert vlaue
		TCCR0_REG |=MTIMER0_MODE;
#else
#error("Timer Mode out of range")
#endif


		//condig oc0 wave generatin mode
		//clear with mask
		TCCR0_REG &=MTIMER_OC0_MASK;
		//set
		TCCR0_REG |=(MTIMER0_OC0_MODE<<MTIMER0_OC0_SH);


}
ErrorState_t MTIMER0_enStart(void)
{
#if(MTIMER0_CLK>=MTIMER_NO_CLK && MTIMER0_CLK<=MTIMER_EXTCLK_RAIS_EDGE)

	//step1 :clear bits by applying Mask
	TCCR0_REG &= MTIMER0_CS_MASK;
//step 2 :set clock value
	TCCR0_REG |=MTIMER0_CLK;
#else
	#error("wrong time clock")
#endif


}
ErrorState_t MTIMER0_enStop(void)
{
//clear
	TCCR0_REG&=MTIMER0_CS_MASK;
	//set value
	TCCR0_REG |= MTIMER_NO_CLK;

}
ErrorState_t MTIMER0_enSetCallBack(u8 copy_u8IntID,void (*ptrfn)(void))
{
	ErrorState_t Local_enState= SUCCES;
	if(ptrfn==NULL)
	{
Local_enState=NULL_PTR_ERR;
	}
		switch(copy_u8IntID)
			{
			case MTIMER0_OVF_INT_ID:
				CallBackArr[0]=ptrfn;
				break;
			case MTIMER0_COM_INT_ID:
				CallBackArr[1]=ptrfn;
				break;
			default:
				Local_enState= OUT_OF_RANGE;
				break;
			}

		//CallBackArr[copy_u8IntID]=ptrfn;
}
ErrorState_t MTIMER0_enSetTime(u32 copy_u32delayMS)
{
u32	Local_u32Arr[]={1,8,64,256,1025};

f32 Local_f32Tick_Time =(f32)Local_u32Arr[MTIMER0_CLK-1]/FCPU;
u32 Local_u32TotalNumberOfCounts =(copy_u32delayMS*1000)/Local_f32Tick_Time;
#if(MTIMER0_MODE==MTIMER0_MODE_NORMAL)
g_u32NumberOfOverflows=Local_u32TotalNumberOfCounts/256;
g_u8NumberOfRemainingcounts=Local_u32TotalNumberOfCounts%256;
	if(g_u8NumberOfRemainingcounts!=0){
		TCNT0_REG=256-g_u8NumberOfRemainingcounts;
		g_u32NumberOfOverflows++;
	}
#elif(MTIMER0_MODE==MTIMER0_MODE_CTC)

	u8 Local_u8OCRValue= 255;
	while((Local_u32TotalNumberOfCounts % Local_u8OCRValue)!=0)
	{
		Local_u8OCRValue--;

	}

	OCR0_REG = Local_u8OCRValue;
	g_u32NumOfCmpMatches=Local_u32TotalNumberOfCounts/Local_u8OCRValue;
	#endif
return SUCCES;
}//works same as delay_ms
ErrorState_t MTIMER0_enEnableInt(u8 copy_u8IntID)
{
ErrorState_t Local_enState= SUCCES;

	switch(copy_u8IntID)
	{
	case MTIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIEO_BIT);
		break;
	case MTIMER0_COM_INT_ID:
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	default:
		Local_enState= OUT_OF_RANGE;
	}
return Local_enState;

}
ErrorState_t MTIMER0_enDisableInt(u8 copy_u8IntID)
{
	ErrorState_t Local_enState= SUCCES;
	switch(copy_u8IntID)
		{
		case MTIMER0_OVF_INT_ID:
			CLR_BIT(TIMSK_REG,TOIEO_BIT);
			break;
		case MTIMER0_COM_INT_ID:
			CLR_BIT(TIMSK_REG,OCIE0_BIT);
			break;
		default:
			Local_enState= OUT_OF_RANGE;
		}
	return Local_enState;

}
ErrorState_t MTIMER0_ensetCompareValue(u8 copy_u8Value)
{

	OCR0_REG=copy_u8Value;
	ErrorState_t Local_enState= SUCCES;

}

#if(MTIMER0_MODE==MTIMER0_MODE_FAST_PWM)
ErrorState_t MTIMER0_enSetFastPWM(u8 copy_u8Duty)
{
	ErrorState_t Local_enState= SUCCES;
	if(copy_u8Duty>=0&&copy_u8Duty<=100)
	{
	#if(MTIMER0_OC0_MODE==MTIMER_OC0_INVERTED)
		OCR0_REG=abs(255-((copy_u8Duty*256)/100));
#elif(MTIMER0_OC0_MODE==MTIMER_OC0_NONINVERTED)
	if(copy_u8Duty==0)
		{
			OCR0_REG=0;
		}
		else{
		OCR0_REG=abs(((copy_u8Duty*256)/100)-1);
		//OCR0_REG=abs((copy_u8Duty*255)/100);
		}
#else
#error("WRONG MODE")
#endif

	}
return Local_enState;
}
#elif(MTIMER0_MODE==MTIMER0_MODE_PHASE_CORRECT_PWM)
ErrorState_t MTIMER0_enSetPhaseCorrect(u8 copy_u8Duty)
{

	ErrorState_t Local_enState= SUCCES;
	if(copy_u8Duty>=0&&copy_u8Duty<=100)
	{
	#if(MTIMER0_OC0_MODE==MTIMER_OC0_INVERTED)
		OCR0_REG=255-((copy_u8Duty*255)/100);
#elif(MTIMER0_OC0_MODE==MTIMER_OC0_NONINVERTED)
		OCR0_REG=((copy_u8Duty*255)/100);


#else
#error("WRONG MODE")
#endif
	}
return Local_enState;
}


#endif
ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32NumberOfCounts=0; //act as global life time scope
	//Increment nuber of counts every time ISR happens
	Local_u32NumberOfCounts++;
	//if number of counts equals to global required Number
	if(Local_u32NumberOfCounts==g_u32NumberOfOverflows)
	{
		//preload TCNT with function part
		TCNT0_REG=256-g_u8NumberOfRemainingcounts;
		//take Action
		if(CallBackArr[MTIMER0_OVF_INT_ID]!=NULL)
		{
		CallBackArr[MTIMER0_OVF_INT_ID]();//app function
		}
		//reset the Localcounter for the new period
		Local_u32NumberOfCounts=0;
	}

}
ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32NumberOfCounts=0; //act as global life time scope
		//Increment nuber of counts every time ISR happens
		Local_u32NumberOfCounts++;
		//if number of counts equals to global required Number
if(Local_u32NumberOfCounts==g_u32NumOfCmpMatches)
{	//take action
	Local_u32NumberOfCounts=0;

	if(CallBackArr[MTIMER0_COM_INT_ID]!=NULL)
	{
		CallBackArr[MTIMER0_COM_INT_ID]();
	}
}
}
