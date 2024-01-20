/*
 * SPI.c
 *
 *  Created on: Aug 30, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SPI_init.h"
#include <avr/io.h>
#include "util/delay.h"



void SPI_Init(SPI_Mode_type mode)
{
	if (mode==MASTER)
	{
		MDIO_vidSetPinDirection(PORT_B,PIN_4,OUTPUT);
		MDIO_vidSetPinDirection(PORT_B,PIN_5,OUTPUT);
		MDIO_vidSetPinDirection(PORT_B,PIN_6,INPUT);
		MDIO_vidSetPinDirection(PORT_B,PIN_7,OUTPUT);
		SET_BIT(SPCR,MSTR);
	}
	else
	{
		MDIO_vidSetPinDirection(PORT_B,PIN_4,INPUT);
		MDIO_vidSetPinDirection(PORT_B,PIN_5,INPUT);
		MDIO_vidSetPinDirection(PORT_B,PIN_6,OUTPUT);
		MDIO_vidSetPinDirection(PORT_B,PIN_7,INPUT);
		CLEAR_BIT(SPCR,MSTR);
	}



	// SPI ENABLE
	SET_BIT(SPCR,SPE);

}


u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_MasterTransmit(char cData)
{
/* Start transmission */
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
}

