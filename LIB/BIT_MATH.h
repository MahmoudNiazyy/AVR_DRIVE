/*
 * BIT_MATH.h
 *
 *  Created on: Jan 28, 2023
 *      Author: aminz
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR|=(1<<BITNO))
#define CLEAR_BIT(VAR,BITNO) (VAR&=(~(1<<BITNO)))
#define TOG_BIT(VAR,BITNO) (VAR^=(1<<BITNO))
#define GET_BIT(VAR,BITNO) ((VAR>>BITNO)&1)


#endif /* BIT_MATH_H_ */
