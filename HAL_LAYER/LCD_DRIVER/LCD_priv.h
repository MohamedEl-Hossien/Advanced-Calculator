/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : KPD_Private ****************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define EIGHT_BIT_INTERFACE_OPERATION		0
#define FOUR_BIT_INTERFACE_OPERATION		1

s32 Priv_S32Power(s32 s32CopyNum, s32 s32CopyPower)
{
	s32 s32LocResult = 1;
	for(u8 u8LocCounter = 1; u8LocCounter<=s32CopyPower; u8LocCounter++)
	{
		s32LocResult *= s32CopyNum;
	}
	return s32LocResult;
}

#endif /* LCD_PRIV_H_ */
