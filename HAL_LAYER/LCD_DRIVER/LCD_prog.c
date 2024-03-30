/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : LCD_Program ****************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_conf.h"
#include "LCD_priv.h"

/* Initialization of LCD*/
void LCD_VidInit(void)
{

#if LCD_INTERFACE_OPERATION == EIGHT_BIT_INTERFACE_OPERATION

	/*		POWER ON		*/
		_delay_ms(30);
		/*		FUNCTION SET	*/
		LCD_VidSendCmd(LCD_FUNCSET_8BIT);
		_delay_ms(1);

		/*		DISPLAY ON/OFF	*/
		LCD_VidSendCmd(LCD_DISPON_CURSON);
		_delay_ms(1);

		/*		DISPLAY CLEAR	*/
		LCD_VidSendCmd(LCD_CLR);
		_delay_ms(2);

		/*		ENTRY MODE SET	*/
		LCD_VidSendCmd(LCD_ENTRYMODE);
		_delay_ms(1);

#elif LCD_INTERFACE_OPERATION == FOUR_BIT_INTERFACE_OPERATION

	/*		POWER ON		*/
	_delay_ms(30);

	/* CLR RS PIN */
	DIO_VidSetPinVal(LCD_RS_PORTX,LCD_RS_PINX,DIO_LOW);

	/* CLR RW PIN*/
	DIO_VidSetPinVal(LCD_RW_PORTX,LCD_RW_PINX,DIO_LOW);

	/* LOAD THE COMMAND */
	DIO_VidSetPinVal(LCD_DATA_PIN4_PORTX,LCD_DATA_PIN4_PINX,0);
	DIO_VidSetPinVal(LCD_DATA_PIN5_PORTX,LCD_DATA_PIN5_PINX,1);
	DIO_VidSetPinVal(LCD_DATA_PIN6_PORTX,LCD_DATA_PIN6_PINX,0);
	DIO_VidSetPinVal(LCD_DATA_PIN7_PORTX,LCD_DATA_PIN7_PINX,0);

	/* SET E PIN TO HIGH*/
	DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_HIGH);
	_delay_ms(1);
	/* CLR E PIN */
	DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_LOW);

	/*		FUNCTION SET	*/
	LCD_VidSendCmd(LCD_FUNCSET_4BIT);
	_delay_ms(1);

	/*		DISPLAY ON/OFF	*/
	LCD_VidSendCmd(LCD_DISPON_CURSON);
	_delay_ms(1);

	/*		DISPLAY CLEAR	*/
	LCD_VidSendCmd(LCD_CLR);
	_delay_ms(2);

	/*		ENTRY MODE SET	*/
	LCD_VidSendCmd(LCD_ENTRYMODE);
	_delay_ms(1);

#endif
}

/* Send Commands to LCD*/
void LCD_VidSendCmd(u8 u8CopyCmd)
{
#if LCD_INTERFACE_OPERATION == EIGHT_BIT_INTERFACE_OPERATION

	/* CLR RS PIN */
	DIO_VidSetPinVal(LCD_RS_PORTX,LCD_RS_PINX,DIO_LOW);

	/* CLR RW PIN*/
	DIO_VidSetPinVal(LCD_RW_PORTX,LCD_RW_PINX,DIO_LOW);

	/* LOAD THE COMMAND */
	DIO_VidSetPinVal(LCD_DATA_PIN0_PORTX,LCD_DATA_PIN0_PINX,GET_BIT(u8CopyCmd,0));
	DIO_VidSetPinVal(LCD_DATA_PIN1_PORTX,LCD_DATA_PIN1_PINX,GET_BIT(u8CopyCmd,1));
	DIO_VidSetPinVal(LCD_DATA_PIN2_PORTX,LCD_DATA_PIN2_PINX,GET_BIT(u8CopyCmd,2));
	DIO_VidSetPinVal(LCD_DATA_PIN3_PORTX,LCD_DATA_PIN3_PINX,GET_BIT(u8CopyCmd,3));
	DIO_VidSetPinVal(LCD_DATA_PIN4_PORTX,LCD_DATA_PIN4_PINX,GET_BIT(u8CopyCmd,4));
	DIO_VidSetPinVal(LCD_DATA_PIN5_PORTX,LCD_DATA_PIN5_PINX,GET_BIT(u8CopyCmd,5));
	DIO_VidSetPinVal(LCD_DATA_PIN6_PORTX,LCD_DATA_PIN6_PINX,GET_BIT(u8CopyCmd,6));
	DIO_VidSetPinVal(LCD_DATA_PIN7_PORTX,LCD_DATA_PIN7_PINX,GET_BIT(u8CopyCmd,7));

	//DIO_VidSetPortVal(DIO_PORTD,u8CopyCmd);

	/* SET E PIN TO HIGH*/
	DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_HIGH);
	_delay_ms(1);

	/* CLR E PIN */
	DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_LOW);

