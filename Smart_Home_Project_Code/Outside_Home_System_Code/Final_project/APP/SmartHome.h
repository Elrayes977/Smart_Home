/*
 * SmartHome.h
 *
 *  Created on: Jun 25, 2023
 *      Author: AA
 */

#ifndef SMARTHOME_H_
#define SMARTHOME_H_

#include "STD_TYPES.h"
//#include "MUART_int.h"

/***************************** SHARED VARIABLES *******************************/

extern u16 AdminData, GuestData;	// Variables to Store data from EEPROM
extern u8 timeout_flag;
extern u8 key;
extern u32 Distance;
/*************************** FUNCTION DECLERATION *****************************/
/*
 * First time set passward
 *
 */
void CreatPassward(void);


/*
 * Function to raise timeout_flag
 */
void SessionTime_INT(void);

/*
 * Function to take the Action of timeout_flag
 */
void SessionTime_TASK(void);

/*
 * Function to Select the mode (Admin - Guest)
 * take actions based on Flags (AdminFlag, GuestFlag ,DefaultFlag )
 * take actions (System Blocked ) based on no. of (ErrFlag)
 */
u8 SelectMode(void);

/*
 * Function to take the password from user
 * and check this password with the one in data base
 */
u8 CheckPass(u8 key);

#endif /* SMARTHOME_H_ */
