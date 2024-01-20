/*

 * EXTI.c
 *
 *  Created on: Aug 22, 2023
 *      Author: WIN 10 PRO
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GLOBAL_INIT/GLOBAL_int.h"

#include "EXTI_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>



void (*EXTI0_CALLBACK_PTR)(void)=NULL ;
void (*EXTI1_CALLBACK_PTR)(void)=NULL ;
void (*EXTI2_CALLBACK_PTR)(void)=NULL ;

void EXT_INTERRUPT_VID_ENABLE(u8 interrupt_number) //EXT0   EXT1  EXT2
{
	switch(interrupt_number)
	{
	case EXTI0:
		SET_BIT(GICR,INT0);
		break;
	case EXTI1:
		SET_BIT(GICR,INT1);
		break;
	case EXTI2:
		SET_BIT(GICR,INT2);
		break;
	}
}
void EXT_INTERRUPT_VID_DISABLE(u8 interrupt_number)
{
	switch(interrupt_number)
	{
	case EXTI0:
		CLEAR_BIT(GICR,INT0);
		break;
	case EXTI1:
		CLEAR_BIT(GICR,INT1);
		break;
	case EXTI2:
		CLEAR_BIT(GICR,INT2);
		break;
	}

}
//   EXT0         FALLING   LOW LEVEL
void EXT_INTERRUPT_VID_SET_MODE(u8 interrupt_number , u8 mode)
{
	switch(interrupt_number)
	{
	case EXTI0:
		switch(mode)
		{
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break;
		case IOC:
			CLEAR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
		}
		break;
		case EXTI1:
			switch(mode)
			{
			case LOW_LEVEL:
				CLEAR_BIT(MCUCR,ISC11);
				CLEAR_BIT(MCUCR,ISC10);
				break;
			case IOC:
				CLEAR_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			case FALLING_EDGE:
				SET_BIT(MCUCR,ISC11);
				CLEAR_BIT(MCUCR,ISC10);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			}

			break;
			case EXTI2:
				switch(mode)
				{
				case FALLING_EDGE:
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCSR,ISC2);
					break;
				}

				break;
	}
}



void EXT0_VID_SET_CALL_BACK(void (*PTR)(void))
{
	EXTI0_CALLBACK_PTR=PTR;
}
void EXT1_VID_SET_CALL_BACK(void (*PTR)(void))
{
	EXTI1_CALLBACK_PTR=PTR;
}
void EXT2_VID_SET_CALL_BACK(void (*PTR)(void))
{
	EXTI2_CALLBACK_PTR=PTR;
}









void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_1 (void){
	EXTI0_CALLBACK_PTR();
}

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_2 (void){
	EXTI1_CALLBACK_PTR();
}


void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_3 (void){
	EXTI2_CALLBACK_PTR();
}

