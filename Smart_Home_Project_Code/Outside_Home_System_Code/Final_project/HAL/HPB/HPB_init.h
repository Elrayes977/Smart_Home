/*
 * HPB_init.h
 *
 *  Created on: May 30, 2023
 *      Author: Elrayes
 */

#ifndef HAL_HPB_HPB_INIT_H_
#define HAL_HPB_HPB_INIT_H_

#define HPB_PB1_ID  1
#define HPB_PB2_ID 2
#define HPB_PB3_ID  3
#define HPB_PB4_ID  4



typedef enum
{
	PB1_ID=1,
	PB2_ID=2,
	PB3_ID=3,
	PB4_ID=4,
}PBID_t;
typedef enum{

	PB_PRESSED=0,
	PB_RELEASED=1

}PBState_t;

typedef struct{

	PBID_t PushButtonID;
	Pin_t PushButtonPin;

}PB_t;

ErrorState_t HPB_enInit(PB_t * ptrPB);
ErrorState_t HPB_enRead(PB_t *PushButtonPin ,PBState_t * ptrState);



#endif /* HAL_HPB_HPB_INIT_H_ */
