/*
 * HULTRASONIC_int.h
 *
 *  Created on: Jun 21, 2023
 *      Author: elray
 */

#ifndef HAL_HULTRASONIC_HULTRASONIC_INT_H_
#define HAL_HULTRASONIC_HULTRASONIC_INT_H_

typedef enum {STATE1 = 1,STATE2,STATE3}StateMachine_t;
static volatile u16 g_Reading1 = 0;
static volatile u16 g_Reading2 = 0;

static volatile u16 g_T1OVFint=0;
static volatile u16 g_T1OVFint_Multfact1=0;
static volatile u16 g_T1OVFint_Multfact2=0;
static volatile StateMachine_t g_State = STATE1;


void OVF_INC(void);
void ICU_HW(void);



ErrorState_t HUltrasonic_enInit(Pin_t copy_enTrigPin);
ErrorState_t HUltrasonic_enStartReading(u8 copy_u8TrigPin,u32 * copy_u8Distance);

#endif /* HAL_HULTRASONIC_HULTRASONIC_INT_H_ */
