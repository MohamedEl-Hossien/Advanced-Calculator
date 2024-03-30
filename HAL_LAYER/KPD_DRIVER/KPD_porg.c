/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : KPD_Program ****************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#define	F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "DIO_priv.h"
#include "KPD_int.h"
#include "KPD_priv.h"
#include "KPD_conf.h"

u8 KPD_au8Array [KPD_ROW_NUM][KPD_COL_NUM] = {
												{KPD_PUTTON1,KPD_PUTTON2,KPD_PUTTON3,KPD_PUTTON4},
												{KPD_PUTTON5,KPD_PUTTON6,KPD_PUTTON7,KPD_PUTTON8},
												{KPD_PUTTON9,KPD_PUTTON10,KPD_PUTTON11,KPD_PUTTON12},
												{KPD_PUTTON13,KPD_PUTTON14,KPD_PUTTON15,KPD_PUTTON16}	};


u8 KPD_u8GetPressedKey()
{
	u8  u8Col,u8ROW, u8LocSW = NOTPRESSED;

	for(u8Col = KPD_COL1; u8Col <  KPD_COL1+KPD_COL_NUM; u8Col++)
	{
		DIO_VidSetPinVal(KPD_COL_PORTX,u8Col,DIO_PIN_LOW);
		for(u8ROW = KPD_ROW1; u8ROW < KPD_ROW1+KPD_ROW_NUM; u8ROW++)
		{
			if( DIO_u8GetPinVal(KPD_ROW_PORTX,u8ROW) == DIO_PIN_LOW )
			{
				u8LocSW = KPD_au8Array [u8ROW-KPD_ROW1][u8Col-KPD_COL1];
				while(DIO_u8GetPinVal(KPD_ROW_PORTX,u8ROW)==DIO_LOW);
				_delay_ms(20);
			}
		}
		DIO_VidSetPinVal(KPD_COL_PORTX,u8Col,DIO_HIGH);
	}
	return u8LocSW;
}
