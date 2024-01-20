/*
 * GLOBAL_int.h
 *
 *  Created on: Aug 22, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_GLOBAL_INIT_GLOBAL_INT_H_
#define MCAL_GLOBAL_INIT_GLOBAL_INT_H_


#define SREG  (*(volatile u8*)0x5F)


#define I 7

void Global_Interrupt_Enable(void);
void Global_Interrupt_Disable(void);

#endif /* MCAL_GLOBAL_INIT_GLOBAL_INT_H_ */
