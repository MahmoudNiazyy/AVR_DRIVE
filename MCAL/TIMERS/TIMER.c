/*
- * TIMER.c
 *
 *  Created on: Aug 25, 2023
 *      Author: WIN 10 PRO
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_int.h"


/*************************Pointer to functions to be assigned to ISR*********************************/

 void (*Timer0_OVF_Fptr) (void)=NULL;
 void (*Timer0_OC_Fptr) (void)=NULL;
 void (*Timer1_OCA_Fptr) (void)=NULL;
 void (*Timer1_OCB_Fptr) (void)=NULL;
 void (*Timer1_ICU_Fptr) (void)=NULL;
/******************************************************************************************/
/*timer 0 functions*/
void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler)
{
	switch (mode)
	{
	case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
	case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
	case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	TCCR0&=0XF8;//0b11111000   TCCR0=TCCR0&0b11111000
	                           // ttcr0=ttcr0|scaler
	TCCR0|=scaler; // 0b11111000 |00000010 =11111010
}

void TIMER0_OC0Mode(OC0Mode_type mode)
{
	switch (mode)
	{
	case OC0_DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
	case OC0_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
	case OC0_NON_INVERTING:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	case OC0_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}

void TIMER0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_OV_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}
void TIMER0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_OC_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}
/*
void preload_Time0(u8 value)
{
	TCNT0=value;
}
void value_OCR0(u8 value)
{
	OCR0=value;
}

*/
/*************************************************************************/
/*timer 1 functions*/
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
	case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;


	case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;

	case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;


	case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}

	TCCR1B&=0XF8;//0b11111000
	TCCR1B|=scaler;

}
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
	case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
	case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
	case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
	case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
	case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
	case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
		SET_BIT(TCCR1B,ICES1);

	else if(edge==FALLING)
		CLEAR_BIT(TCCR1B,ICES1);
}


/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void TIMER0_OV_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OVF_Fptr=LocalFptr;
}

void TIMER0_OC_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OC_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/

void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void){

	if(Timer0_OVF_Fptr!=NULL)
	{
		Timer0_OVF_Fptr();

	}


}
void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void){

	if(Timer0_OC_Fptr!=NULL)
	{
		Timer0_OC_Fptr();

	}


}

void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_7 (void){

	if(Timer1_OCA_Fptr!=NULL)
	{
		Timer1_OCA_Fptr();

	}


}


void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_6 (void){

	if(Timer1_ICU_Fptr!=NULL)
	{
		Timer1_ICU_Fptr();

	}


}

/**************************************servo***************/
void servo_init(void)
{
	OCR1A=19999;
}
void servo_angle(u8 angle)//40   50  90   110
{
	OCR1B=999+(((u32)1000*angle)/180);
}

/*********************************/

                    //1 OR 2         ISR
void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void))
{
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER0_SCALER_8);
	OCR1A=(time*1000);   //1000-1=999ms;
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCA_InterruptEnable();
}


static u16 t1,t2,t3,flag=0;
void func(void)
{
    if(flag==0)
    {
    	t1=ICR1;
    	Timer1_InputCaptureEdge(FALLING);
    	flag=1;
    }
    else if(flag==1)
    {
    	t2=ICR1;
    	Timer1_InputCaptureEdge(RISING);
    	flag=2;
    }
    else  if (flag==2)
    {
    	t3=ICR1;
    	Timer1_ICU_InterruptDisable();
    	flag=3;
    }
  //  _delay_us(10);
}
void pwm_measure(u32 *freq,u8 *duty)
{
	u16 TON , TOFF;
	Timer1_ICU_SetCallBack(func);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3);

	TON=t2-t1;
	TOFF=t3-t2;
	*duty= ((u32)TON*100)/(u32)(TON+TOFF);
	*freq= (u32)1000000/(u32)(TON+TOFF);



}


