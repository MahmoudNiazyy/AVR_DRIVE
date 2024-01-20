/*
 * WDT.c
 *
 *  Created on: Aug 28, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "WDT_init.h"




void WDT_Set(TimeOut_type time)
{

	WDTCR = (WDTCR&0XF8)|time ;

	SET_BIT(WDTCR,3);
}
void WDT_Stop(void)
{

	WDTCR=0b00011000;

	WDTCR=0;
}
