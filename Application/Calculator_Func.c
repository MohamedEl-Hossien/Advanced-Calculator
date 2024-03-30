/******************************************************/
/************* Date : 30/03/2024 **********************/
/************* File Name : Calculator_Func ************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "LCD_int.h"
#include "Calculator_Func.h"

extern u8 G_u8_KPD_Pressed[50];

u8 M_u8_Create_KPD_Arr(u8 Copy_u8_Counter,f32* P_f32_Result)
{
	*P_f32_Result=0;								//Set Result by Zero
	u8 Loc_u8_Counter=0,Loc_u8_Result=0;
	u8 Loc_u8_Operands_Count=0,Loc_u8_Operators_Count=0,Loc_u8_Negative_Flag=0;
	u8 Loc_u8_Operators_Arr[30]={0};				//Create Array to Store Operates
	f32 Loc_f32_Operands_Arr[30]={0};				//Create Array To Store Operands
	LCD_VidSendCmd(LCD_CLR);						//Clear LCD

	while(Loc_u8_Counter<Copy_u8_Counter)			//Copy_u8_Counter Stores Num of KPD Pressed
	{
		//Check if the Char is a Number or Operator
		if((G_u8_KPD_Pressed[Loc_u8_Counter]>='0') && (G_u8_KPD_Pressed[Loc_u8_Counter]<='9'))
		{
			//while the Next Char is a Number -> Create one Integer Number from Digits
			while(((G_u8_KPD_Pressed[Loc_u8_Counter]>='0') && (G_u8_KPD_Pressed[Loc_u8_Counter]<='9')) && (Loc_u8_Counter<Copy_u8_Counter))
			{
				//Store The Number in Operands Array
				Loc_f32_Operands_Arr[Loc_u8_Operands_Count]=Loc_f32_Operands_Arr[Loc_u8_Operands_Count]*10+(G_u8_KPD_Pressed[Loc_u8_Counter]-'0');
				Loc_u8_Counter++;
			}
			//If Negative Flag = 1 -> Multiply Number by -1
			if(Loc_u8_Negative_Flag==1)
			{
				Loc_f32_Operands_Arr[Loc_u8_Operands_Count]*=-1;
				Loc_u8_Negative_Flag=0;				//Clear Flag
			}
			Loc_u8_Operands_Count++;				//Increase Counter by 1
		}
		else
		{
			if(Loc_u8_Counter==0)		//Check if it is the First Element in The Array or not
			{
				//Check if the First Element = '+' & Next Element is a Number
				if(G_u8_KPD_Pressed[Loc_u8_Counter]=='+')
				{
					if((G_u8_KPD_Pressed[Loc_u8_Counter+1]>='0') && (G_u8_KPD_Pressed[Loc_u8_Counter+1]<='9'))
					{
						Loc_u8_Counter++;
					}
					else
					{
						return Syntax_Error;
					}
				}
				//Check if the First Element = '-' & Next Element is a Number
				else if(G_u8_KPD_Pressed[Loc_u8_Counter]=='-')
				{
					if((G_u8_KPD_Pressed[Loc_u8_Counter+1]>='0') && (G_u8_KPD_Pressed[Loc_u8_Counter+1]<='9'))
					{
						Loc_u8_Negative_Flag=1;		//Set Negative Flag
						Loc_u8_Counter++;
					}
					else
					{
						return Syntax_Error;
					}
				}
				else
				{
					return Syntax_Error;
				}
			}
			else
			{
				//Store The Operator in Operators Array
				Loc_u8_Operators_Arr[Loc_u8_Operators_Count]=G_u8_KPD_Pressed[Loc_u8_Counter];
				Loc_u8_Operators_Count++;
				//Check if The Next Element is a Number
				if((G_u8_KPD_Pressed[Loc_u8_Counter+1]>='0') && (G_u8_KPD_Pressed[Loc_u8_Counter+1]<='9'))
				{
					Loc_u8_Counter++;
				}
				//Check if the Next Element is a Negative Number
				else if((G_u8_KPD_Pressed[Loc_u8_Counter+1]=='-') && ((G_u8_KPD_Pressed[Loc_u8_Counter+2]>='0') && (G_u8_KPD_Pressed[Loc_u8_Counter+2]<='9')))
				{
					Loc_u8_Negative_Flag=1;		//Set Negative Flag
					Loc_u8_Counter+=2;
				}
				else
				{
					return Syntax_Error;
				}
			}
		}
	}

	//Check if Operands == Operators +1
	if((Loc_u8_Operators_Count+1)==Loc_u8_Operands_Count)
	{
		//Call Func to Calculate the Result
		Loc_u8_Result = M_u8_Calculate_Result(Loc_u8_Operators_Arr, Loc_f32_Operands_Arr, Loc_u8_Operators_Count, P_f32_Result);
		if(Loc_u8_Result==Math_Error)
		{
			return Math_Error;
		}
		else
		{
			return Correct;
		}
	}
	else
	{
		return Syntax_Error;
	}
}


u8 M_u8_Calculate_Result(u8* P_u8_Operators_Arr, f32* P_f32_Operands_Arr, u8 Copy_u8_Operators_Count, f32* P_f32_Result)
{
	u8 Loc_u8_Counter=0,Loc_u8_Counter1=0;
	while(Loc_u8_Counter<Copy_u8_Operators_Count)
	{
		//First Calculate Multiply & Division Operators
		if(P_u8_Operators_Arr[Loc_u8_Counter]=='*' || P_u8_Operators_Arr[Loc_u8_Counter]=='/')
		{
			if(P_u8_Operators_Arr[Loc_u8_Counter]=='*')
			{
				P_f32_Operands_Arr[Loc_u8_Counter]*=P_f32_Operands_Arr[Loc_u8_Counter+1];
			}
			else
			{
				//For Division, Check that Denominator not Equal Zero
				if(P_f32_Operands_Arr[Loc_u8_Counter+1]!=0)
				{
					P_f32_Operands_Arr[Loc_u8_Counter]/=P_f32_Operands_Arr[Loc_u8_Counter+1];
				}
				else
				{
					return Math_Error;
				}
			}
			//Rearrange Elements in Operands Array & Operators Array
			for(Loc_u8_Counter1=Loc_u8_Counter;Loc_u8_Counter1<Copy_u8_Operators_Count-1;Loc_u8_Counter1++)
			{
				P_f32_Operands_Arr[Loc_u8_Counter1+1]=P_f32_Operands_Arr[Loc_u8_Counter1+2];
				P_u8_Operators_Arr[Loc_u8_Counter1]=P_u8_Operators_Arr[Loc_u8_Counter1+1];
			}
			Copy_u8_Operators_Count--;
		}
		else
		{
			Loc_u8_Counter++;
		}
	}
	*P_f32_Result=P_f32_Operands_Arr[0];
	//Calculate Addition & Subtraction Operators
	for(Loc_u8_Counter=0;Loc_u8_Counter<Copy_u8_Operators_Count;Loc_u8_Counter++)
	{
			if(P_u8_Operators_Arr[Loc_u8_Counter]=='+')
			{
				*P_f32_Result+=P_f32_Operands_Arr[Loc_u8_Counter+1];
			}
			else if(P_u8_Operators_Arr[Loc_u8_Counter]=='-')
			{
				*P_f32_Result-=P_f32_Operands_Arr[Loc_u8_Counter+1];
			}
	}
	return Correct;
}
