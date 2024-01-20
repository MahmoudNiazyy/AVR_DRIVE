/*
 * main.c

 *
 *  Created on: Aug 13, 2023
 *      Author: WIN 10 PRO
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/7-segment/segment_int.h"
#include "../HAL/keybad/keybad_int.h"

#include "../HAL/lcd/LCD_int.h"
#include "../HAL/motor/motor_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/GLOBAL_INIT/GLOBAL_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/TIMERS/TIMER_int.h"
#include "../MCAL/TIMERS/WDT_init.h"
#include "../MCAL/UART/UART_init.h"
#include "../MCAL/SPI/SPI_init.h"
#include "../MCAL/I2C/I2C_init.h"
#include "../MCAL/RTOS/Kernel_interface.h"
#include <avr/io.h>
#include "util/delay.h"
#include <avr/interrupt.h>

volatile static u8 c=0;
void TASK1(void)
{
	TOG_BIT(PORTA,PIN_0);

}
void TASK2(void)
{

  c++;
	TOG_BIT(PORTA,PIN_1);
	if (c==10)
	{
		RTOS_voidSuspendTask(0);
	}
	if (c==20)
	{
		RTOS_voidResumeTask(0);
		c=0;
	}


}


int main(void)
{


	MDIO_vidSetPinDirection(PORT_A,PIN_0,OUTPUT);
	MDIO_vidSetPinDirection(PORT_A,PIN_1,OUTPUT);
	RTOS_u8CreateTask(0,&TASK1,1000);
	RTOS_u8CreateTask(1,&TASK2,3000);

	RTOS_voidStart();




	while(1)
	{

	}
}
