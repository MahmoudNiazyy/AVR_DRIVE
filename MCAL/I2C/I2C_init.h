/*
 * I2C_init.h
 *
 *  Created on: Sep 2, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_I2C_I2C_INIT_H_
#define MCAL_I2C_I2C_INIT_H_



#define TWCR *((volatile u8*)(0x56))
#define TWDR *((volatile u8*)(0x23))
#define TWAR *((volatile u8*)(0x22))
#define TWSR *((volatile u8*)(0x21))
#define TWBR *((volatile u8*)(0x20))

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0





/**********************************************************/

#define read 1
#define write 0

#define ACK1 1
#define NOT_ACK 0



void I2CInit(void);
u8 TWISendStart_condition(void);
u8 TWISendSlaveAddressRW(u8 copy_u8_Slave_address,u8 read_write);
u8 I2C_send_byte(u8 DATA);
u8 I2C_StopCondition(void);
u8 I2C_Get_status(void);
u8 I2C_reciveByte(u8 *byte , u8 ACK);
void I2C_reciveByte_ACK(u8 *byte);




#endif /* MCAL_I2C_I2C_INIT_H_ */
