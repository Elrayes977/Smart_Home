/*
 * HKEY_PAD_config.h
 *
 *  Created on: May 31, 2023
 *      Author: elrayes
 */

#ifndef HAL_HKEY_PAD_HKEY_PAD_CONFIG_H_
#define HAL_HKEY_PAD_HKEY_PAD_CONFIG_H_

#define HKEYPAD_R0_PIN  PB4

#define HKEYPAD_R1_PIN	 PB5


#define HKEYPAD_R2_PIN  PB6

#define HKEYPAD_R3_PIN  PB7


#define HKEYPAD_C0_PIN  PD2

#define HKEYPAD_C1_PIN	 PD3


#define HKEYPAD_C2_PIN  PD4

#define HKEYPAD_C3_PIN  PD5

/*
 *choose between real REAL_KIT or SIM_KIT
 *
 */
#define KIT_TYPE	SIM_KIT
/*
 * here you can choose keypad mapping
 *
 */
#define HKEYPAD_KEYS  	{{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'c',0,'=','+'}}
#endif /* HAL_HKEY_PAD_HKEY_PAD_CONFIG_H_ */
