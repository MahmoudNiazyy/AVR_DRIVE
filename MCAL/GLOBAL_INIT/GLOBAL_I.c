/*
 * GLOBAL_I.c
 *
 *  Created on: Aug 22, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GLOBAL_int.h"




void Global_Interrupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void Global_Interrupt_Disable(void)
{
	CLEAR_BIT(SREG,I);
}

