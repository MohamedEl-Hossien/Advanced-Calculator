/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : KPD_Configuration **********/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef KPD_CONF_H_
#define KPD_CONF_H_

#define KPD_COL_PORTX	DIO_PORTA
#define KPD_COL1		DIO_PIN4
#define KPD_COL2		DIO_PIN5
#define KPD_COL3		DIO_PIN6
#define KPD_COL4		DIO_PIN7

#define KPD_ROW_PORTX	DIO_PORTA
#define KPD_ROW1		DIO_PIN0
#define KPD_ROW2		DIO_PIN1
#define KPD_ROW3		DIO_PIN2
#define KPD_ROW4		DIO_PIN3

/*KPD_au8Array {{KPD_PUTTON1 ,KPD_PUTTON2 ,KPD_PUTTON3 ,KPD_PUTTON4 },
				{KPD_PUTTON5 ,KPD_PUTTON6 ,KPD_PUTTON7 ,KPD_PUTTON8 },
				{KPD_PUTTON9 ,KPD_PUTTON10,KPD_PUTTON11,KPD_PUTTON12},
				{KPD_PUTTON13,KPD_PUTTON14,KPD_PUTTON15,KPD_PUTTON16}};*/


#define KPD_PUTTON1		'7'
#define KPD_PUTTON2		'8'
#define KPD_PUTTON3		'9'
#define KPD_PUTTON4		'/'
#define KPD_PUTTON5		'4'
#define KPD_PUTTON6		'5'
#define KPD_PUTTON7		'6'
#define KPD_PUTTON8		'*'
#define KPD_PUTTON9		'1'
#define KPD_PUTTON10	'2'
#define KPD_PUTTON11	'3'
#define KPD_PUTTON12	'-'
#define KPD_PUTTON13	' '
#define KPD_PUTTON14	'0'
#define KPD_PUTTON15	'='
#define KPD_PUTTON16	'+'


#endif /* KPD_CONF_H_ */
