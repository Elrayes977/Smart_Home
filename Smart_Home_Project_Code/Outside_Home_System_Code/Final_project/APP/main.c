/*
 *
 *
 *  Created on: Jun 26, 2023
 *   Author:Mohamed Hegazy & Abdelrahman Elrayes
 */
#include <avr/delay.h>
/*LIB Files*/
#include "STD_TYPES.h"
#include "ERROR_STATES.h"

/*MCAL DRIVERS*/
#include "MDIO_int.h"
#include "MEXIT_int.h"
#include "MGIE_int.h"
#include "MADC_int.h"
#include "MTIMER0_int.h"
#include "MTIMER1_int.h"
#include "MTWI_int.h"
#include "MUART_int.h"

/*HAL DRIVERS*/
#include "HLCD_init.h"
#include "HLED_int.h"
#include "HSSD_int.h"
#include "HPB_init.h"
#include "HBUZ_init.h"
#include "HKEY_PAD_init.h"
#include "HLM35_int.h"
#include "HEEPROM_int.h"
#include "HRELAY_int.h"
#include "HULTRASONIC_int.h"
/*APP Files*/
#include "SmartHome_config.h"
#include "SmartHome.h"

/*
 * GRAD Project
 */


void main(void)
{

/****************************** LOCAL VARIABLES *******************************/

	u8 Init_Adderss, AData_Adress, GData_Adress; //for EEPROM SAVED DATA
	u8 i, temp;
	u8 returnValue;
	u8 EEPROM_state=EMPTY_EEPROM;
	u8 welcome_flag=0;
/****************************** INITIALIZATION ********************************/

	/* initialize The HAL Drivers*/
	HUltrasonic_enInit(TRIGG_PIN);
	HLED_enInit(HLED_RED_ID);
	HLCD_Init();
	HKEYPAD_enInt();
	HEEPROM_enInit();
	HRELAY_enInit();
	/* initialize The MCAL Drivers*/
	MTIMER0_enInit();
	MTWI_enInit();
	MUART_enInit();

	MDIO_SetPinDirection(SIGNAL_PIN, OUTPUT);
/****************************** SMART HOME CODE *******************************/


		/** Check for first time **/

		HEEPROM_enReadByte(1, &Init_Adderss);
		_delay_ms(30);

		if (Init_Adderss != 0)
		{
			i = 2;
			while (i <= 5)
			{
				temp = i * 2;
				// first 4 byte for ADMIN
				HEEPROM_enWriteByte(temp, 0); //& 4 6 8 10
				_delay_ms(30);

				// Second 4 byte for GUEST
				HEEPROM_enWriteByte(temp + 8, 0); //& 12 13 14 16
				_delay_ms(30);
				i++;
			}
			EEPROM_state=EMPTY_EEPROM;
		}
		else
		{
			EEPROM_state=NOT_EMPTY_EEPROM;
		}

		/** Store data in variables **/

		i = 2;
		while (i <= 5)
		{
			temp = i * 2;
			// first 4 byte for ADMIN
			HEEPROM_enReadByte(temp, &AData_Adress); //& 4 6 8 10
			_delay_ms(30);
			AdminData = (AdminData * 10) + AData_Adress;

			// Second 4 byte for GUEST
			HEEPROM_enReadByte(temp + 8, &GData_Adress); //& 12 13 14 16
			_delay_ms(30);
			GuestData = (GuestData * 10) + GData_Adress;
			i++;
		}


		/****** SELECT SESSION TIME ******/
/*
		MTIMER0_enEnableInt(MTIMER0_OVF_INT_ID);
		MTIMER0_enSetCallBack(MTIMER0_OVF_INT_ID,SessionTime_INT);
		MTIMER0_enSetTime(10000);
		// Enable the GIE & Start Timer
		MGIE_enEnable();
		MTIMER0_enStart();

*/




	/***************************** PERIODIC CODE *****************************/
	while(1)
	{
		/** Ultrasonic condition **/
		HUltrasonic_enStartReading(TRIGG_PIN, &Distance);
		if (Distance <= 30)
		{
			HLCD_ClearDisplay();
			if(welcome_flag==0)
			{
		        /** Welcome screen **/
				HLCD_SendString("Welcome to smart");
				HLCD_gotoXY(2, 1);
				HLCD_SendString("home system");
				_delay_ms(500);
				HLCD_ClearDisplay();
				welcome_flag=1;
			}

			if(EEPROM_state==EMPTY_EEPROM)
			{
				/** First Time Case **/

				CreatPassward();
				i = 2;
				while (i <= 5)
				{
					temp = i * 2;
					// first 4 byte for ADMIN
					HEEPROM_enReadByte(temp, &AData_Adress); //& 4 6 8 10
					_delay_ms(30);
					AdminData = (AdminData * 10) + AData_Adress;

					// Second 4 byte for GUEST
					HEEPROM_enReadByte(temp + 8, &GData_Adress); //& 12 13 14 16
					_delay_ms(30);
					GuestData = (GuestData * 10) + GData_Adress;
					i++;
				}
				EEPROM_state=NOT_EMPTY_EEPROM;
			}
			else
			{
				/** Not First Time Case **/
				HLCD_ClearDisplay();
				key = HKEYPAD_NO_PRESSED_KEY;
				returnValue = 1;
				while(returnValue != 0)
				{
					// /****** SELECT MODE ******
					//u8 ret = 1;
					returnValue = SelectMode();
				}
				if(timeout_flag == 1)
				{
					SessionTime_TASK();
					timeout_flag = 0;
				}

			}



		}//if ultrasonice
		else
		{
			HLCD_ClearDisplay();
			HLCD_SendString("SYSTEM IS OFF !!");

			welcome_flag=0;
		}
	}
}
