/************************************************/
/* Title       : LCD Interface file             */
/* Author      : Fatma Hesham                   */
/* Release     : 1.0                            */
/* Last Update : Aug 18, 2021                   */
/************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_


void LCD_vidInit(void);

void LCD_vidWriteCharacter(u8 u8_Character);

u8 LCD_u8_ReadCharacter();

void LCD_vidWriteCommand(u8 u8_Command);

u8 LCD_u8_ReadCommand();

void LCD_vidWriteString(u8 * Copy_pString);

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col );

void LCD_vidClearScreen(void);

void LCD_vid_Shift_Cursor_To_Left();

#endif /* LCD_INT_H_ */
