/*
 * motor_int.h
 *
 *  Created on: Aug 21, 2023
 *      Author: WIN 10 PRO
 */

#ifndef HAL_MOTOR_MOTOR_INT_H_
#define HAL_MOTOR_MOTOR_INT_H_


#define STEPPER_PORT PORT_A
#define BLUE      PIN_0
#define PINK      PIN_1
#define YELLOW    PIN_2
#define ORANGE    PIN_3






void MOTOR_Init(void);


void MOTOR_Stop(void);

void MOTOR_CW(void);

void MOTOR_CCW(void);




#endif /* HAL_MOTOR_MOTOR_INT_H_ */
