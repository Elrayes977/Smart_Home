/*
 * HBUZ_prg.c
 *
 *  Created on: May 31, 2023
 *      Author: elray
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "MDIO_int.h"
#include "ERROR_STATES.h"
#include "HBUZ_priv.h"
#include "HBUZ_config.h"
#include "HBUZ_init.h"

void HBUZ_voidInit(void)
{

	MDIO_SetPinDirection(HBUZ_PIN,OUTPUT);
}

ErrorState_t HBUZ_enOn(void)
{
ErrorState_t Local_State=SUCCES;
MDIO_voidSetPinValue(HBUZ_PIN, HIGH);
return Local_State;
}

ErrorState_t HBUZ_enOff(void)
{
ErrorState_t Local_State=SUCCES;
MDIO_voidSetPinValue(HBUZ_PIN, LOW);
return Local_State;
}

ErrorState_t HBUZ_enOnce(u64 copy_u64BuzzPeriod)
{ErrorState_t Local_State=SUCCES;
	MDIO_voidSetPinValue(HBUZ_PIN, HIGH);
	_delay_ms(copy_u64BuzzPeriod);
	MDIO_voidSetPinValue(HBUZ_PIN, LOW);
	_delay_ms(copy_u64BuzzPeriod);
	return Local_State;
}

ErrorState_t HBUZ_enTwice(u64 copy_u64BuzzPeriod)
{ErrorState_t Local_State=SUCCES;
	MDIO_voidSetPinValue(HBUZ_PIN, HIGH);
	_delay_ms(copy_u64BuzzPeriod);
	MDIO_voidSetPinValue(HBUZ_PIN, LOW);
	_delay_ms(100);
	MDIO_voidSetPinValue(HBUZ_PIN, HIGH);
	_delay_ms(copy_u64BuzzPeriod);
	MDIO_voidSetPinValue(HBUZ_PIN, LOW);
	_delay_ms(copy_u64BuzzPeriod);
	return Local_State;
}
