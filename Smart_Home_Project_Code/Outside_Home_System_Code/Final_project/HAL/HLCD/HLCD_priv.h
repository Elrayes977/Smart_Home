/*
 * HLC_priv.h
 *
 *  Created on: Jun 1, 2023
 *      Author: elray
 */

#ifndef HAL_HLCD_HLCD_PRIV_H_
#define HAL_HLCD_HLCD_PRIV_H_

#define _4BIT_ 0
#define _8BIT_ 1
#define HLCD_CLEAR 0x01
#define HLCD_FUNCTION_SET_8Bit_2Lines_5X7 0x38 //0011 1000
#define HLCD_FUNCTION_SET_4Bit_2Lines_5X7 0x28 //0010 1000

											    	//     D C B
#define HLCD_DISPLAY_ON_CURSOS_ON_BLINK_OFF  0x0E     //0000 1 1 1 0
#define HLCD_ENTRY_MODE_SET_INC_NO_SHIFT  0x06   //0000
#define HLCD_SET_ROW1 0x80 //DDRAM location
#define HLCD_SET_ROW2 0xC0
#define HLCD_GCRAM_SET 0x40
#define GCRAM_ROW_INC 8
#define ROW_1 1
#define ROW_2 2
static void HLCD_voidNLatch(u8 copy_u8Byte);

#endif /* HAL_HLCD_HLCD_PRIV_H_ */
