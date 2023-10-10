/*
 *
 *
 *  Created on: Jun 26, 2023
 *   Author:Mohamed Hegazy & Abdelrahman Elrayes
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "MDIO_int.h"
#include "MEXIT_int.h"
#include "MGIE_int.h"
#include "MADC_int.h"
#include "MTIMER0_int.h"
#include "MTIMER1_int.h"
#include "MTWI_int.h"
#include "MTWI_int.h"
#include "MUART_int.h"

#include "HLCD_init.h"
#include "HLED_int.h"
#include "HSSD_int.h"
#include "HPB_init.h"
#include "HBUZ_init.h"
#include "HKEY_PAD_init.h"
#include "HLM35_int.h"
#include "HDC_MOTOR_init.h"
#include "HEEPROM_int.h"
#include "HULTRASONIC_int.h"


#include "Home_system.h"
//#define TRIG_PIN PC7
//costume carecters
volatile u8 Recived_DATA=0;
void Sytem_flag_recived(void);
void Sytem_flag_recived(void)
{
UART_ReceiveNoBlock((u8 *)&Recived_DATA);


}


void main(void) {
	/*************************** MAIN DEFINITIONS ***************************/

	u8 ACflag = 0, Sflag = 0;

	u8 Temp,key = HKEYPAD_NO_PRESSED_KEY;
	s8 ACTemp = 25;
	u8 lamp1F=0,lamp2F=0,lamp3F=0;
	u8 smile[] = { 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00, 0x00 };
	u8 sad[] = { 0x00, 0x00, 0x0A, 0x00, 0x0E, 0x11, 0x00, 0x00 };
	u8 House[] = { 0x04, 0x0E, 0x1F, 0x15, 0x15, 0x1F, 0x1B, 0x1B };
	u8 Ice[] = { 0x04, 0x15, 0x0E, 0x1F, 0x0E, 0x15, 0x04, 0x00 };
	u8 Lamp[] = { 0x1F, 0x1F, 0x0E, 0x1F, 0x15, 0x11, 0x0E, 0x00 };

	/**************************** INITIALIZATION ****************************/

	/* initialize The MCAL Drivers*/

	MDIO_SetPinDirection(PD0, INPUT);
	MDIO_voidSetPinValue(PD0, HIGH);
	MUART_enInit();
	MUART_enRx_interruptENable();
	MUART_RX_Setcallback(Sytem_flag_recived);
	MGIE_enEnable();

	/* initialize The HAL Drivers*/
	HLED_enInit(HLED_RED_ID);
	HLED_enInit(HLED_BLUE_ID);
	HLED_enInit(HLED_GRN_ID);
	HLCD_Init();
	HKEYPAD_enInt();
	HLM35_enInit();
	HDCM_enInit();
	HBUZ_voidInit();
	HSSD_enInit();
	//HRELAY_enInit();
	HLED_enInit(HLED_RED_ID);
	HLED_enInit(HLED_BLUE_ID);
	HLED_enInit(HLED_GRN_ID);


	//MTIMER0_enInit();
	//MTIMER1_enInit();
	//MTWI_enInit();
	//MSPI_enSPI_MasterInit();
	//MSPI_enSPI_SlaveInit();

	/*************************** SMART HOME CODE ***************************/

	HLCD_SendString("System Off");
	HLCD_SendCustomChar(HOUSE, House);
	HLCD_SendCustomChar(ICE, Ice);
	HLCD_SendCustomChar(SMILE, smile);
	HLCD_SendCustomChar(SAD, sad);
	HLCD_SendCustomChar(LAMP, Lamp);
	HLCD_gotoXY(1, 11);
	HLCD_DisplayCustomeChar(SAD);
	//HLCD_SendData(1);
	Value_t SystemFlag=LOW ;
	key = HKEYPAD_NO_PRESSED_KEY;
	while (1) {

		MDIO_voidGetPinValue(PD0, &SystemFlag);
//HUltrasonic_enStartReading(TRIG_PIN,&Distance);
		//if (SystemFlag ==LOW) {
	if(Recived_DATA=='o'){
		if (Sflag == 0) {
				_delay_ms(100);
				HLCD_ClearDisplay();
				_delay_ms(100);
				HLCD_SendString("Loading...");
				_delay_ms(100);
				HLCD_ClearDisplay();
				HLCD_SendString("Welcome");
				HLCD_gotoXY(1, 9);
				HLCD_DisplayCustomeChar(HOUSE);
				HLCD_DisplayCustomeChar(SMILE);
				Sflag = 1;
				_delay_ms(1000);
				HLCD_ClearDisplay();
			}

			HKEYPAD_enGetPressedKey(&key);
			if (key != HKEYPAD_NO_PRESSED_KEY) {
				switch (key) {
				case 'c':
					ACflag ^= 1;
					if (ACflag == 1) {
						HLCD_gotoXY(1,1);
						HLCD_SendString("AC ON ");
					} else {
						HLCD_gotoXY(1,1);
						HLCD_SendString("AC OFF");

					}
					break;
				case '-':
					if (ACTemp>=17) {
						ACTemp--;
						HLCD_gotoXY(1,14);
						HLCD_sendIntNum(ACTemp);
						HLCD_SendString("C");
						//HLCD_SendString("  ");
					}
					break;

				case '+':
					if (ACTemp <= 31) {
						ACTemp++;
						HLCD_gotoXY(1,14);
						HLCD_sendIntNum(ACTemp);
						HLCD_SendString("C");
					}
					break;
				case 1:
					HLED_enToggle(HLED_RED_ID);
					lamp1F^=1;
					if(lamp1F==1)
					{
						HLCD_gotoXY(2,1);
						HLCD_DisplayCustomeChar(LAMP);
					}
					else
					{
						HLCD_gotoXY(2,1);
						HLCD_SendString(" ");
					}
					break;
				case 2:
					HLED_enToggle(HLED_BLUE_ID);
					lamp2F^=1;
				if(lamp2F==1)
				{
					HLCD_gotoXY(2,2);
					HLCD_DisplayCustomeChar(LAMP);
				}
				else
				{
						HLCD_gotoXY(2,2);
						HLCD_SendString(" ");
				}
					break;
				case 3:
					HLED_enToggle(HLED_GRN_ID);
					lamp3F^=1;
					if(lamp3F==1)
					{
						HLCD_gotoXY(2,3);
						HLCD_DisplayCustomeChar(LAMP);
					}
					else
					{
					HLCD_gotoXY(2,3);
					HLCD_SendString(" ");
					}

					break;
				default:
					HLCD_gotoXY(2, 14);
					HLCD_DisplayCustomeChar(SAD);
				}
			}	//key if
			else {

			}	//end else
			if (ACflag == 1) {
				//HLCD_ClearDisplay();

				AC_ON(ACTemp);

			}	//AC IF
			else {
				AC_OFF();


			}	//AC else
			HLCD_gotoXY(2,13);
			HLCD_DisplayCustomeChar(HOUSE);
			HLM35_enTempRead(&Temp);
			HLCD_gotoXY(2,14);
			HLCD_sendIntNum(Temp);
			HLCD_SendString("C");
		} //end system  if
		else{
			Sflag=0;
			AC_OFF();
			HLED_enSetOFF(HLED_BLUE_ID);
			HLED_enSetOFF(HLED_GRN_ID);
			HLED_enSetOFF(HLED_RED_ID);
			HLCD_ClearDisplay();
			HLCD_SendString("SYSTEM OFF");
		} //end  SYTEM else


	}
}

