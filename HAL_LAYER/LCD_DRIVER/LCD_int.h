/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : LCD_Interface **************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_

/******************************************************************************/
/************************** Public Commands ***********************************/
/******************************************************************************/

#define LCD_CLR							0x01	//replace all characters with ASCII 'space'
#define LCD_HOME						0x02	//return cursor to first position of first line
#define LCD_ENTRYMODE					0x06	//shift cursor to left/right when read/write
#define LCD_DISPOFF						0x08	//Turn off Display
#define LCD_DISPON_CURSOFF				0x0C	//Turn on Display, Cursor off
#define LCD_DISPON_CURSON				0x0E	//Turn on Display, Cursor on, No Blinking
#define LCD_DISPON_CURSBLINK			0x0F	//Turn on Display, Cursor Blinking
#define LCD_FUNCSET_8BIT				0x38	//8-bit data, 2 line display, 5 x 7 font
#define LCD_FUNCSET_4BIT				0x28	//8-bit data, 2 line display, 5 x 7 font
#define LCD_FUNCRESET					0x30	//LCD Reset
#define LCD_SETCURSOR					0x80	//Set Cursor Position

/******************************************************************************/
/************************** Public Functions **********************************/
/******************************************************************************/

/* Initialization of LCD*/
void LCD_VidInit(void);

void LCD_VidSendChar(u8 u8CopyChar);

/* Send Characters to LCD*/
void LCD_VidSendCmd(u8 u8CopyCmd);

/* Send String to LCD*/
void LCD_VidSendStr(u8* pu8Str);

/* Move Cursor to Certain Position*/
void LCD_VidGoToXY(s8 s8CopyLine,s8 s8CopyPosition);

/* Write Integer Number On LCD*/
void LCD_VidWriteNum(s32 s32CopyNum);

/* Write Float Number On LCD*/
void LCD_VidWriteFloatNum(f32 f32CopyFloatNum);

/* Write Custom Char Previously Stored In CGRAM */
void LCD_VidWriteCustomChar(u8 u8CopyCharIndex, s8 s8CopyLine, s8 s8CopyPosition);

/* Store Custom Char CGRAM */
void LCD_VidStoreCustomChar(u8 u8CopyCharIndex, u8* pu8CopyCharPattern);

/* Shift Display To Right */
void LCD_VidShiftDispRight(u8 u8CopyNumOfShifts);

/* Shift Display To Left */
void LCD_VidShiftDispLeft(u8 u8CopyNumOfShifts);

/* Shift Cursor To Right*/
void LCD_VidShiftCursRight(u8 u8CopyNumOfShifts);

/* Shift Cursor To Left */
void LCD_VidShiftCursLeft(u8 u8CopyNumOfShifts);

#endif /* LCD_INT_H_ */
