/*
 * MSPI_priv.h
 *
 *  Created on: Jun 19, 2023
 *      Author: AA
 */

#ifndef MSPI_MSPI_PRIV_H_
#define MSPI_MSPI_PRIV_H_

//#define DDRB_REG	(*(volatile * u8)0x37)
#define SPDR_REG	*((volatile u8*)0x2F)
#define SPCR_REG	*((volatile u8*)0x2D)
#define SPSR_REG	*((volatile u8*)0x2E)

// for SPCR Bits
#define SPR0_BIT	0	//SPI Clock Rate
#define SPR1_BIT	1	//SPI Clock Rate
#define CPHA_BIT	2	//SPI Clock Phase
#define CPOL_BIT	3	//SPI Clock Polarity
#define MSTR_BIT	4	//Master/Slave Select
#define DORD_BIT	5	//Data Order (LSB or MSB)
#define SPE_BIT		6	//SPI Enable
#define SPIE_BIT	7	//SPI Interrupt Enable


// for SPSR Bits
#define SPI2X_BIT	0	//Double SPI Speed Bit
						//Bit 5..1 – Reserved Bits
#define WCOL_BIT	6	//Write COLlision Flag
#define SPIF_BIT	7	//SPI Interrupt Flag



#endif /* MSPI_MSPI_PRIV_H_ */
