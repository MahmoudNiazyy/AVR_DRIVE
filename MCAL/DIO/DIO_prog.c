/*
 * DIO_prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_int.h"




void MDIO_vidSetPinDirection(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber, u8 cpy_u8PortDirection)
{
	//DDRs
	switch (cpy_u8PortDirection)
	{
		case OUTPUT: //set DDRs
		{
			switch(cpy_u8PortNumber)
			{
			  case PORT_A:	  {SET_BIT(DDRA, cpy_u8PinNumber); break;}

			  case PORT_B:    {SET_BIT(DDRB, cpy_u8PinNumber); break;}

			  case PORT_C:	  {SET_BIT(DDRC, cpy_u8PinNumber); break;}

			  case PORT_D:    {SET_BIT(DDRD, cpy_u8PinNumber); break;}

			  default:   	  {/* wrong port number*/ break;}
			}
			break;
		}
		case INPUT:
		{
			switch(cpy_u8PortNumber)
			{
			  case PORT_A:	  {CLEAR_BIT(DDRA,cpy_u8PinNumber); break;}

			  case PORT_B:    {CLEAR_BIT(DDRB,cpy_u8PinNumber); break;}

			  case PORT_C:    {CLEAR_BIT(DDRC,cpy_u8PinNumber); break;}

			  case PORT_D:	  {CLEAR_BIT(DDRD,cpy_u8PinNumber); break;}

			  default:		  {/* wrong port number*/ break;}
			}
			break;
		}
		default:	{/* wrong direction*/ break;}
	}
}
void MDIO_vidSetPinValue(u8 cpy_u8PortNumber, u8 cpy_u8PinNumber, u8 cpy_u8PinValue)
{
	// PORTs registers
	switch (cpy_u8PinValue)
	{
		case HIGH: //set
		{
			switch (cpy_u8PortNumber)
			{
				case PORT_A:	{SET_BIT(PORTA, cpy_u8PinNumber); break;}

				case PORT_B:	{SET_BIT(PORTB, cpy_u8PinNumber); break;}

				case PORT_C:	{SET_BIT(PORTC, cpy_u8PinNumber); break;}

				case PORT_D: 	{SET_BIT(PORTD, cpy_u8PinNumber); break;}

				default:		{/* wrong port number*/	break;}
			}
			break;
		}
		case LOW:
		{
			switch(cpy_u8PortNumber)
			{
			  case PORT_A:	  {CLEAR_BIT(PORTA,cpy_u8PinNumber); break;}

			  case PORT_B:	  {CLEAR_BIT(PORTB,cpy_u8PinNumber); break;}

			  case PORT_C:	  {CLEAR_BIT(PORTC,cpy_u8PinNumber); break;}

			  case PORT_D:    {CLEAR_BIT(PORTD,cpy_u8PinNumber); break;}

			  default:		  {/* wrong port number*/ break;}
			}
			break;
		}
		default:	{/*wrong value*/ break;}
	}
}


u8 MDIO_vidGetPinValue(u8 cpy_u8PortNumber, u8 cpy_u8PinNumber)
{
	u8 get=0;
	// PINs registers
	switch(cpy_u8PortNumber) // get bit
	{
		case PORT_A:	get = GET_BIT(PINA,cpy_u8PinNumber); break;

		case PORT_B:	get = GET_BIT(PINB,cpy_u8PinNumber); break;

		case PORT_C:	get = GET_BIT(PINC,cpy_u8PinNumber); break;

		case PORT_D:	get = GET_BIT(PIND,cpy_u8PinNumber); break;

		default:		/*wrong PORT Number*/ break;
	}
	return get ;
}


void MDIO_vidSetPortDirection(u8 cpy_u8PortNumber, u8 cpy_u8PortDirection)
{
	//DDRs
	switch(cpy_u8PortNumber)
	{
		case PORT_A:	{DDRA = cpy_u8PortDirection; break;}

		case PORT_B:	{DDRB = cpy_u8PortDirection; break;}

		case PORT_C:    {DDRC = cpy_u8PortDirection; break;}

		case PORT_D:	{DDRD = cpy_u8PortDirection; break;}

		default:    	{/* wrong port number */ break;}
	}

}

void MDIO_vidSetPortvalue(u8 cpy_u8PortNumber, u8 cpy_u8PortValue)
{
	//PORTs registers
	switch(cpy_u8PortNumber)
	{
		case PORT_A:    {PORTA = cpy_u8PortValue; break;}

		case PORT_B:	{PORTB = cpy_u8PortValue; break;}

		case PORT_C:	{PORTC = cpy_u8PortValue; break;}

		case PORT_D:	{PORTD = cpy_u8PortValue; break;}

		default:    	{/* wrong port number */ break;}
	}
}
void MDIO_vidGetPortValue(u8 cpy_u8PortNumber, u8* buf_u8PortValue)
{
	//PINs registers
	switch(cpy_u8PortNumber)
	{
		case PORT_A:    {*buf_u8PortValue = PINA; break;}

		case PORT_B:	{*buf_u8PortValue = PINB; break;}

		case PORT_C:	{*buf_u8PortValue = PINC; break;}

		case PORT_D:   	{*buf_u8PortValue = PIND; break;}

		default:	{/* wrong port number */ break;}
	}
}
