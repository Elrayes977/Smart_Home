/*
 * MEXIT_priv.h
 *
 *  Created on: Jun 7, 2023
 *      Author: elray
 */

#ifndef MEXIT_MEXIT_PRIV_H_
#define MEXIT_MEXIT_PRIV_H_

#define MCUCR_REG   (*((volatile u8*)0x55)) //ISC INT0,INT1
#define MCUCSR_REG  (*((volatile u8*)0x54))//ISC INT2
#define GICR_REG 	(*((volatile u8*)0x5B))//PIEs=SPECIAL KEYS
#define GIFR_REG 	(*((volatile u8*)0x5A))//PIFs=flags

//MCUCR_REG
//ISC11 ISC10 ISC01 ISC00
#define ISC11_BIT 0
#define ISC10_BIT 1
#define ISC01_BIT 2
#define ISC00_BIT 3
//MCUCSR_REG
#define ISC2_BIT 6
//GICR
#define INT2 5
#define INT0 6
#define INT1 7

#define INT1_SC_MASK	0b11110011
#define INT1_SC_SH 2

#define INT0_SC_MASK  0b11111100

#endif /* MEXIT_MEXIT_PRIV_H_ */
