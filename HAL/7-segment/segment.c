/*
 * segment.c
 *
 *  Created on: Aug 15, 2023
 *      Author: WIN 10 PRO
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "segment_int.h"
#include <avr/io.h>


static const u8 ssd_num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void ssd_init(void)
{
	MDIO_vidSetPortDirection(ssd_port,0xff);
}
void ssd_display_num(u8 num)
{
	if(num<10)
	{
#if ssd_type==com_cathod
		MDIO_vidSetPortvalue(ssd_port,ssd_num[num]);
#elif ssd_type==com_anod
		MDIO_vidSetPortvalue(ssd_port,~ssd_num[num]);
#endif
	}
}
void ssd_turn_off(void)
{
#if ssd_type==com_cathod
	MDIO_vidSetPortvalue(ssd_port,0);
#elif ssd_type==com_anod
	MDIO_vidSetPortvalue(ssd_port,0xff);
#endif
}
