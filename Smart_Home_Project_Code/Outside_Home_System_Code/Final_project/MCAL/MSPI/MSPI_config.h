/*
 * MSPI_config.h
 *
 *  Created on: Jun 19, 2023
 *      Author: AA
 */

#ifndef MSPI_MSPI_CONFIG_H_
#define MSPI_MSPI_CONFIG_H_

// dfine pins
#define SELECTOR	PB4
#define MOSI		PB5
#define MISO		PB6
#define SCK			PB7

/*
 * Select the Clock Rate
 *
	osc/4		==> 0
	fosc/16		==> 1
	fosc/64		==> 2
	fosc/128	==> 3
 */

#define CLOCK_SELECT	1

#endif /* MSPI_MSPI_CONFIG_H_ */
