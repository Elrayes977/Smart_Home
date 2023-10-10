/*
 * Config.h
 *
 *  Created on: May 29, 2023
 *      Author: Elrayes
 */

#ifndef HAL_LED_HLED_CONFIG_H_
#define HAL_LED_HLED_CONFIG_H_
/*
 * please conifgure LED pins
 *
 * please choose led direction
 * HLED_LED_FORWARD , HLED_LED_REVERSE
 *
 * */
#define HLED_RED_LED_PIN	PC0
#define HLED_RED_LED_DIR	HLED_LED_FORWARD




#define HLED_GRN_LED_PIN	PC1
#define HLED_GRN_LED_DIR	HLED_LED_FORWARD

#define HLED_BLUE_LED_PIN	PC2
#define HLED_BLUE_LED_DIR	HLED_LED_FORWARD

#endif /* HAL_LED_HLED_CONFIG_H_ */
