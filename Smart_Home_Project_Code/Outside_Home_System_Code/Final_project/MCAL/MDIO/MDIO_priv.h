/*
 * MDIO_priv.h
 *
 *  Created on: May 28, 2023
 *      Author: Elrayes
 */

#ifndef MDIO_MDIO_PRIV_H_
#define MDIO_MDIO_PRIV_H_

#define PRTA_REG *((volatile u8*)0x3B)
#define DDRA_REG *((volatile u8*)0x3A)
#define PINA_REG *((volatile u8*)0x39)


#define PRTB_REG *((volatile u8*)0x38)
#define DDRB_REG *((volatile u8*)0x37)
#define PINB_REG *((volatile u8*)0x36)


#define PRTC_REG *((volatile u8*)0x35)
#define DDRC_REG *((volatile u8*)0x34)
#define PINC_REG *((volatile u8*)0x33)


#define PRTD_REG *((volatile u8*)0x32)
#define DDRD_REG *((volatile u8*)0x31)
#define PIND_REG *((volatile u8*)0x30)


#endif /* MDIO_MDIO_PRIV_H_ */
