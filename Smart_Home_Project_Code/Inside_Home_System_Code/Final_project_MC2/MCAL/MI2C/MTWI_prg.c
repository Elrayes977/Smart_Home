/*
 * MTWI_prg.c
 *
 *  Created on: Jun 21, 2023
 *      Author: elray
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MTWI_priv.h"
#include "MTWI_config.h"
#include "MTWI_int.h"




ErrorState_t MTWI_enInit(void)
{
//cofig speed -> 400KHz (TWBR register, prescaler bits)
CLR_BIT(TWSR_REG,TWSP0_BIT);
CLR_BIT(TWSR_REG,TWSP1_BIT);

TWBR_REG=0x02;
//pre scaler = 1

//en twi turn on

SET_BIT(TWCR_REG,TWEN_BIT);

return SUCCES;
}

ErrorState_t MTWI_enSendStart(void)
{
//	STEP1: clear flag + set start bit + Enable TWI
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWSTA_BIT)|(1<<TWEN_BIT);
// step 2 : wait until operation starts
	//while(GET_BIT(TWCR_REG,TWINT_BIT)==0);
	while (!(TWCR_REG & (1<<TWINT_BIT)));  //GET BIT

	return SUCCES;
}

ErrorState_t MTWI_enSendStop(void)
{
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWSTO_BIT);
	return SUCCES;
}
ErrorState_t MTWI_enSendByte(u8 copy_u8Data)
{//load data into register
	TWDR_REG = copy_u8Data;
//clear flag + set Enable
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
	//wait
	//while(GET_BIT(TWCR_REG,TWINT_BIT)==0);
	while (!(TWCR_REG & (1<<TWINT_BIT)));  //GET BIT
	return SUCCES;
}
ErrorState_t MTWI_enRecByteAck(u8 *ptrRECdata)
{
	//clear flag + set Enable
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT)|(1<<TWEA_BIT);
	//while(GET_BIT(TWCR_REG,TWINT_BIT)==0);
	while (!(TWCR_REG & (1<<TWINT_BIT)));  //GET BIT
	//load data
	*ptrRECdata=TWDR_REG;

	return SUCCES;
}
ErrorState_t MTWI_enRecByteNoAck(u8 *ptrRECdata)
{


	//clear flag + set Enable
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
	//while(GET_BIT(TWCR_REG,TWINT_BIT)==0);
while (!(TWCR_REG & (1<<TWINT_BIT)));  //GET BIT
	//load data
	*ptrRECdata=TWDR_REG;
	return SUCCES;
}
ErrorState_t MTWI_enReadStatus(u8 * ptrStatusValue)
{
	//apply mask on status register
	* ptrStatusValue =TWSR_REG & MTWI_STATUS_MASK;
	return SUCCES;
}
