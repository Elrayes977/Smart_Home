/*
 * HKEY_PAD_init.h
 *
 *  Created on: May 31, 2023
 *      Author: elray
 */

#ifndef HAL_HKEY_PAD_HKEY_PAD_INIT_H_
#define HAL_HKEY_PAD_HKEY_PAD_INIT_H_

#define HKEYPAD_NO_PRESSED_KEY 0xFF

ErrorState_t HKEYPAD_enInt(void);

ErrorState_t HKEYPAD_enGetPressedKey(u8 * ptrKey);




#endif /* HAL_HKEY_PAD_HKEY_PAD_INIT_H_ */
