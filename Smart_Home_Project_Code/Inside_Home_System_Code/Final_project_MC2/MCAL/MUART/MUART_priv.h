/*
 * MUART_priv.h
 *
 *  Created on: Jul 6, 2023
 *      Author: Elrayes
 */

#ifndef MUART_MUART_PRIV_H_
#define MUART_MUART_PRIV_H_


#define UCSRA_REG   (*((volatile u8 *)0x2B))  // control A
#define UCSRB_REG   (*((volatile u8 *)0x2A))  // control B
#define UCSRC_REG   (*((volatile u8 *)0x40))  // control C
#define UDR_REG     (*((volatile u8 *)0x2C))  // data register
#define UBRRH_REG   (*((volatile u8 *)0x40))  // BR high
#define UBRRL_REG   (*((volatile u8 *)0x29))   // BR low

//UCSRC_REG

#define URSEL_BIT     7  // register select
#define UMSEL_BIT     6  // UART mode select
#define UPM1_BIT      5  // parity bit
#define UPM0_BIT      4  // parity bit
#define USBS_BIT      3  // stop bit
#define UCSZ1_BIT     2  // msg size
#define UCSZ0_BIT     1  // msg size
#define UCPOL_BIT     0  // clock polarity in synchrounse mode

//UCSRA_REG

#define RXC_BIT     7   // RX complete flag
#define TXC_BIT     6   // TX complete flag
#define UDRE_BIT    5   // data register empty
#define FE_BIT      4   // frame error
#define DOR_BIT     3   // data overrun error
#define PE_BIT      2   // parity error
#define U2X_BIT     1   // double speed mode
#define MPCM_BIT    0

//UCSRB_REG

#define  RXCIE_BIT  7   // RX complete Interrupt Enable
#define  TXCIE_BIT  6   // Tx complete Interrupt Enable
#define  UDRIE_BIT  5   // data register empty Interrupt Enable
#define  RXEN_BIT   4   // Enable Rx
#define  TXEN_BIT   3   // Enable Tx
#define  UCSZ2_BIT  2   // msg size
#define  RXB8_BIT   1   // bit8 in 9 bit mode (Rx)
#define  TXB8_BIT   0   // bit8 in 9 bit mode (Tx)

// character size
#define   UART_CHARACTER_SIZE_5   0
#define   UART_CHARACTER_SIZE_6   1
#define   UART_CHARACTER_SIZE_7   2
#define   UART_CHARACTER_SIZE_8   3

//parity bits
#define   UART_PARITY_BIT_NO_PARITY   0
#define   UART_PARITY_BIT_EVEN        2
#define   UART_PARITY_BIT_ODD         3

//stop bits
 #define   UART_STOP_BIT_1      0
 #define   UART_STOP_BIT_2      1

// Baud Rates
#define UART_BAUD_RATE_16MHZ_2400     416
#define UART_BAUD_RATE_16MHZ_9600     103
#define UART_BAUD_RATE_16MHZ_115200   8

#define UART_BAUD_RATE_8MHZ_2400     207
#define UART_BAUD_RATE_8MHZ_9600     51
#define UART_BAUD_RATE_8MHZ_115200   3
#define UART_BAUD_RATE_8MHZ_38400    12

#define UART_CHARACTER_SIZE_MASK  0b11111001
#define UART_CHARACTER_SIZE_SHIFT  1

#define UART_PARITY_MASK          0b11001111
#define UART_PARITY_SHIFT			4

#define UART_STOP_BIT_MASK        0b11110111

#endif /* MUART_MUART_PRIV_H_ */
