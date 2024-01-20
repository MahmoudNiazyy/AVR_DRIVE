

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_


// name (*(u8*)0xadd)

/* register definition*/
#define PORTA	(*(volatile u8*)0x3B)
#define DDRA	(*(volatile u8*)0x3A)
#define PINA	(*(volatile u8*)0x39)

#define PORTB	(*(volatile u8*)0x38)
#define DDRB	(*(volatile u8*)0x37)
#define PINB	(*(volatile u8*)0x36)

#define PORTC	(*(volatile u8*)0x35)
#define DDRC	(*(volatile u8*)0x34)
#define PINC	(*(volatile u8*)0x33)

#define PORTD	(*(volatile u8*)0x32)
#define DDRD	(*(volatile u8*)0x31)
#define PIND	(*(volatile u8*)0x30)


#define OUTPUT	(u8)1
#define INPUT	(u8)0
#define INPUll	(u8)2


#define PORT_A	(u8)'A'
#define PORT_B	(u8)'B'
#define PORT_C	(u8)'C'
#define PORT_D	(u8)'D'

#define LOW		(u8)0
#define HIGH	(u8)1


#define PIN_0   0
#define PIN_1   1
#define PIN_2   2
#define PIN_3   3
#define PIN_4   4
#define PIN_5   5
#define PIN_6   6
#define PIN_7   7

// set pin direction	(out,in)
// set pin value		(high, low)
// get pin value		(high, low)

// port, pin, direction

void MDIO_vidSetPinDirection(u8 cpy_u8PortNumber, u8 cpy_u8PinNumber, u8 cpy_u8PortDirection);
void MDIO_vidSetPinValue(u8 cpy_u8PortNumber, u8 cpy_u8PinNumber, u8 cpy_u8PinValue);
u8 MDIO_vidGetPinValue(u8 cpy_u8PortNumber, u8 cpy_u8PinNumber);

/* set port direction*/
void MDIO_vidSetPortDirection(u8 cpy_u8PortNumber, u8 cpy_u8PortDirection);
void MDIO_vidSetPortvalue(u8 cpy_u8PortNumber, u8 cpy_u8PortValue);
void MDIO_vidGetPortValue(u8 cpy_u8PortNumber, u8* buf_u8PortValue);
#endif
