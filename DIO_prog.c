//implementation of func used
/**********************************************/
/*Title       : DIO peripheral program file   */
/*Author      : Fatma Hesham                  */
/*Release     : 1.0                           */
/*Last Update : Aug 16,2021                   */
/**********************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_priv.h"

void DIO_vid_Init()
{
	DDRA = DIO_u8_PORTA_DIRECTION;
	DDRB = DIO_u8_PORTB_DIRECTION;
	DDRC = DIO_u8_PORTC_DIRECTION;
	DDRD = DIO_u8_PORTD_DIRECTION;
}

void DIO_vid_SetPinValue(u8 Copy_u8_PinNo,u8 Copy_u8_PinValue)
{
	if(Copy_u8_PinNo >= DIO_u8_PORTA_START && Copy_u8_PinNo <= DIO_u8_PORTA_END )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
			SET_BIT(PORTA,Copy_u8_PinNo);
		else if( Copy_u8_PinValue==DIO_u8_LOW)
			CLEAR_BIT(PORTA,Copy_u8_PinNo);
	}
	else if(Copy_u8_PinNo >= DIO_u8_PORTB_START && Copy_u8_PinNo <= DIO_u8_PORTB_END )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
			SET_BIT(PORTB,Copy_u8_PinNo - DIO_u8_PORT_A_SIZE);
		else if( Copy_u8_PinValue==DIO_u8_LOW)
			CLEAR_BIT(PORTB,Copy_u8_PinNo - DIO_u8_PORT_A_SIZE);
	}
	else if(Copy_u8_PinNo >= DIO_u8_PORTC_START && Copy_u8_PinNo <= DIO_u8_PORTC_END )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
			SET_BIT(PORTC,Copy_u8_PinNo - (DIO_u8_PORT_A_SIZE + DIO_u8_PORT_B_SIZE));
		else if( Copy_u8_PinValue==DIO_u8_LOW)
			CLEAR_BIT(PORTC,Copy_u8_PinNo - (DIO_u8_PORT_A_SIZE + DIO_u8_PORT_B_SIZE));
	}
	else if(Copy_u8_PinNo >= DIO_u8_PORTD_START && Copy_u8_PinNo <= DIO_u8_PORTD_END )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
			SET_BIT(PORTD,Copy_u8_PinNo - (DIO_u8_PORT_A_SIZE + DIO_u8_PORT_B_SIZE + DIO_u8_PORT_C_SIZE));
		else if( Copy_u8_PinValue==DIO_u8_LOW)
			CLEAR_BIT(PORTD,Copy_u8_PinNo - (DIO_u8_PORT_A_SIZE + DIO_u8_PORT_B_SIZE + DIO_u8_PORT_C_SIZE));
	}
	
	
}

void DIO_vid_SetPortValue(u8 u8_PORT_Name, u8 u8_PORT_Value)
{
	u8_PORT_Name = u8_PORT_Value;
}

u8 DIO_u8_GetPinValue(u8 Copy_u8_PinNo)
{
	if(Copy_u8_PinNo >= DIO_u8_PORTA_START && Copy_u8_PinNo <= DIO_u8_PORTA_END )
		{
		   return GET_BIT(PORTA,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinNo >= DIO_u8_PORTB_START && Copy_u8_PinNo <= DIO_u8_PORTB_END )
		{
			return GET_BIT(PORTB,Copy_u8_PinNo - DIO_u8_PORT_A_SIZE);
		}
		else if(Copy_u8_PinNo >= DIO_u8_PORTC_START && Copy_u8_PinNo <= DIO_u8_PORTC_END )
		{
			return GET_BIT(PORTC,Copy_u8_PinNo - (DIO_u8_PORT_A_SIZE + DIO_u8_PORT_B_SIZE));
		}
		else if(Copy_u8_PinNo >= DIO_u8_PORTD_START && Copy_u8_PinNo <= DIO_u8_PORTD_END )
		{
			return GET_BIT(PORTD,Copy_u8_PinNo - (DIO_u8_PORT_A_SIZE + DIO_u8_PORT_B_SIZE + DIO_u8_PORT_C_SIZE));
		}

}

