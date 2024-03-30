/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : LCD_Configurations *********/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef LCD_CONF_H_
#define LCD_CONF_H_

/************* LCD OPERATED IN EITHER 4 OR 8 BITS MODE ***************/
/************* OPTIONS : 1-8_BIT_INTERFACE_OPERATION   ***************/
/*************			 2-4_BIT_INTERFACE_OPERATION   ***************/

#define LCD_INTERFACE_OPERATION		FOUR_BIT_INTERFACE_OPERATION


/************* LCD CONTROL PORT & PINS ***************/
#define LCD_RS_PORTX				DIO_PORTD
#define LCD_RS_PINX					DIO_PIN0
#define LCD_RW_PORTX				DIO_PORTD
#define LCD_RW_PINX					DIO_PIN1
#define LCD_E_PORTX					DIO_PORTD
#define LCD_E_PINX					DIO_PIN2

/************* LCD DATA PORT & PINS ******************/
/******* CONFIGURATION OF FIRST 4 PINS ***************/
/******* USED ONLY IN 8_BIT_INTERFACE_OPERATION ******/
#define LCD_DATA_PIN0_PORTX			DIO_PORTC
#define LCD_DATA_PIN0_PINX			DIO_PIN0
#define LCD_DATA_PIN1_PORTX			DIO_PORTC
#define LCD_DATA_PIN1_PINX			DIO_PIN1
#define LCD_DATA_PIN2_PORTX			DIO_PORTC
#define LCD_DATA_PIN2_PINX			DIO_PIN2
#define LCD_DATA_PIN3_PORTX			DIO_PORTC
#define LCD_DATA_PIN3_PINX			DIO_PIN3

/******* CONFIGURATION OF SECOND 4 PINS **************/
/******* USED IN 4/8 _BIT_INTERFACE_OPERATION ********/
#define LCD_DATA_PIN4_PORTX			DIO_PORTD
#define LCD_DATA_PIN4_PINX			DIO_PIN4
#define LCD_DATA_PIN5_PORTX			DIO_PORTD
#define LCD_DATA_PIN5_PINX			DIO_PIN5
#define LCD_DATA_PIN6_PORTX			DIO_PORTD
#define LCD_DATA_PIN6_PINX			DIO_PIN6
#define LCD_DATA_PIN7_PORTX			DIO_PORTD
#define LCD_DATA_PIN7_PINX			DIO_PIN7
/*****************************************************/


#endif /* LCD_CONF_H_ */
