/*
 * MUART_prg.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Elrayes
 */
#include "avr/interrupt.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"

#include "MUART_priv.h"
#include "MUART_config.h"
#include "MUART_int.h"
/*************callback****************/
static void (*UART_TX_PtrF)(void)=NULL;
static void (*UART_RX_PtrF)(void)=NULL;
static void (*UART_DataReg_PtrF)(void)=NULL;
/************global variables*********/

//#include "HLCD_init.h"
ErrorState_t MUART_enInit(void)
{
	ErrorState_t Local_enState=SUCCES;
u8 Local_UCSRC_value=0x80;
	//set buad rate
UBRRH_REG=(u8)(UART_BAUD_RATE>>8);
UBRRL_REG=(u8)UART_BAUD_RATE;
//Set RX
SET_BIT(UCSRB_REG,RXEN_BIT);
//set TX
SET_BIT(UCSRB_REG,TXEN_BIT);

CLR_BIT(UCSRA_REG,U2X_BIT);

//UCSRC_REG=0;

//Set mode
//SET_BIT(UCSRC_REG,URSEL_BIT);//to active USCRC reg
//CLR_BIT(UCSRC_REG,UMSEL_BIT);//Asynch UART


//parity mode
Local_UCSRC_value&=UART_PARITY_MASK;
Local_UCSRC_value|=UART_PARITY_BIT<<UPM0_BIT;
//Stop bits mode
//WRITE_BIT(UCSRC_REG,USBS_BIT,UART_STOP_BIT);
Local_UCSRC_value&=UART_STOP_BIT_MASK;
Local_UCSRC_value|=(UART_STOP_BIT<<USBS_BIT);
//data bits size
Local_UCSRC_value&=UART_CHARACTER_SIZE_MASK;
Local_UCSRC_value|=(UART_CHARACTER_SIZE<<UCSZ0_BIT);
//WRITE_BIT(UCSRC_REG,UCSZ0_BIT,1);
//WRITE_BIT(UCSRC_REG,UCSZ1_BIT,1);
//max 8 data bits for 9 data bits you should set UCSZ2 in reg UCSRB

UCSRC_REG=Local_UCSRC_value;
	/* Set baud rate */
//	UBRRH_REG = (unsigned char)(UART_BAUD_RATE>>8);
	//UBRRL_REG = (unsigned char)UART_BAUD_RATE;
	/* Enable receiver and transmitter */
//	UCSRB_REG = (1<<RXEN_BIT)|(1<<TXEN_BIT);
	/* Set frame format: 8data, 2stop bit */
//UCSRC_REG = (1<<URSEL_BIT)|(1<<USBS_BIT)|(3<<UCSZ0_BIT);
/***********************/
//HLCD_gotoXY(1, 1);
//HLCD_SendString("HIIII");
//HLCD_sendIntNum(UART_PARITY_BIT<<UPM0_BIT);
//HLCD_gotoXY(2, 1);
//HLCD_sendIntNum(UCSRC_REG);
/**********************/

return Local_enState;
}
ErrorState_t MUART_enSendByteSync(u8 Copy_u8Data)
{
	ErrorState_t Local_enState=SUCCES;

	/*wait for empty reg buffer */
	while(!(GET_BIT(UCSRA_REG,UDRE_BIT)));
	/*Send Data to data register */
	UDR_REG=Copy_u8Data;
	//while(!(GET_BIT(UCSRA_REG,TXC_BIT)));


	/* Wait for empty transmit buffer */
//	while ( !( UCSRA_REG & (1<<UDRE_BIT)) )	;
	/* Put data into buffer, sends the data */
	//UDR_REG = Copy_u8Data;
	return Local_enState;

}
ErrorState_t MUART_enReciveByteSync(u8 * ptrCopyData)
{
	ErrorState_t Local_enState=SUCCES;
	/*wait for reciving coplete */
	//if(ptrCopyData!=NULL){
	while(!(GET_BIT(UCSRA_REG,RXC_BIT)));
		/* RECIVED*/
		*ptrCopyData=UDR_REG;
	//while ( !(UCSRA_REG & (1<<RXCIE_BIT)) );
	//*ptrCopyData=UDR_REG;
	//UDR_REG=0;
	//}
	//else{
		//Local_enState=NULL_PTR_ERR;
		//}
		return Local_enState;
}
ErrorState_t MUART_enSendStringSync(char * str)
{ErrorState_t Local_enState=SUCCES;
	for(u8 Local_index=0;str[Local_index];Local_index++)
	{
		MUART_enSendByteSync(str[Local_index]);
	}

	return Local_enState;

}

