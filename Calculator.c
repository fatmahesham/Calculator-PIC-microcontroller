/***********************************************/
/*Title       : Calculator program file        */
/*Author      : Fatma Hesham                   */
/*Release     : 1.0                            */
/*Last Update : Sep 11,2021                    */
/***********************************************/

#include "STD_Types.h"
#include "Calculator.h"

/*
****************** Operators ********************
Correct  add -> '+'
         equal -> '='
         power -> '^'

Modified  multiplication -> 'x' //'x' not'*'
          remainder -> 0x25
          division -> 0xFD
          factor -> 0x21
          blank -> 0xFE

****************** Numbers **********************
  num             ascii code for ATmega32 in decimal
  (0 -> 9)         (48 -> 57)

*/

u8 characters_array[50]; //array stores the character of every single press on keypad
static s8 char_array_size=-1;     //size is calculated counting from zero
                                  //character_size is the index of the last available place in the characters_array
static s8 character_index=-1;    //to move into characters_array

s8 digits_counter=0;     //counts number of digits in an integer to calculate its value

s32 integers_stack[2]={0};   //to store integers in delayed operation
u8 operations_stack[2]={0};  //to store operation sign in delayed operation
static s8 stack_index=-1;    //used to deal with integers_stack & operations_stack

static s32 s32_Sol=0;    //final solution

s32 power(s32 a, s32 b)
{
    s32 base=a, Res=1;
    while(b!=0)
    {
        if(b%2)
            Res*=base;
        base*=base;
        b=b>>1;
    }
    return Res;

}

#define  character_ind   character_index+digits_counter  //ind -> indicator

void read_num_and_op(s32* num_ptr, u8* op_ptr) //read number and operation
{
	digits_counter=0;
	character_index+=1;
	while(char_array_size>=character_ind&& characters_array[character_ind] >= '0'
			 && characters_array[character_ind] <= '9' )
	{
		digits_counter+=1;
	}
	if(character_ind <= char_array_size)
        *op_ptr = characters_array[character_ind];
    else
        *op_ptr = 's';  //character_ind points to unavailable place in character array (the place after the last one)
	*num_ptr = 0;
    for(s8 count=digits_counter-1; count>=0; count-=1)
	{
		(*num_ptr) += (characters_array[character_index++]-48)*power(10, count);
	}

}

u8 Calc_Periorty(u8 ch)
{
	switch (ch)
	{
	case '^' : return 3;
	case 'x' : return 2;
	case 0xFD: return 2; //Division
	case 0x25: return 2; //Remainder
	case '+' : return 1;
	case '-' : return 1;
	case 's' : return 0; //the program finishes walking through the character array

	}
}

s32 Get_Sol(s32 num1, s32 num2, u8 op)
{
	switch (op)
		{
		case '^' : return power(num1,num2);
		case '+' : return num1+num2;
		case '-' : return num1-num2;
		case 'x' : return num1*num2;
		case 0xFD: return num1/num2;
		case 0x25: return num1%num2;
		//case 0x21: return fact(num1);

		}
}

u32 Calculator_vid_Calc_Sol()
{
	s32 num1, num2;
	s32 *num1_ptr=&num1, *num2_ptr=&num2;

	u8 op1, op2;
	u8 *op1_ptr=&op1, *op2_ptr=&op2;

	u8 Operation1_Periorty, Operation2_Periorty;

	read_num_and_op(num1_ptr, op1_ptr);
    Operation1_Periorty=Calc_Periorty(op1);

	while(1)
	{
		read_num_and_op(num2_ptr, op2_ptr);
		Operation2_Periorty=Calc_Periorty(op2);
		if(Operation1_Periorty >= Operation2_Periorty)
		{
			s32_Sol=Get_Sol(num1,num2,op1);
			while(stack_index>-1)
			{
				u8 Stack_Operation_Periorty=Calc_Periorty(operations_stack[stack_index]);
				if(Stack_Operation_Periorty >= Operation2_Periorty)
				{
					s32_Sol=Get_Sol(integers_stack[stack_index],s32_Sol,operations_stack[stack_index]);
					stack_index--;
				}
				else
				{
					break;
				}
			}
			num1=s32_Sol;
			op1=op2;
			Operation1_Periorty = Operation2_Periorty;
		}
		else
		{
			stack_index++;
			integers_stack[stack_index]=num1;
			operations_stack[stack_index]=op1;
			num1=num2;
			op1=op2;
			Operation1_Periorty = Operation2_Periorty;
		}
		if (op2=='s')
            return s32_Sol;
	}
}

void Calculator_vid_Store_char(u8 ch)
{
	if(ch == 'c')
		char_array_size --;
	else
	    characters_array[++char_array_size]=ch;
	if(character_index>char_array_size)
		Calculator_vid_Clear_Screen_And_Memory();
}

void Calculator_vid_Print_Sol_By_LCD()
{
	u8 num_of_digits=0;
	if(s32_Sol<0)
	{
		LCD_vidWriteCharacter('-');
		s32_Sol *= -1;
	}
	s32 num=s32_Sol;
	while(num)
	{
		num /= 10;
		num_of_digits++;
	}
	if(num_of_digits==0)
	{
		LCD_vidWriteCharacter((u8)(48));
	}
	while(num_of_digits != 0)
	{
		s32 digit_weight=power(10, num_of_digits-1);
		s32 u8_ch =  s32_Sol / digit_weight;
		LCD_vidWriteCharacter((u8)(u8_ch+48));
		s32_Sol -= u8_ch* digit_weight;
		num_of_digits--;
	}
}

s8 cursor_at_start_point()
{
	if(char_array_size==-1)
		return 1;
	else
		return 0;
}

void Calculator_vid_Clear_Screen_And_Memory()
{
	LCD_vidClearScreen();
	char_array_size=-1;
	character_index=-1;
}
