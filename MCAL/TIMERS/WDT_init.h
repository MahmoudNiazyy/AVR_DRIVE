/*
 * WDT_init.h
 *
 *  Created on: Aug 28, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_TIMERS_WDT_INIT_H_
#define MCAL_TIMERS_WDT_INIT_H_

#define WDTOE  4
#define WDE   3
#define WDP2  2
#define WDP1  1
#define WDP0  0

#define WDTCR *((volatile u8*)(0x41))
typedef enum{
	timeout_16ms=0,
	timeout_32ms,
	timeout_65ms,
	timeout_130ms,
	timeout_260ms,
	timeout_520ms,
	timeout_1000ms,
	timeout_2100ms,
}TimeOut_type;


void WDT_Set(TimeOut_type time);
void WDT_Stop(void);


#endif /* MCAL_TIMERS_WDT_INIT_H_ */
