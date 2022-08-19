/************************************************/
/* Title       : LCD Program file               */
/* Author      : Fatma Hesham                   */
/* Release     : 1.0                            */
/* Last Update : Aug 18, 2021                   */
/************************************************/

#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_priv.h"

#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"


void LCD_vidInit(void)
{
	_delay_ms(35);
	LCD_vidWriteCommand(LCD_Matrix_2Lines_5x7_Matrix);
	_delay_ms(1);
	LCD_vidWriteCommand(LCD_Display_On_Cursor_Blinking);
	_delay_ms(1);
	LCD_vidWriteCommand(LCD_Clear_Screen);
	_delay_ms(2);
	LCD_vidWriteCommand(LCD_Shift_Cursor_To_Right);
	_delay_ms(1);

#if LCD_MODE == LCD_u8_4BitMode
	LCD_vidWriteCommand(0x33);
	_delay_ms(2);
	LCD_vidWriteCommand(0x32);
	_delay_ms(2);
#endif

}

void LCD_vidWriteCharacter(u8 u8_Character)
{
	DIO_vid_SetPinValue(LCD_u8_PIN_RS,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_RW,DIO_u8_LOW);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_E,DIO_u8_HIGH);
	_delay_ms(1);
	LCD_u8_PORT = u8_Character;
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_E,DIO_u8_LOW);
	_delay_ms(1);
}

u8 LCD_u8_ReadCharacter()
{
	DIO_vid_SetPinValue(LCD_u8_PIN_RS,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_RW,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_E,DIO_u8_HIGH);
	_delay_ms(1);
	return LCD_u8_PORT;
}

void LCD_vidWriteCommand(u8 u8_Command)
{
	DIO_vid_SetPinValue(LCD_u8_PIN_RS,DIO_u8_LOW);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_RW,DIO_u8_LOW);
	_delay_ms(1);
	LCD_u8_PORT = u8_Command;
	DIO_vid_SetPinValue(LCD_u8_PIN_E,DIO_u8_HIGH);
	_delay_ms(1);
	LCD_u8_PORT = u8_Command;
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_E,DIO_u8_LOW);
	_delay_ms(1);

}

u8 LCD_u8_ReadCommand()
{
	DIO_vid_SetPinValue(LCD_u8_PIN_RS,DIO_u8_LOW);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_RW,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_vid_SetPinValue(LCD_u8_PIN_E,DIO_u8_HIGH);
	_delay_ms(1);
	return LCD_u8_PORT;
}

void LCD_vidWriteString(u8 * Copy_pString)
{
	int i=0;
	while( *(Copy_pString+i) != NULL)
	{
		LCD_vidWriteCharacter(*(Copy_pString+i));
        i++;

	}
}

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col )
{
	u8 Local_u8Address ;
		switch(Copy_u8Row)
		{
		case 0 :
			Local_u8Address = 0x00 + Copy_u8Col ; // first row address
			break ;
		case 1 :
			Local_u8Address = 0x40 + Copy_u8Col ; // second row address
			break ;
		}
		LCD_vidWriteCommand(0x80 | Local_u8Address ); // DDRAM address
}

void LCD_vidClearScreen(void)
{
	LCD_vidWriteCommand(LCD_Clear_Screen);
    _delay_ms(2);
}

void LCD_vid_Shift_Cursor_To_Left()
{
	LCD_vidWriteCommand(LCD_Shift_Cursor_To_Left);
    _delay_ms(1);
}

