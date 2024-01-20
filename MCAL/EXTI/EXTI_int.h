/*
 * ENTI_int.h
 *
 *  Created on: Aug 22, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define MCUCR   (*(volatile u8*)(0x55))
#define GIFR    (*(volatile u8*)(0x5A))
#define  GICR   (*(volatile u8*)(0x5B))
#define MCUCSR  (*(volatile u8*)(0x54))

#define ISC11 3    // INT1
#define ISC10 2    // INT1
#define ISC01 1    //INT 0
#define ISC00 0    // INT 0


#define ISC2 6      //INT 2


#define INT1 7
#define INT0 6
#define INT2 5





#define LOW_LEVEL       0
#define IOC             1 //interrupt on Change.
#define FALLING_EDGE    2
#define RISING_EDGE     3

#define EXTI0 0
#define EXTI1 1
#define EXTI2 2





void EXT_INTERRUPT_VID_ENABLE(u8 interrupt_number);
void EXT_INTERRUPT_VID_DISABLE(u8 interrupt_number);
void EXT_INTERRUPT_VID_SET_MODE(u8 interrupt_number , u8 mode);


//CALL BACK FUNCTION

void EXT0_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT1_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT2_VID_SET_CALL_BACK(void (*PTR)(void));



#endif /* MCAL_EXTI_EXTI_INT_H_ */
