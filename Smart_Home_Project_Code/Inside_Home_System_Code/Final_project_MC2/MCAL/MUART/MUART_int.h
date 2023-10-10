/*
 * MUART_int.h
 *
 *  Created on: Jul 6, 2023
 *      Author: Elrayes
 */

#ifndef MUART_MUART_INT_H_
#define MUART_MUART_INT_H_

ErrorState_t MUART_enInit(void);
ErrorState_t MUART_enSendByteSync(u8 Copy_u8Data);
ErrorState_t MUART_enReciveByteSync(u8 * ptrCopyData);
ErrorState_t MUART_enSendStringSync(char * str);
ErrorState_t MUART_enReciveStringSync(char * str);

ErrorState_t UART_SendNoBlock(u8 Copy_u8Data);

ErrorState_t UART_ReceiveNoBlock(u8 * ptrCopyData);


/*********interrupsts************/
ErrorState_t MUART_enDataReg_EmptyInt_Enable(void);

ErrorState_t MUART_enDataReg_EmptyInt_Disable(void);


ErrorState_t MUART_enTx_interruptENable(void);

ErrorState_t MUART_enTx_interruptDisable(void);

ErrorState_t MUART_enRx_interruptENable(void);



ErrorState_t MUART_enRx_interruptDisable(void);


ErrorState_t MUART_TX_Setcallback(void (*copy_ptrf)(void));

ErrorState_t MUART_RX_Setcallback(void (*copy_ptrf)(void));

ErrorState_t MUART_Datareg_Setcallback(void (*copy_ptrf)(void));

#endif /* MUART_MUART_INT_H_ */
