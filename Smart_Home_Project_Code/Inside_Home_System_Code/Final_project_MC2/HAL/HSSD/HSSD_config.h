/*
 * HSSD_config.h
 *
 *  Created on: May 30, 2023
 *      Author: Elrayes
 */

#ifndef DEBUG_HAL_HSSD_HSSD_CONFIG_H_
#define DEBUG_HAL_HSSD_HSSD_CONFIG_H_

/*
PLEASE CONFIGUR PINS FOR 7 SEGMENT LEDS:
A,B.......G,DP

EN1 DIG,EN2 DIG


*/



#define HSSD_LED_A_PIN  PA1
#define HSSD_LED_B_PIN	PA2
#define HSSD_LED_C_PIN	PA3
#define HSSD_LED_D_PIN	PA4
#define HSSD_LED_E_PIN	PA5
#define HSSD_LED_F_PIN	PA6
#define HSSD_LED_G_PIN	PA7
#define HSSD_LED_DP_PIN	PB0

#define HSSD_EN1_PIN	PC6
#define HSSD_EN2_PIN	PC7

/*
 *
 * configur display time
 */

#define HSSD_DISPLAY_TIME 500
/*
 * choose SSD type
 * HSSD_CA
 * HSSD_CC
 */
#define HSSD_TYPE
#endif /* DEBUG_HAL_HSSD_HSSD_CONFIG_H_ */
