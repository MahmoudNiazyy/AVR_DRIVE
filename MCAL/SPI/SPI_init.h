/*
 * SPI_init.h
 *
 *  Created on: Aug 30, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_
/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0




typedef enum{
	SLAVE,
	MASTER


	}SPI_Mode_type;


void SPI_Init(SPI_Mode_type mode);

u8 SPI_SendReceive(u8 data);
void SPI_MasterTransmit(char cData);


#endif /* MCAL_SPI_SPI_INIT_H_ */
