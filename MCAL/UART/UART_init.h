/*
 * UART_init.h
 *
 *  Created on: Aug 29, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_UART_UART_INIT_H_
#define MCAL_UART_UART_INIT_H_


#define UDR 	*((volatile u8*)(0x2C))
#define UCSRA 	*((volatile u8*)(0x2B))
#define RXC    7
#define UDRE   5
#define UCSRB	*((volatile u8*)(0x2A))
#define RXCIE  7
#define TXCIE  6
#define UDRIE  5
#define RXEN   4
#define TXEN   3
#define UCSZ2  2
#define RXB8   1
#define TXB8   0
#define UCSRC 	*((volatile u8*)(0x40))
#define URSEL  7
#define UMSEL  6
#define UPM1   5
#define UPM0   4
#define USBS   3
#define UCSZ1  2
#define UCSZ0  1
#define UCPOL  0
#define UBRRH 	*((volatile u8*)(0x40))
#define UBRRL 	*((volatile u8*)(0x29))


void UART_init(void);
void UART_sendchar(u8 data);
void UART_sendstring(u8 *data);
u8 UART_recievechar(void);
void uart_SetCallBack(void(*LocalFptr)(void));
void enable_uart_intrrupr(void);



#endif /* MCAL_UART_UART_INIT_H_ */