#elif LCD_INTERFACE_OPERATION == FOUR_BIT_INTERFACE_OPERATION

	/* CLR RS PIN */
	DIO_VidSetPinVal(LCD_RS_PORTX,LCD_RS_PINX,DIO_LOW);

	/* CLR RW PIN*/
	DIO_VidSetPinVal(LCD_RW_PORTX,LCD_RW_PINX,DIO_LOW);

	for(u8 i = 0; i<=1; i++)
	{
		/* SET E PIN TO HIGH*/
		DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_HIGH);
		_delay_ms(1);

		/*LOAD THE COMMAND*/
		DIO_VidSetPinVal(LCD_DATA_PIN4_PORTX,LCD_DATA_PIN4_PINX,GET_BIT(u8CopyCmd,(4-i*4)));
		DIO_VidSetPinVal(LCD_DATA_PIN5_PORTX,LCD_DATA_PIN5_PINX,GET_BIT(u8CopyCmd,(5-i*4)));
		DIO_VidSetPinVal(LCD_DATA_PIN6_PORTX,LCD_DATA_PIN6_PINX,GET_BIT(u8CopyCmd,(6-i*4)));
		DIO_VidSetPinVal(LCD_DATA_PIN7_PORTX,LCD_DATA_PIN7_PINX,GET_BIT(u8CopyCmd,(7-i*4)));

		/* CLR E PIN*/
		DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_LOW);
	}

#endif
}

/* Send Characters to LCD*/
void LCD_VidSendChar(u8 u8CopyChar)
{
#if LCD_INTERFACE_OPERATION == EIGHT_BIT_INTERFACE_OPERATION

	/* CLR RS PIN */
	DIO_VidSetPinVal(LCD_RS_PORTX,LCD_RS_PINX,DIO_HIGH);

	/* CLR RW PIN*/
	DIO_VidSetPinVal(LCD_RW_PORTX,LCD_RW_PINX,DIO_LOW);

	/* LOAD THE COMMAND */
	DIO_VidSetPinVal(LCD_DATA_PIN0_PORTX,LCD_DATA_PIN0_PINX,GET_BIT(u8CopyChar,0));
	DIO_VidSetPinVal(LCD_DATA_PIN1_PORTX,LCD_DATA_PIN1_PINX,GET_BIT(u8CopyChar,1));
	DIO_VidSetPinVal(LCD_DATA_PIN2_PORTX,LCD_DATA_PIN2_PINX,GET_BIT(u8CopyChar,2));
	DIO_VidSetPinVal(LCD_DATA_PIN3_PORTX,LCD_DATA_PIN3_PINX,GET_BIT(u8CopyChar,3));
	DIO_VidSetPinVal(LCD_DATA_PIN4_PORTX,LCD_DATA_PIN4_PINX,GET_BIT(u8CopyChar,4));
	DIO_VidSetPinVal(LCD_DATA_PIN5_PORTX,LCD_DATA_PIN5_PINX,GET_BIT(u8CopyChar,5));
	DIO_VidSetPinVal(LCD_DATA_PIN6_PORTX,LCD_DATA_PIN6_PINX,GET_BIT(u8CopyChar,6));
	DIO_VidSetPinVal(LCD_DATA_PIN7_PORTX,LCD_DATA_PIN7_PINX,GET_BIT(u8CopyChar,7));

	//DIO_VidSetPortVal(DIO_PORTD,u8CopyChar);

	/* SET E PIN TO HIGH*/
	DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_HIGH);
	_delay_ms(1);

	/* CLR E PIN */
	DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_LOW);

#elif LCD_INTERFACE_OPERATION == FOUR_BIT_INTERFACE_OPERATION

	/* CLR RS PIN */
	DIO_VidSetPinVal(LCD_RS_PORTX,LCD_RS_PINX,DIO_HIGH);

	/* CLR RW PIN*/
	DIO_VidSetPinVal(LCD_RW_PORTX,LCD_RW_PINX,DIO_LOW);

	for(u8 i = 0; i<=1; i++)
	{
		 /*SET E PIN TO HIGH*/
		DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_HIGH);
		_delay_ms(1);

		 /*LOAD THE COMMAND*/
		DIO_VidSetPinVal(LCD_DATA_PIN4_PORTX,LCD_DATA_PIN4_PINX,GET_BIT(u8CopyChar,(4-i*4)));
		DIO_VidSetPinVal(LCD_DATA_PIN5_PORTX,LCD_DATA_PIN5_PINX,GET_BIT(u8CopyChar,(5-i*4)));
		DIO_VidSetPinVal(LCD_DATA_PIN6_PORTX,LCD_DATA_PIN6_PINX,GET_BIT(u8CopyChar,(6-i*4)));
		DIO_VidSetPinVal(LCD_DATA_PIN7_PORTX,LCD_DATA_PIN7_PINX,GET_BIT(u8CopyChar,(7-i*4)));

		 /*CLR E PIN*/
		DIO_VidSetPinVal(LCD_E_PORTX,LCD_E_PINX,DIO_LOW);
	}

