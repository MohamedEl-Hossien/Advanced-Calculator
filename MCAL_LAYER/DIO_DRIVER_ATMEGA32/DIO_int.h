/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : DIO_Interface **************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_

/***** Macros of DIO Ports *****/
#define DIO_PORTA			0
#define DIO_PORTB			1
#define DIO_PORTC			2
#define DIO_PORTD			3

/***** Macros of DIO Pins ******/
#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2			2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7

/***** Pins Direction of DIO Ports ****/
#define DIO_INPUT			0x00
#define DIO_OUTPUT			0xFF

#define DIO_LOW				0x00
#define DIO_HIGH			0xFF

#define DIO_PIN_INPUT		0
#define DIO_PIN_OUTPUT		1

#define DIO_PIN_LOW			0
#define DIO_PIN_HIGH		1

#define DIO_PIN_NOPULLUP	0
#define DIO_PIN_PULLUP		1

#define DIO_UNDEF_VAL   	0xFF

/***** Initialization Function of DIO Ports ***********/
void DIO_VidInit(void);

/***** Set Pins Direction of DIO Ports ****************/
void DIO_VidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir);

/***** Set Pins Value of DIO Ports ********************/
void DIO_VidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal);

/***** Get Pins Value of DIO Ports ********************/
u8 DIO_u8GetPinVal(u8 u8PortId, u8 u8PinId);

/***** Toggle Pins Value of DIO Ports *****************/
void DIO_VidTogglePinVal(u8 u8PortId, u8 u8PinId);

/***** Enable Pins Pull Up Resistance of DIO Ports ****/
void DIO_VidEnablePullUpRes(u8 u8PortId, u8 u8PinId);

/***** Set All Pins Direction of DIO Ports ************/
void DIO_VidSetPortDir(u8 u8PortId, u8 u8PortDir);

/***** Set All Pins Value of DIO Ports ****************/
void DIO_VidSetPortVal(u8 u8PortId, u8 u8PortVal);

#endif /* DIO_INT_H_ */
