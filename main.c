/***********************************************/
/*Title       : main function                  */
/*Author      : Fatma Hesham                   */
/*Release     : 1.0                            */
/*Last Update : Sep 11,2021                    */
/***********************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KeyPad_int.h"
#include <util/delay.h>

int main()
{
	DIO_vid_Init();
	LCD_vidInit();

	LCD_vidWriteString("     Hello!     ");
	_delay_ms(10);
	LCD_vidClearScreen();

	while(1)
	{
		Keypad_GetPressedKey();

	} //super loop

	return 0;
}
