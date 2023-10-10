/*
 * HLCD_config.h
 *
 *  Created on: Jun 1, 2023
 *      Author: elray
 */

#ifndef HAL_HLCD_HLCD_CONFIG_H_
#define HAL_HLCD_HLCD_CONFIG_H_
/*
 *
 * chooseor _8BIT_
 *
 */
#define HLCD_MODE _4BIT_

#define HLCD_RS_PIN	PA1
#define HLCD_EN_PIN	PA2
#define HLCD_RW_PIN

#if(HLCD_MODE==_8BIT_)

#define HLCD_D0_PIN PB0
#define HLCD_D1_PIN PB1
#define HLCD_D2_PIN	PB2
#define HLCD_D3_PIN	PB3

#endif

#define HLCD_D4_PIN	PA3
#define HLCD_D5_PIN	PA4
#define HLCD_D6_PIN	PA5
#define HLCD_D7_PIN	PA6

#endif /* HAL_HLCD_HLCD_CONFIG_H_ */
