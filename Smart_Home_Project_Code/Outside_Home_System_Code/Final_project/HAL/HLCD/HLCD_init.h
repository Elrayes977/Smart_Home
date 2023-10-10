/*
 * HLCD_init.h
 *
 *  Created on: Jun 1, 2023
 *      Author: elray
 */

#ifndef HAL_HLCD_HLCD_INIT_H_
#define HAL_HLCD_HLCD_INIT_H_


ErrorState_t HLCD_Init(void);
ErrorState_t HLCD_SendData(u8 copy_u8Data);
ErrorState_t HLCD_SendCommand(u8 copy_u8Command);

ErrorState_t HLCD_SendString(char * str);

ErrorState_t HLCD_ClearDisplay(void);
ErrorState_t HLCD_sendIntNum(s32 copy_u32Num);
ErrorState_t HLCD_gotoXY(u8 copy_u8X,u8 copy_u8Y);
ErrorState_t HLCD_SendCustomChar(u8 copy_u8CharCode,u8 * ptrPatterCode);
ErrorState_t HLCD_DisplayCustomeChar(u8 copy_u8CharCode);
#endif /* HAL_HLCD_HLCD_INIT_H_ */
