/*
 * SmartHome.c
 *
 *  Created on: Jun 25, 2023
 *      Author: AA
 */
#include <util/delay.h>
#include "STD_TYPES.h"

//#include "MUART_int.h"
#include "SmartHome_config.h"
#include "SmartHome.h"


//#include "MEXIT_int.h"
#include "MDIO_int.h"
#include "MUART_int.h"

#include "HKEY_PAD_init.h"
#include "HLCD_init.h"
#include "HEEPROM_int.h"
#include "HRELAY_int.h"
#include "HULTRASONIC_int.h"



/***************************** SHARED VARIABLES *******************************/

u16 AdminData = 0 , GuestData =0;	// Variables to Store data from EEPROM
u8 key = HKEYPAD_NO_PRESSED_KEY;
u8 timeout_flag = 0;
u32 Distance=0;
/***************************** GLOBAL VARIABLES *******************************/

u16 AdminPass, GuestPass;	// Variables to Store data from user
u8 AdminFlag = 0 , GuestFlag = 0,DefaultFlag = 0; // Flags
u8 temp , Errflag = 0;
u8 i =0;
/************************* FUNCTION EMPLEMENTATION ****************************/

/*
 * First time set passward
 *
 */
void CreatPassward(void)
{


	HEEPROM_enWriteByte(1, 0); // SET the initialization password
	_delay_ms(30);

	HLCD_SendString("Please Login");
	HLCD_gotoXY(2, 1);
	HLCD_SendString("First time..");
	_delay_ms(500);
	HLCD_ClearDisplay();

/******************* SETTING ADMIN PASSWORD ********************/

	HLCD_SendString("SET ADMIN PASS..");
	HLCD_gotoXY(2, 1);
	HLCD_SendString("Admin Pass: ");
	 i = 2;
	while (i <= 5)
	{
		temp = i * 2;
		HKEYPAD_enGetPressedKey(&key);
		if (key != HKEYPAD_NO_PRESSED_KEY)
		{
			 if (key == 'c')
			 {
				 HLCD_gotoXY(2, 10+i); // 12 13 14 15
				 HLCD_SendString(" ");
				 i--;
			 }
			 else
			 {
				 HEEPROM_enWriteByte(temp, key);
				 HLCD_sendIntNum(key);
				 HLCD_gotoXY(2, 11+i); // 12 13 14 15
				 HLCD_SendString("*");
				 i++;
			 }
		}
	}
	HLCD_ClearDisplay();
	HLCD_gotoXY(1, 6);
	HLCD_SendString("Done");
	HLCD_gotoXY(2, 3);
	HLCD_SendString("Pass Saved");
	_delay_ms(500);
	HLCD_ClearDisplay();

/******************* SETTING GUEST PASSWORD ********************/

	HLCD_SendString("SET GUEST PASS..");
	HLCD_gotoXY(2, 1);
	HLCD_SendString("Guest Pass: ");
	i = 2;
	while (i <= 5)
	{

		temp = i * 2;
		HKEYPAD_enGetPressedKey(&key);
		if (key != HKEYPAD_NO_PRESSED_KEY)
		{
			 if (key == 'c')
			 {
				 HLCD_gotoXY(2, 10+i); // 13 14 15 16
				 HLCD_SendString(" ");
				 i--;
			 }
			 else
			 {
				HEEPROM_enWriteByte(temp + 8, key);

				HLCD_sendIntNum(key);
				HLCD_gotoXY(2, 11+i); // 12 13 14 15
				HLCD_SendString("*");
				i++;
			 }
		}
	}
	HLCD_ClearDisplay();
	HLCD_gotoXY(1, 6);
	HLCD_SendString("Done");
	HLCD_gotoXY(2, 3);
	HLCD_SendString("Pass Saved");
	_delay_ms(500);
	HLCD_ClearDisplay();


}




/*
 * Function to raise timeout_flag
 */
void SessionTime_INT(void)
{
	timeout_flag = 1;
}

/*
 * Function to take the Action of timeout_flag
 */
void SessionTime_TASK(void)
{
	HLCD_ClearDisplay();
	HLCD_gotoXY(1, 1);
	HLCD_SendString("Session Timeout");
	_delay_ms(1000);
	HLCD_ClearDisplay();
}

