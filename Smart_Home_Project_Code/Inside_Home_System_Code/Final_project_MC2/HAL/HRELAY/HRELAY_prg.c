/*
 * HRELAY_prg.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Elrayes
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "HRELAY_config.h"
#include "HRELAY_int.h"
#include "MDIO_int.h"

ErrorState_t HRELAY_enInit(void)
{
MDIO_SetPinDirection(HRELAY_PIN,OUTPUT);
return SUCCES;
}
ErrorState_t HRELAY_enOn(void)
{
MDIO_voidSetPinValue(HRELAY_PIN, HIGH);
	return SUCCES;
}
ErrorState_t HRELAY_enOFF(void)
{
	MDIO_voidSetPinValue(HRELAY_PIN, LOW);
	return SUCCES;
}
ErrorState_t HRELAY_enToggle(void)
{
MDIO_voidTogglePinValue(HRELAY_PIN);
	return SUCCES;
}
