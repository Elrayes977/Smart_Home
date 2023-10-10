/*
 * MSPI_prg.c
 *
 *  Created on: Jun 19, 2023
 *      Author: AA
 */
#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "MSPI_priv.h"
#include "MSPI_config.h"
#include "MSPI_int.h"

#include "avr/io.h"


ErrorState_t MSPI_enSPI_MasterInit(void)
{
	ErrorState_t Local_State = SUCCES;

	// Set MOSI and SCK output, all others input
	DDRB |= (1<<MOSI)| (1<<SCK)|(1<<SELECTOR);
	// Enable SPI, Master, set clock rate fck/16
	SPCR_REG |= (1<<SPE_BIT)|(1<<MSTR_BIT)|(1<<SPR0_BIT);


	// congiger the pins as Output
	/*MDIO_SetPinDirection(SELECTOR, OUTPUT);
	MDIO_SetPinDirection(MOSI, OUTPUT);
	MDIO_SetPinDirection(SCK, OUTPUT);

	// configer the bits in SPCR
	SET_BIT(SPCR_REG , SPE_BIT);	//Enable SPI
	SET_BIT(SPCR_REG , MSTR_BIT);	//SELECT MASTER
	SPCR_REG |= CLOCK_SELECT;		//SELECT CLOCK (from congfig)*/

	return Local_State;
}

ErrorState_t MSPI_enMasterTransmit(u8 copy_u8Data , u8 * ptru8RetData)
{
	ErrorState_t Local_State = SUCCES;
	//Start transmission
	SPDR_REG = copy_u8Data;
	// Wait for transmission complete
	while(!(SPSR_REG & (1<<SPIF_BIT)));
	*ptru8RetData = SPDR_REG;
	return Local_State;
}

ErrorState_t MSPI_enSPI_SlaveInit(void)
{
	ErrorState_t Local_State = SUCCES;

	// congiger the pins as Output
	MDIO_SetPinDirection(MISO, OUTPUT);

	// configer the bits in SPCR
	SET_BIT(SPCR_REG , SPE_BIT);	//Enable SPI

	return Local_State;
}

ErrorState_t MSPI_enSlaveReceive( u8 * ptru8RetData)
{
	ErrorState_t Local_State = SUCCES;

	if(SPDR_REG == 'A')
	{
		SPDR_REG = 'C';
	}

	/* Wait for reception complete */
	while(!(SPSR_REG & (1<<SPIF_BIT)));

	/* Return data register */
	*ptru8RetData =  SPDR_REG;

	return Local_State;
}
