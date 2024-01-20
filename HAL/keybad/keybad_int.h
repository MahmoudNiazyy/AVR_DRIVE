/*
 * keybad_int.h
 *
 *  Created on: Aug 16, 2023
 *      Author: WIN 10 PRO
 */

#ifndef HAL_KEYBAD_KEYBAD_INT_H_
#define HAL_KEYBAD_KEYBAD_INT_H_



#define k_port   PORT_C
#define  NO_KEY   'T'

void keybad_inti(void);
u8 keybad_PressKey(void);



#endif /* HAL_KEYBAD_KEYBAD_INT_H_ */
