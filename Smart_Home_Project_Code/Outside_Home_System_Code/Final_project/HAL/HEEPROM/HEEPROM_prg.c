

#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "MTWI_int.h"
#include "HEEPROM_config.h"
#include "HEEPROM_int.h"

ErrorState_t HEEPROM_enInit(void)
{
	// init TWI
	MTWI_enInit();
	return SUCCES;
}

ErrorState_t HEEPROM_enWriteByte(u16 copy_u16Address, u8 copy_u8DByte)
{
	u8 Status;
	// Step 1 : Send Start
	MTWI_enSendStart();
	// Step 2 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_START_SUCCESS)
	{
		return FAILIUR;
	}

	// Step 3 : Send Address 1010 + A10 A9 A8 + W (W = 0)
//	u8 _3MSB = (u8)((copy_u16Address & 0x0700) >> 7);
	//MTWI_enSendByte(_3MSB| 0xA0);
MTWI_enSendByte(0xA0);
	// Step 4 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_SLA_W_ACK)
	{
		return FAILIUR;
	}

	// Step 5 : Send rest of Byte address as data A7 ... A0
	MTWI_enSendByte((u8) (copy_u16Address>>8));

	// Step 6 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}
	MTWI_enSendByte((u8) copy_u16Address);

	// Step 6 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}

	// Step 7 : Send Byte to be written
	MTWI_enSendByte((u8) copy_u8DByte);

	// Step 8 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}

	// Step 9 : Send Stop
	MTWI_enSendStop();

	return SUCCES;
}

ErrorState_t HEEPROM_enReadByte(u16 copy_u16Address, u8 *PtrRecData)
{
	u8 Status;
		// Step 1 : Send Start
		MTWI_enSendStart();
		// Step 2 : Check Status
		MTWI_enReadStatus(&Status);
		if(Status != MTWI_MT_START_SUCCESS)
		{
			return FAILIUR;
		}

		// Step 3 : Send Address 1010 + A10 A9 A8 + R/W
		//u8 _3MSB = (u8)((copy_u16Address & 0x0700) >> 7); //(W = 0)
		//MTWI_enSendByte(_3MSB| 0xA0);



		// Step 4 : Check Status
		MTWI_enSendByte(0xA0);
			// Step 4 : Check Status
			MTWI_enReadStatus(&Status);
			if(Status != MTWI_MT_SLA_W_ACK)
			{
				return FAILIUR;
			}

			// Step 5 : Send rest of Byte address as data A7 ... A0
			MTWI_enSendByte((u8) (copy_u16Address>>8));

			// Step 6 : Check Status
			MTWI_enReadStatus(&Status);
			if(Status != MTWI_MT_DATA_ACK)
			{
				return FAILIUR;
			}
			MTWI_enSendByte((u8) copy_u16Address);

		// Step 5 : Send rest of Byte address as data A7 ... A0
		MTWI_enSendByte((u8) copy_u16Address);

		// Step 6 : Check Status
		MTWI_enReadStatus(&Status);
		if(Status != MTWI_MT_DATA_ACK)
		{
			return FAILIUR;
		}
		//Step 7 : Send Repeated Start
		MTWI_enSendStart();

		// Step 8 : Check Status
		MTWI_enReadStatus(&Status);
		if(Status != MTWI_MR_REPEATED_START_SUCCESS)
		{
			return FAILIUR;
		}

		// Step 9 : Send Address 1010 + 000 + R
		MTWI_enSendByte(0xA0 | 0x01);

		// Step 10 : Check Status
		MTWI_enReadStatus(&Status);
		if(Status != MTWI_MR_SLA_R_ACK)
		{
			return FAILIUR;
		}

		//Step 11 : Read Data
		MTWI_enRecByteAck(PtrRecData);

		// Step 12 : Check Status
		MTWI_enReadStatus(&Status);
		if(Status != MTWI_MR_DATA_ACK)
		{
			return FAILIUR;
		}

		// Step 13 : Send Stop
		MTWI_enSendStop();
	return SUCCES;
}


#if 0

#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "MTWI_int.h"
#include "HEEPROM_config.h"
#include "HEEPROM_int.h"

ErrorState_t HEEPROM_enInit(void)
{
	// init TWI
	MTWI_enInit();
return SUCCES;
}

ErrorState_t HEEPROM_enWriteByte(u16 copy_u16Address, u8 copy_u8DByte)
{
	u8 Status;
	// Step 1 : Send Start
	MTWI_enSendStart();
	// Step 2 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_START_SUCCESS)
	{
		return FAILIUR;
	}

	// Step 3 : Send Address 1010 + A10 A9 A8 + W (W = 0)
	//u8 _3MSB = (u8)((copy_u16Address & 0x0700) >> 7);
	MTWI_enSendByte( 0xA0); // send to main register of eeptom 0x50 A0 & A1 &A2 = 0

	// Step 4 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_SLA_W_ACK)
	{
		return FAILIUR;
	}

	// Step 5 : Send rest of Byte address as data A7 ... A0

	MTWI_enSendByte(copy_u16Address>>8);
	// Step 6 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}
	MTWI_enSendByte((u8) copy_u16Address);

	// Step 6 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}

	// Step 7 : Send Byte to be written
	MTWI_enSendByte((u8) copy_u8DByte);

	// Step 8 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}

	// Step 9 : Send Stop
	MTWI_enSendStop();

	return SUCCES;
}

ErrorState_t HEEPROM_enReadByte(u16 copy_u16Address, u8 *PtrRecData)
{
	u8 Status;
	// Step 1 : Send Start
	MTWI_enSendStart();
	// Step 2 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_START_SUCCESS)
	{
		return FAILIUR;
	}

	// Step 3 : Send Address 1010 + A10 A9 A8 + R/W
	//u8 _3MSB = (u8)((copy_u16Address & 0x0700) >> 7); //(W = 0)
	MTWI_enSendByte(0xA0);

	// Step 4 : Check Status
	MTWI_enReadStatus(&Status);

	if(Status != MTWI_MT_SLA_W_ACK)
	{
		return FAILIUR;
	}

	// Step 5 : Send rest of Byte address as data A7 ... A0

	MTWI_enSendByte(copy_u16Address>>8);
	// Step 6 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}
	MTWI_enSendByte((u8) copy_u16Address);

	// Step 6 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MT_DATA_ACK)
	{
		return FAILIUR;
	}

	//Step 7 : Send Repeated Start
	MTWI_enSendStart();

	// Step 8 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MR_REPEATED_START_SUCCESS)
	{
		return FAILIUR;
	}

	// Step 9 : Send Address 1010 + 000 + R
	MTWI_enSendByte(0xA0 | 0x01);

	// Step 10 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MR_SLA_R_ACK)
	{
		return FAILIUR;
	}

	//Step 11 : Read Data
	MTWI_enRecByteAck(PtrRecData);

	// Step 12 : Check Status
	MTWI_enReadStatus(&Status);
	if(Status != MTWI_MR_DATA_ACK)
	{
		return FAILIUR;
	}

	// Step 13 : Send Stop
	MTWI_enSendStop();
	return SUCCES;
}
#endif