ErrorState_t MUART_enReciveStringSync(char * str)
{ErrorState_t Local_enState=SUCCES;

u8 Local_index;
	for(Local_index=0;str[Local_index-1]!='#';Local_index++)
	{
		MUART_enReciveByteSync((u8 *)&str[Local_index]);
	}

	str[Local_index-1]='\0';
	return Local_enState;

}

ErrorState_t UART_SendNoBlock(u8  Copy_u8Data)
{
	ErrorState_t Local_enState=SUCCES;


		UDR_REG=Copy_u8Data;



		return Local_enState;


}

ErrorState_t UART_ReceiveNoBlock(u8 * ptrCopyData)
{
	ErrorState_t Local_enState=SUCCES;

	*ptrCopyData=UDR_REG;
	return Local_enState;
}


/*********interrupts*********/

ErrorState_t MUART_enDataReg_EmptyInt_Enable(void)
{
	ErrorState_t Local_enState=SUCCES;



SET_BIT(UCSRB_REG,UDRIE_BIT);
return Local_enState;

}

ErrorState_t MUART_enDataReg_EmptyInt_Disable(void)
{ErrorState_t Local_enState=SUCCES;



CLR_BIT(UCSRB_REG,UDRIE_BIT);
return Local_enState;

}



ErrorState_t MUART_enTx_interruptENable(void)
{
		ErrorState_t Local_enState=SUCCES;


		SET_BIT(UCSRB_REG,TXCIE_BIT);

		return Local_enState;

}

ErrorState_t MUART_enTx_interruptDisable(void)
{
			ErrorState_t Local_enState=SUCCES;


			CLR_BIT(UCSRB_REG,TXCIE_BIT);
			return Local_enState;

}

ErrorState_t MUART_enRx_interruptENable(void)
{
			ErrorState_t Local_enState=SUCCES;

			SET_BIT(UCSRB_REG,RXCIE_BIT);

			return Local_enState;

}



ErrorState_t MUART_enRx_interruptDisable(void)
{
			ErrorState_t Local_enState=SUCCES;


			CLR_BIT(UCSRB_REG,RXCIE_BIT);
			return Local_enState;

}


ErrorState_t MUART_TX_Setcallback(void (*copy_ptrf)(void))
{
	ErrorState_t Local_enState=SUCCES;
	if(copy_ptrf!=NULL)
	{
	UART_TX_PtrF=copy_ptrf;
	}
	else
	{
		Local_enState=NULL_PTR_ERR;
	}

	return Local_enState;
}


ErrorState_t MUART_RX_Setcallback(void (*copy_ptrf)(void))
{
	ErrorState_t Local_enState=SUCCES;
	if(copy_ptrf!=NULL)
	{
	UART_RX_PtrF=copy_ptrf;
	}
	else
	{
		Local_enState=NULL_PTR_ERR;
	}

	return Local_enState;
}

ErrorState_t MUART_Datareg_Setcallback(void (*copy_ptrf)(void))
{
	ErrorState_t Local_enState=SUCCES;
	if(copy_ptrf!=NULL)
	{
		UART_DataReg_PtrF=copy_ptrf;
	}
	else
	{
		Local_enState=NULL_PTR_ERR;
	}

	return Local_enState;
}

ISR(USART_RXC_vect)
{
	if(UART_RX_PtrF!=NULL){

		UART_RX_PtrF();
	}


}


ISR(USART_UDRE_vect)
{

	if(UART_DataReg_PtrF!=NULL)
	{
		UART_DataReg_PtrF();
	}

}
ISR(USART_TXC_vect)
{
	if(UART_TX_PtrF!=NULL){

		UART_TX_PtrF();

	}

}
