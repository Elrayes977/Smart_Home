/*
 * Home_system.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Elrayes
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "HLCD_init.h"
#include "HDC_MOTOR_init.h"
#include "Home_system.h"
#include "HLM35_int.h"


void AC_ON(s8 copy_s8ACtemp) {
	u8 temp;
	//s8 ACTemp=25;
	s8 Initial_speed = 25; //25%
	s8 productValue = 0;
	s8 finalspeed;
	HLM35_enTempRead(&temp);
	/*
	 HLCD_gotoXY(2, 9);
	 HLCD_sendIntNum(temp);
	 HLCD_SendString("C");
	 HLCD_sendIntNum(copy_s8ACtemp);
	 HLCD_SendString("C");
	 HLCD_SendString("  ");
	 */
	if ((s8) temp > copy_s8ACtemp) {	//HLCD_ClearDisplay();
		HLCD_gotoXY(1, 13);
		HLCD_DisplayCustomeChar(ICE);							//HLCD_SendString("FAN ON");
		productValue = (s8) temp - copy_s8ACtemp;
		finalspeed = Initial_speed + (productValue * 5);
		if (finalspeed >= 0) {
			HDCM_enStart(forward, (u8) finalspeed);
		} //end if

		else {

		}
	} //end temp if
	else if ((s8) temp <= copy_s8ACtemp) {
		//HLCD_ClearDisplay();
		//HLCD_SendString("FAN OFF");
		HDCM_enStop();
		HLCD_gotoXY(1, 13);
		HLCD_SendString(" ");

	}
}
void AC_OFF(void) {
	HDCM_enStop();

}
