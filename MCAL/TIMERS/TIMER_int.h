/*
 * TIMER_int.h
 *
 *  Created on: Aug 25, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_TIMERS_TIMER_INT_H_
#define MCAL_TIMERS_TIMER_INT_H_

/* Timer 0 */
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TWCR    (*(volatile unsigned char*)0x56)
#define SPMCR   (*(volatile unsigned char*)0x57)
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define OCR0    (*(volatile unsigned char*)0x5C)
/****************************************************************************************************/

/*TIMER 1*/


#define ICR1         (*(volatile unsigned short*)0x46)
#define ICR1L     (*(volatile unsigned char*)0x46)
#define ICR1H     (*(volatile unsigned char*)0x47)
#define OCR1B     (*(volatile unsigned short*)0x48)
#define OCR1BL    (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)
#define OCR1A     (*(volatile unsigned short*)0x4A)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH      (*(volatile unsigned char*)0x4B)
#define TCNT1       (*(volatile unsigned short*)0x4C)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)
#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define TCCR1A        (*(volatile unsigned char*)0x4F)



#define OSCCAL       (*(volatile unsigned char*)0x51)
/******************************************************************************/
/* Timer 2 */

#define OCR2     (*(volatile unsigned char*)0x43)
#define TCNT2    (*(volatile unsigned char*)0x44)
#define TCCR2    (*(volatile unsigned char*)0x45)




/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

/* ASSR */
/* bits 7-4 reserved */
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* WDTCR */
#define WDTCR    (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0



















typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;


typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;

void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler);

void TIMER0_OC0Mode(OC0Mode_type mode);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OV_SetCallBack(void(*local_fptr)(void));
void TIMER0_OC_SetCallBack(void(*LocalFptr)(void));

/******************************TIMER1***************************************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;


typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;





void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler);
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);

void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);

void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);

void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));


void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void servo_init(void);
void servo_angle(u8 angle);

#endif /* MCAL_TIMERS_TIMER_INT_H_ */
