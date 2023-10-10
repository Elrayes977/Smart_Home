/*
 * HDC_MOTOR_init.h
 *
 *  Created on: Jun 19, 2023
 *      Author: elray
 */

#ifndef HAL_HDC_MOTOR_HDC_MOTOR_INIT_H_
#define HAL_HDC_MOTOR_HDC_MOTOR_INIT_H_
typedef enum{
forward,
reverse
}direction_t;

ErrorState_t HDCM_enInit(void);
ErrorState_t HDCM_enStart(direction_t copy_enDirection,u8 copy_u8Duty);
ErrorState_t HDCM_enStop(void);
#endif /* HAL_HDC_MOTOR_HDC_MOTOR_INIT_H_ */
