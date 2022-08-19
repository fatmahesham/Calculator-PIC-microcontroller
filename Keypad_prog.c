/***********************************************/
/*Title       : KEYPAD peripheral program file */
/*Author      : Fatma Hesham                   */
/*Release     : 1.0                            */
/*Last Update : Sep 9,2021                     */
/***********************************************/

#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_Types.h"

#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_priv.h"

#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"

#include "Keypad_config.h"
#include "Keypad_int.h"
#include "Keypad_priv.h"

#include "Calculator.h"

void Keypad_GetPressedKey()
{
	u8 Col, Row;
	while (1)
	{
		for (Col = 0; Col < N_Col; Col++)
		{
			SET_NIBBLE_HIGH(Keypad_Port_In ) ;
			SET_NIBBLE_LOW(Keypad_Port_In ) ;
			Keypad_Port_Out = ~(0b00000001 << Col);

			_delay_ms(0.65);

			for (Row = 0; Row < N_Row; Row++)
			{
				if (Bit_Is_Clear(Keypad_Port_In, Row))
				{
					u8 ch = Keypad_4x4(Row*4+Col);
					if(ch == 'c')
					{
						LCD_vid_Shift_Cursor_To_Left();
						LCD_vidWriteCharacter(0xFE);
						LCD_vid_Shift_Cursor_To_Left();
						Calculator_vid_Store_char(ch);
					}
					else if (ch == '=')
					{
						LCD_vidWriteCharacter(ch);
						Calculator_vid_Calc_Sol();
						Calculator_vid_Print_Sol_By_LCD();
					}
					else
					{
						LCD_vidWriteCharacter(ch);
						Calculator_vid_Store_char(ch);
					}
				}
				_delay_ms(0.65);
			}
		}
	}
}
