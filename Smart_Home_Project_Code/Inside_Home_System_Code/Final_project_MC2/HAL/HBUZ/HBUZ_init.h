/*
 * HBUZ_init.h
 *
 *  Created on: May 31, 2023
 *      Author: elray
 */

#ifndef HAL_HBUZ_HBUZ_INIT_H_
#define HAL_HBUZ_HBUZ_INIT_H_

void HBUZ_voidInit(void);
ErrorState_t HBUZ_enOn(void);
ErrorState_t HBUZ_enOff(void);
ErrorState_t HBUZ_enOnce(u64 copy_u64BuzzPeriod);
ErrorState_t HBUZ_enTwice(u64 copy_u64BuzzPeriod);

#endif /* HAL_HBUZ_HBUZ_INIT_H_ */