#endif
}

/* Send String to LCD*/
void LCD_VidSendStr(u8* pu8Str)
{
	u8 Counter = 0;
	while (pu8Str[Counter]!=0)
	{
		LCD_VidSendChar(pu8Str[Counter]);
		Counter++;
	}
}

/* Move Cursor to Certain Position*/
void LCD_VidGoToXY(s8 s8CopyLine,s8 s8CopyPosition)
{
	switch(s8CopyLine)
	{
	case 1:LCD_VidSendCmd(s8CopyPosition+128-1);break;	//position = position + address 0x80
	case 2:LCD_VidSendCmd(s8CopyPosition+192-1);break;	//position = position + address 0xC0		}
	}
}

/* Write Integer Number On LCD*/
void LCD_VidWriteNum(s32 s32CopyNum)
{
	if(s32CopyNum==0)
	{
		LCD_VidSendChar('0');
	}
	else
	{
		if(s32CopyNum<0)
		{
			LCD_VidSendChar('-');
			s32CopyNum *= -1;
		}
		u8 u8LocNumOfDigits = 0;
		s32 s32LocTemp = 0;
		s32 s32LocCopyNum = s32CopyNum;
		while (s32LocCopyNum != 0)
		{
			u8LocNumOfDigits++;
			s32LocCopyNum /= 10;
		}
		for(s8 u8LocCounter = u8LocNumOfDigits; u8LocCounter>0; u8LocCounter--)
		{
			s32LocTemp = s32CopyNum / (Priv_S32Power(10,u8LocCounter-1)) ;
			LCD_VidSendChar(s32LocTemp+'0');
			s32CopyNum = s32CopyNum % (Priv_S32Power(10,u8LocCounter-1)) ;
			_delay_ms(50);
		}
	}
}

/* Write Float Number On LCD*/
void LCD_VidWriteFloatNum(f32 f32CopyFloatNum)
{
	s32 s32CopyIntNum = f32CopyFloatNum;
	f32 f32CopyFloatR = f32CopyFloatNum - s32CopyIntNum;
	if(f32CopyFloatR<0)
	{
		f32CopyFloatR *= -1;
		if(s32CopyIntNum==0)
		{
			LCD_VidSendChar('-');
		}
	}
	LCD_VidWriteNum(s32CopyIntNum);
	if(f32CopyFloatR!=0)
	{
		LCD_VidSendChar('.');
		for(s8 u8LocCounter = 0; u8LocCounter<=2; u8LocCounter++)
		{
			f32CopyFloatR *= 10;
			LCD_VidWriteNum((s32)f32CopyFloatR);
			f32CopyFloatR -= (s32)f32CopyFloatR;
		}
	}
}

/* Write Custom Char Previously Stored In CGRAM */
void LCD_VidWriteCustomChar(u8 u8CopyCharIndex, s8 s8CopyLine, s8 s8CopyPosition)
{
	LCD_VidSendCmd(0x40+u8CopyCharIndex);
	LCD_VidGoToXY(s8CopyLine,s8CopyPosition);
	LCD_VidSendChar(u8CopyCharIndex);
}

/* Store Custom Char CGRAM */
void LCD_VidStoreCustomChar(u8 u8CopyCharIndex, u8* pu8CopyCharPattern)
{
	u8 u8LocCGRAM_ADD = u8CopyCharIndex * 8;
	LCD_VidSendCmd(0x40+u8LocCGRAM_ADD);
	for(u8 u8LocCounter = 0; u8LocCounter<8; u8LocCounter++)
	{
		LCD_VidSendChar(pu8CopyCharPattern[u8LocCounter]);
	}
}

/* Shift Display To Right */
void LCD_VidShiftDispRight(u8 u8CopyNumOfShifts)
{
	for(u8 u8LocCounter = 1; u8LocCounter<=u8CopyNumOfShifts; u8LocCounter++)
	{
		LCD_VidSendCmd(0x1C);
	}
}

/* Shift Display To Left */
void LCD_VidShiftDispLeft(u8 u8CopyNumOfShifts)
{
	for(u8 u8LocCounter = 1; u8LocCounter<=u8CopyNumOfShifts; u8LocCounter++)
		{
			LCD_VidSendCmd(0x18);
		}
}

/* Shift Cursor To Right*/
void LCD_VidShiftCursRight(u8 u8CopyNumOfShifts)
{
	for(u8 u8LocCounter = 1; u8LocCounter<=u8CopyNumOfShifts; u8LocCounter++)
	{
		LCD_VidSendCmd(0x16);
	}

}

/* Shift Cursor To Left */
void LCD_VidShiftCursLeft(u8 u8CopyNumOfShifts)
{
	for(u8 u8LocCounter = 1; u8LocCounter<=u8CopyNumOfShifts; u8LocCounter++)
	{
		LCD_VidSendCmd(0x10);
	}
}












