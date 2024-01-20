/*
 * LCD.h
 *
 *  Created on: Aug 19, 2023
 *      Author: WIN 10 PRO
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


#define lcd_ctrl_port  PORT_B
#define lcd_data_port  PORT_A
#define  lcd_rs_pin    PIN_1
#define  lcd_en_pin    PIN_2



void HCLCD_vidInit(void);
void HCLCD_vidSendCommand(u8 cpy_u8Command);
void HCLCD_vidSendData(u8 cpy_u8Data);
void HCLCD_vidInit_4bit(void);
void HCLCD_vidSenddata_4bit(u8 cpy_u8Command);
void HCLCD_vidSendString(const u8* add_pu8String);
void HCLCD_vidSendNumber(s32 cpy_u32Number);

void HCLCD_vidSendFloat(f64 cpy_f64Float);
void HCLCD_vidGoTo(u8 cpy_u8X, u8 cpy_u8Y);
void HCLCD_vidClear(void);
void HCLCD_vidSendSpecialChar(const u8* arr_u8Char, u8 cpy_u8BlockNumber);
void LCD_WriteBinary(u8 num);
#endif /* HAL_LCD_LCD_INT_H_ */
