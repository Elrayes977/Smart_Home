/*
 * MEXIT_int.h
 *
 *  Created on: Jun 7, 2023
 *      Author: elray
 */
#ifndef MEXIT_INT_H_
#define MEXIT_INT_H_

typedef enum{
	LOW_LEVEL_TRIG=0,

	ANY_CHANGE_TRIG=1,

	FALL_EDGE_TRIG=2,

	RAIS_EDGE_TRIG=3

}IntTrigger_t;


typedef enum{
	INT2_ID=5,
	INT0_ID=6,
	INT1_ID=7



}InterruptID_t;

ErrorState_t MEXIT_enEnable(InterruptID_t copy_enID,IntTrigger_t copy_enTrig);//set ON Enable , config trigger
ErrorState_t MEXIT_enDisable(InterruptID_t copy_enID);//Set off

ErrorState_t MEXIT_enSetCallBack(InterruptID_t copy_enID,void (*ptrfn)(void));

#endif //MEXIT_INT_H_
