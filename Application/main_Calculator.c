/******************************************************/
/************* Date : 30/03/2024 **********************/
/************* File Name : Main_Calculator ************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KPD_int.h"
#include "Calculator_Func.h"

u8 G_u8_KPD_Pressed[50];								//Global Array to store Keypad Buttons Pressed

int main()
{
	DIO_VidInit();										//Initialize Digital Input/Output Ports
	LCD_VidInit();										//Initialize LCD
	u8 Loc_u8_Key_Pressed,Loc_u8_Counter=0;
	u8 Loc_u8_Status=Syntax_Error;						// Initial Value of Status is Syntax Error
	f32 Loc_f32_Result=0;
	while(1)
	{
		Loc_u8_Key_Pressed = KPD_u8GetPressedKey();		//Get Pressed Key
		if(Loc_u8_Key_Pressed != NOTPRESSED)
		{
			if(Loc_u8_Key_Pressed=='=')					//If The Key Pressed is '=', Check The Expression
			{
				if(Loc_u8_Counter!=0)
				{
					Loc_u8_Status = M_u8_Create_KPD_Arr(Loc_u8_Counter,&Loc_f32_Result);
					//Call Function that Create Two Arrays, one for Operands and the other for Operators
					Loc_u8_Counter = 0;
					if(Loc_u8_Status==Syntax_Error)
					{
						LCD_VidSendStr((u8*)"Syntax_Error");	//Print Syntax_Error on LCD
					}
					else if(Loc_u8_Status == Math_Error)
					{
						LCD_VidSendStr((u8*)"Math_Error");		//Print Math_Error on LCD
					}
					else if(Loc_u8_Status == Correct)
					{
						LCD_VidWriteFloatNum(Loc_f32_Result);	//Print Result Value on LCD
					}
				}
			}
			else if(Loc_u8_Key_Pressed==' ')					//If The Key Pressed is ' ', Clear All
			{
				Loc_u8_Counter = 0;
				LCD_VidSendCmd(LCD_CLR);						//Clear LCD
			}
			else
			{
				if(Loc_u8_Counter==0)							//If The Counter = 0, Clear All
				{
					LCD_VidSendCmd(LCD_CLR);
				}
				else if(Loc_u8_Counter>=16)						//If The Counter >= 16, Shift Display Left to Show Content on LCD
				{
					LCD_VidShiftDispLeft(1);
				}
				LCD_VidSendChar(Loc_u8_Key_Pressed);			//Print Char on LCD
				G_u8_KPD_Pressed[Loc_u8_Counter]=Loc_u8_Key_Pressed;	//Store Pressed Key in The KeyPad Array
				Loc_u8_Counter++;								//Increase Counter by one
			}
		}
	}
}
