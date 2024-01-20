/*
 * UART.c
 *
 *  Created on: Aug 29, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_init.h"
#include <avr/io.h>
#include "util/delay.h"

void UART_init(void)
{
	//cntrol ucsrc
		UCSRC=0b10000110;
		//B RATE
		UBRRL=51;
	// enable teasmit
		SET_BIT(UCSRB,TXEN);
		//enable recive
		SET_BIT(UCSRB,RXEN);

}
void UART_sendchar(u8 data)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=data;
}

void UART_sendstring(u8 *str)
{    u8 i=0;
	while(str[i])
	{
		UART_sendchar(str[i]);
				i++;
	}
}
u8 UART_recievechar(void)
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}



void enable_uart_intrruprTx(void)
{
	SET_BIT(UCSRB,TXCIE);

}
void enable_uart_intrruprRx(void)
{
	SET_BIT(UCSRB,RXCIE);
}

