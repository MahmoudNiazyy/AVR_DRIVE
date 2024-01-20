/*
 * ADC.c
 *
 *  Created on: Aug 23, 2023
 *      Author: WIN 10 PRO
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "../GLOBAL_INIT/GLOBAL_int.h"
#include "ADC_int.h"
#include <avr/io.h>

void (*ADC_CALLBACK)(void)=NULL;



void ADC_Init (u8 volt_ref,u8 prescaller)
{
	//volt ref.
	switch (volt_ref) {
	case EREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);

		break;
	case AVCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);

		break;
	case internal:
	    SET_BIT(ADMUX,REFS0);
	     SET_BIT(ADMUX,REFS1);

	break;

	default:
		break;
	}
	//data direction
     CLEAR_BIT(ADMUX,ADLAR);

	//prescaller
      switch(prescaller)
      {
      case prescaller2:
    	  CLEAR_BIT(ADCSRA,ADPS0);
    	  CLEAR_BIT(ADCSRA,ADPS1);
    	  CLEAR_BIT(ADCSRA,ADPS2);
    	  break;
      case prescaller4:
          	  CLEAR_BIT(ADCSRA,ADPS0);
          	  SET_BIT(ADCSRA,ADPS1);
          	  CLEAR_BIT(ADCSRA,ADPS2);
          	  break;
      case prescaller8:
    	  SET_BIT(ADCSRA,ADPS0);
          SET_BIT(ADCSRA,ADPS1);
          CLEAR_BIT(ADCSRA,ADPS2);
          break;
      case prescaller128:
         	  SET_BIT(ADCSRA,ADPS0);
              SET_BIT(ADCSRA,ADPS1);
              SET_BIT(ADCSRA,ADPS2);
              break;

      }

	//adc enable
      SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read (u8 Channel)//00000010
{
	//SELECT CHANNEL
	ADMUX=ADMUX&0b11100000;
	ADMUX=ADMUX|Channel;   //11100000|00000001=11100001

	// START CON.
	 SET_BIT(ADCSRA,ADSC);
	//WAITE
	 while(!GET_BIT(ADCSRA,ADIF)){}
	 //clear flag
	   SET_BIT(ADCSRA,ADIF);
	//RETURN
	   return ADC_Reg;
}



f32 ADC_VOLT(u8 channel)  //v/vref = adc/1024>> v=(adc*vref)/1024
{
   f32 num;
   f32  volt;
   num= ADC_Read(channel);
   volt= (num*5)/1024;
   return volt;

}

f32 ADC_TEMP(u8 channel)
{   f32 num;
f32  temp;
    num=ADC_VOLT(channel);   //volt*1000/10>>>>>volt *100
    temp= (num*100);

    return  temp;
}



void ADC_SETCALL_BACK(void(*ptr)(void))
{
	ADC_CALLBACK=ptr;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_16 (void){
	ADC_CALLBACK();
}
