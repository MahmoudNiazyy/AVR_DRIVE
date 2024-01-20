/*
 * I2C.c
 *
 *  Created on: Sep 2, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "I2C_init.h"

void I2CInit(void)
{   // 400KHZ  >>> 72
	TWBR=10;

	CLEAR_BIT(TWCR,TWIE);

}
u8 TWISendStart_condition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return (TWSR & 0xF8);

}
u8 TWISendSlaveAddressRW(u8 copy_u8_Slave_address,u8 read_write)
{
	TWDR = copy_u8_Slave_address<<1;
	if(read_write == read)
	{
		SET_BIT(TWDR,0);
	}
	else if(read_write == write)
	{
		CLEAR_BIT(TWDR,0);
	}

	TWCR = (1<<TWINT) | (1<<TWEN);

	 CLEAR_BIT(TWCR,TWSTA);

	 while (!(TWCR & (1<<TWINT)));

	 return (TWSR & 0xF8);

}
u8 I2C_send_byte(u8 DATA)
{
	TWDR = DATA;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));   //while(!GET_BIT(TWCR,TWINT));
	 return (TWSR & 0xF8);
}
u8 I2C_StopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	 return (TWSR & 0xF8);
}
u8 I2C_Get_status(void)
{
	 return (TWSR & 0xF8);
}


u8 I2C_reciveByte(u8 *byte , u8 ACK)//ACK OR NOT ACK
{
	if(ACK==ACK1)
	{
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	}

	if(ACK==NOT_ACK)
	{
		TWCR = (1<<TWINT)|(1<<TWEN);
		CLEAR_BIT(TWCR,TWEA);

	}

	while (!(TWCR & (1<<TWINT)));
	*byte=TWDR;

	 return (TWSR & 0xF8);

}
void I2C_reciveByte_ACK(u8 *byte)
{


	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	while (GET_BIT(TWCR,TWINT)==0);

	while ((TWSR & 0xF8)!=0x50);//check ACK
	*byte=TWDR;


}