/*
 * Function to Select the mode (Admin - Guest)
 * take actions based on Flags (AdminFlag, GuestFlag ,DefaultFlag )
 * take actions (System Blocked ) based on no. of (ErrFlag)
 */
u8 SelectMode(void)
{
	u8 CheckRet;
	HLCD_SendString("Select Mode :");
	HLCD_gotoXY(2, 1);
	HLCD_SendString("0:Admin 1:Guest");
	key=HKEYPAD_NO_PRESSED_KEY;
	while(key == HKEYPAD_NO_PRESSED_KEY)
	{
		HUltrasonic_enStartReading(TRIGG_PIN, &Distance);

		if((timeout_flag == 1)||(Distance > 30))
		{
			return 0;
		}
		HKEYPAD_enGetPressedKey(&key);
	}

	HLCD_ClearDisplay();
	if (key != HKEYPAD_NO_PRESSED_KEY)
	{
		CheckRet = CheckPass(key);
		if (CheckRet == 0)
		{
			return 0;
		}
	}

	while(Errflag < 2)
	{
		if((AdminFlag == 1) || (GuestFlag == 1))
		{
			//HRELAY_enOn();
			if(AdminFlag == 1)
			{
				HLCD_ClearDisplay();
				HLCD_SendString("[C]EXIT[0]OPEN");
				HLCD_gotoXY(2, 1);
				HLCD_SendString("[1]CLOSE");
				key=HKEYPAD_NO_PRESSED_KEY;
				while(key!='c')
				{
					HUltrasonic_enStartReading(TRIGG_PIN, &Distance);
					if((timeout_flag == 1)||(Distance > 30))
					{
						return 0;
					}

					HKEYPAD_enGetPressedKey(&key);
					if(key!=HKEYPAD_NO_PRESSED_KEY){
					switch(key)
					{
					case 0:
						MUART_enSendByteSync('o');
						MDIO_voidTogglePinValue(SIGNAL_PIN);
						HRELAY_enOn();
						HLCD_gotoXY(2, 15);
						HLCD_SendData(key);
					break;
					case 1:
						MUART_enSendByteSync('f');
						MDIO_voidTogglePinValue(SIGNAL_PIN);
						HRELAY_enOFF();
						HLCD_gotoXY(2, 15);
						HLCD_SendData(key);
					break;
					default:
						HLCD_gotoXY(2, 15);
						HLCD_SendString("X");
					break;

					}
					}
				}
				HLCD_ClearDisplay();
				//MDIO_voidSetPinValue(SIGNAL_PIN, HIGH);
			}
			Errflag = 0;
			break;
		}
		else if(DefaultFlag == 1)
		{
			key = HKEYPAD_NO_PRESSED_KEY;
			HLCD_ClearDisplay();
			HLCD_SendString("Select Mode :");
			HLCD_gotoXY(2, 1);
			HLCD_SendString("0:Admin 1:Guest");

			while(key == HKEYPAD_NO_PRESSED_KEY)
			{
				HUltrasonic_enStartReading(TRIGG_PIN, &Distance);

				if((timeout_flag == 1)||(Distance > 30))
				{
					return 0;
				}
				HKEYPAD_enGetPressedKey(&key);
			}

			HLCD_ClearDisplay();
			if (key != HKEYPAD_NO_PRESSED_KEY)
			{

				CheckRet = CheckPass(key);
				if (CheckRet == 0)
				{
					return 0;
				}
			}
		}
		else
		{
			HLCD_ClearDisplay();
			HLCD_gotoXY(1, 2);
			HLCD_SendString("Wrong Password");
			HLCD_gotoXY(2, 1);
			HLCD_SendString("Please Try Again");
			HLCD_ClearDisplay();
			CheckRet = CheckPass(key);
			if (CheckRet == 0)
			{
				return 0;
			}
			Errflag++;
		}

	}

	if(Errflag == 2)
	{
		s8 time =12;
		HLCD_ClearDisplay();
		HLCD_gotoXY(1, 2);
		HLCD_SendString("Wrong Password");
		HLCD_ClearDisplay();

		// BLOCK SYSTEM (30 Sec)
		HLCD_SendString("SYSTM IS BLOCKED");
		HLCD_gotoXY(2, 1);
		HLCD_SendString("Unlock in");
		HLCD_gotoXY(2, 11);
		HLCD_sendIntNum(time);
		HLCD_gotoXY(2, 14);
		HLCD_SendString("SEC");
		while(time > 0)
		{
			_delay_ms(500);
			time--;
			if(time < 10)
			{
				HLCD_gotoXY(2, 11);
				HLCD_sendIntNum(0);
				HLCD_gotoXY(2, 12);
				HLCD_sendIntNum(time);
			}
			else
			{
				HLCD_gotoXY(2, 11);
				HLCD_sendIntNum(time);
			}

		}
		Errflag = 0;
		HLCD_ClearDisplay();
		HLCD_SendString("SESTEM UNLOCKED");
	}
	return 1;
}

