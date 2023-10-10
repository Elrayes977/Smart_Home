/*
 * MSPI_int.h
 *
 *  Created on: Jun 19, 2023
 *      Author: AA
 */

#ifndef MSPI_MSPI_INT_H_
#define MSPI_MSPI_INT_H_

ErrorState_t MSPI_enSPI_MasterInit(void);
ErrorState_t MSPI_enMasterTransmit(u8 copy_u8Data , u8 * ptru8RetData);
ErrorState_t MSPI_enSPI_SlaveInit(void);
ErrorState_t MSPI_enSlaveReceive( u8 * ptru8RetData);

#endif /* MSPI_MSPI_INT_H_ */
