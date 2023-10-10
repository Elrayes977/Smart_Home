/*
 * HLM35_int.h
 *
 *  Created on: Jun 14, 2023
 *      Author: elray
 */

#ifndef HAL_HLM35_HLM35_INT_H_
#define HAL_HLM35_HLM35_INT_H_

ErrorState_t HLM35_enInit(void);
ErrorState_t HLM35_enTempRead(u8 *pTempValue);

#endif /* HAL_HLM35_HLM35_INT_H_ */