/*
 * Function to take the password from user
 * and check this password with the one in data base
 */
u8 CheckPass(u8 key)
{
	AdminPass = 0;
	GuestPass = 0;
	AdminFlag = 0;
	GuestFlag = 0;
	DefaultFlag = 0;
	/****** SET PASSWORDS ******/
	switch (key)
	{
	u8 i;
		case ADMIN_MODE:
			HLCD_SendString("Admin Mode :");
			HLCD_gotoXY(2, 1);
			HLCD_SendString("Enter Pass: ");
			i = 2;

			while (i <= 5)
			{
				HUltrasonic_enStartReading(TRIGG_PIN, &Distance);

				if((timeout_flag == 1)||(Distance > 30))
				{
					return 0;
				}
				HKEYPAD_enGetPressedKey(&key);
				if (key != HKEYPAD_NO_PRESSED_KEY)
				{
					 if (key == 'c')
					 {
						 AdminPass = (AdminPass -temp) / 10;
						 HLCD_gotoXY(2, 10+i); // 12 13 14 15
						 HLCD_SendString(" ");
						 HLCD_gotoXY(2, 10+i);
						 i--;
					 }
					 else
					 {
						temp = key;
						HLCD_sendIntNum(key);
						 HLCD_gotoXY(2, 11+i); // 12 13 14 15
						 HLCD_SendString("*");
						AdminPass = (AdminPass * 10) + key;
						i++;
					 }
				}
			}

			/****** Check ADMIN PASSWORDS ******/
			if (AdminPass == AdminData)
			{
				HLCD_ClearDisplay();
				HLCD_gotoXY(1, 5);
				HLCD_SendString("WELCOME");
				HLCD_gotoXY(2, 3);
				HLCD_SendString("Mr. Hegazy");
				_delay_ms(500);
				HLCD_ClearDisplay();
				AdminFlag = 1;
			}
			break;

		case GUEST_MODE:
			HLCD_SendString("Guest Mode :");
			HLCD_gotoXY(2, 1);
			HLCD_SendString("Enter Pass: ");
			i = 2;
			while (i <= 5)
			{
				HUltrasonic_enStartReading(TRIGG_PIN, &Distance);

				if((timeout_flag == 1)||(Distance > 30))
				{
					return 0;
				}
				temp = i * 2;
				HKEYPAD_enGetPressedKey(&key);
				if (key != HKEYPAD_NO_PRESSED_KEY)
				{

					 if (key == 'c')
					 {
						 GuestPass = (GuestPass -temp) / 10;
						 HLCD_gotoXY(2, 10+i); // 12 13 14 15
						 HLCD_SendString(" ");
						 HLCD_gotoXY(2, 10+i);
						 i--;
					 }
					 else
					 {
						temp = key;
						HLCD_sendIntNum(key);
						HLCD_gotoXY(2, 11+i); // 12 13 14 15
						HLCD_SendString("*");
						GuestPass = (GuestPass * 10) + key;
						i++;
					 }
				}
			}
			/****** Check GUEST PASSWORDS ******/
			if (GuestPass == GuestData)
			{
				HLCD_ClearDisplay();
				HLCD_gotoXY(1, 5);
				HLCD_SendString("WELCOME");
				HLCD_gotoXY(2, 4);
				HLCD_SendString("Mr. Boody");
				_delay_ms(500);
				HLCD_ClearDisplay();
				GuestFlag = 1;
			}
			break;

		default:
			HLCD_SendString("Wrong Input !!");
			DefaultFlag = 1;
			break;
	}
	return 1;
}
