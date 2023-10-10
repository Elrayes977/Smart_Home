/*
 * MADC_priv.h
 *
 *  Created on: Jun 5, 2023
 *      Author: elray
 */

#ifndef MADC_MADC_PRIV_H_
#define MADC_MADC_PRIV_H_

#define	ADMUX_REG	(*((volatile u8*)0x27))
#define	ADCSRA_REG	(*((volatile u8*)0x26))
#define	ADCH_REG	(*((volatile u8*)0x25))
#define	ADCL_REG	(*((volatile u8*)0x24))

//ADMUX_REG
//REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0
#define MUX0  0
#define MUX1  1
#define	MUX2  2
#define	MUX3  3
#define	MUX4  4
#define	ADLAR 5
#define	REFS0 6
#define	REFS1 7
//ADCSRA_REG
//ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0

#define ADPS0  0
#define ADPS1  1
#define	ADPS2  2
#define	ADIE   3
#define	ADIF 	4
#define	ADATE 	5
#define	ADSC 	6
#define	ADEN 	7


//conversion modes
#define SINGLE_CONVERSION_MODE 0
#define FREE_RUNNING_MODE      1
#endif /* MADC_MADC_PRIV_H_ */
