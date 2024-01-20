/*
 * ADC_int.h
 *
 *  Created on: Aug 23, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


#define ADMUX 	*((volatile u8*)(0x27)) 	// ADC Multiplexer Register
#define ADCSRA 	*((volatile u8*)(0x26)) 	// ADC Control And Status Register
#define ADCH	*((volatile u8*)(0x25))		// ADC High Register
#define ADCL 	*((volatile u8*)(0x24)) 		// ADC Low Register
#define SFIOR	*((volatile u8*))0x50)) 		// ADC Low Register
#define ADC_Reg  *((volatile u16*)0x24) 		// ADC all Register

#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#define ACME 3
#define PUD 2
#define PSR2 1
#define PSR10 0


#define Channel_A0 0
#define Channel_A1 1
#define Channel_A2 2
#define Channel_A3 3
#define Channel_A4 4
#define Channel_A5 5
#define Channel_A6 6
#define Channel_A7 7


#define EREF         0
#define AVCC         1
#define internal     3

#define prescaller2   0
#define prescaller4   1
#define prescaller8   2
#define prescaller16  3
#define prescaller32  4
#define prescaller128 5

void ADC_Init (u8 volt_ref,u8 prescaller);// ADC Initialization And Enable
u16 ADC_Read (u8 Channel); // Read From The ADC Channel
f32 ADC_VOLT(u8 channel);
f32 ADC_TEMP(u8 channel);


void ADC_SETCALL_BACK(void(*ptr)(void));


#endif /* MCAL_ADC_ADC_INT_H_ */
