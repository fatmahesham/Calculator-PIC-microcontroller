/***********************************************/
/*Title       : KeyPad configuration file      */
/*Author      : Fatma Hesham                   */
/*Release     : 1.0                            */
/*Last Update : Sep 9,2021                     */
/***********************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_

#define Keypad_Port_Dir DDRC
#define Keypad_Port_Out PORTD
#define Keypad_Port_In  PINC
#define N_Col 4
#define N_Row 4

#if(N_Col == 4)

u8 Keypad_4x4(u8 Num) {
	switch (Num) {
	case 0:
		return '7';
		break;
	case 1:
		return '8';
		break;
	case 2:
		return '9';
		break;
	case 3:
		return 0xFD;
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return 'x';
		break;
	case 8:
		return '1';
		break;
	case 9:
		return '2';
		break;
	case 10:
		return '3';
		break;
	case 11:
		return '-';
		break;
	case 12:
		return 'c';
		break;
	case 13:
		return '0';
		break;
	case 14:
		return '=';
		break;
	case 15:
		return '+';
		break;
	}
}
#endif

#endif /* KEYPAD_H_ */
