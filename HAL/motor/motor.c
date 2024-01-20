/*
 * motor.c
 *
 *  Created on: Aug 21, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "motor_int.h"
#include "util/delay.h"

void MOTOR_Init(void)
{
	MDIO_vidSetPortDirection(STEPPER_PORT,0x0f);
}


void MOTOR_Stop(void)
{
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
}

void MOTOR_CW(void)
{
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,HIGH);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
	_delay_ms(500);
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,HIGH);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
	_delay_ms(500);
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,HIGH);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
	_delay_ms(500);
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,HIGH);
	_delay_ms(500);
}

void MOTOR_CCW(void)
{
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,HIGH);
	_delay_ms(500);
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,HIGH);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
	_delay_ms(500);
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,HIGH);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
	_delay_ms(500);
	MDIO_vidSetPinValue(STEPPER_PORT,BLUE,HIGH);
	MDIO_vidSetPinValue(STEPPER_PORT,PINK,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(STEPPER_PORT,ORANGE,LOW);
	_delay_ms(500);
}

