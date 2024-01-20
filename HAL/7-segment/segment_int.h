/*
 * segment_int.h
 *
 *  Created on: Aug 15, 2023
 *      Author: WIN 10 PRO
 */

#ifndef HAL_7_SEGMENT_SEGMENT_INT_H_
#define HAL_7_SEGMENT_SEGMENT_INT_H_


#define com_cathod   1
#define com_anod     0


#define ssd_type com_anod
#define ssd_port  PORT_C


void ssd_init(void);
void ssd_display_num(u8 num);
void ssd_turn_off(void);
#endif /* HAL_7_SEGMENT_SEGMENT_INT_H_ */
