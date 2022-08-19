/************************************************/
/* Title       : LCD Private file               */
/* Author      : Fatma Hesham                   */
/* Release     : 1.0                            */
/* Last Update : Aug 18, 2021                   */
/************************************************/
#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define LCD_Matrix_2Lines_5x7_Matrix          0b00111000 // 2 lines and 5x7 matrix
#define LCD_Display_On_Cursor_Blinking        0b00001110 // Display on, cursor blinking
#define LCD_Display_On_Cursor_not_Blinking    0b00001100 // Display on, cursor is not blinking
#define LCD_Shift_Cursor_To_Right      0x14
#define LCD_Shift_Cursor_To_Left       0x10
#define LCD_Clear_Screen               0x01
#define LCD_Cursor_In_1st_Line_Begin   0x80
#define LCD_Cursor_In_2nd_Line_Begin   0xC0

#define LCD_u8_4BitMode     0
#define LCD_u8_8BitMode     1


#endif /* LCD_PRIV_H_ */
