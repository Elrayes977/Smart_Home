/*
 * MTIMER0_int.h
 *
 *  Created on: Jun 11, 2023
 *      Author: elray
 */

#ifndef TIMER0_MTIMER0_INT_H_
#define TIMER0_MTIMER0_INT_H_
#define MTIMER0_OVF_INT_ID 0
#define MTIMER0_COM_INT_ID 1

ErrorState_t MTIMER0_enInit(void);
ErrorState_t MTIMER0_enStart(void);
ErrorState_t MTIMER0_enStop(void);
ErrorState_t MTIMER0_enSetCallBack(u8 copy_u8IntID,void (*ptrfn)(void));
ErrorState_t MTIMER0_enSetTime(u32 copy_u32delayMS);//wor;s same as delay_ms
ErrorState_t MTIMER0_enEnableInt(u8 copy_u8IntID);
ErrorState_t MTIMER0_enDisableInt(u8 copy_u8IntID);
ErrorState_t MTIMER0_ensetCompareValue(u8 copy_u8Value);
#if(MTIMER0_MODE==MTIMER0_MODE_FAST_PWM)
ErrorState_t MTIMER0_enSetFastPWM(u8 copy_u8Duty);
#elif(MTIMER0_MODE==MTIMER0_MODE_PHASE_CORRECT_PWM)
ErrorState_t MTIMER0_enSetPhaseCorrect(u8 copy_u8Duty);
#endif
#endif /* TIMER0_MTIMER0_INT_H_ */
