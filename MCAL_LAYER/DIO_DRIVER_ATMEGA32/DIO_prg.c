/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : DIO_Program ****************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_conf.h"

void DIO_VidInit()
{
	DDRA_REG = CONC(	DIO_PORTA_PIN7_INIT_DIREC,
						DIO_PORTA_PIN6_INIT_DIREC,
						DIO_PORTA_PIN5_INIT_DIREC,
						DIO_PORTA_PIN4_INIT_DIREC,
						DIO_PORTA_PIN3_INIT_DIREC,
						DIO_PORTA_PIN2_INIT_DIREC,
						DIO_PORTA_PIN1_INIT_DIREC,
						DIO_PORTA_PIN0_INIT_DIREC	);

	DDRB_REG = CONC(	DIO_PORTB_PIN7_INIT_DIREC,
						DIO_PORTB_PIN6_INIT_DIREC,
						DIO_PORTB_PIN5_INIT_DIREC,
						DIO_PORTB_PIN4_INIT_DIREC,
						DIO_PORTB_PIN3_INIT_DIREC,
						DIO_PORTB_PIN2_INIT_DIREC,
						DIO_PORTB_PIN1_INIT_DIREC,
						DIO_PORTB_PIN0_INIT_DIREC	);

	DDRC_REG = CONC(	DIO_PORTC_PIN7_INIT_DIREC,
						DIO_PORTC_PIN6_INIT_DIREC,
						DIO_PORTC_PIN5_INIT_DIREC,
						DIO_PORTC_PIN4_INIT_DIREC,
						DIO_PORTC_PIN3_INIT_DIREC,
						DIO_PORTC_PIN2_INIT_DIREC,
						DIO_PORTC_PIN1_INIT_DIREC,
						DIO_PORTC_PIN0_INIT_DIREC	);

	DDRD_REG = CONC(	DIO_PORTD_PIN7_INIT_DIREC,
						DIO_PORTD_PIN6_INIT_DIREC,
						DIO_PORTD_PIN5_INIT_DIREC,
						DIO_PORTD_PIN4_INIT_DIREC,
						DIO_PORTD_PIN3_INIT_DIREC,
						DIO_PORTD_PIN2_INIT_DIREC,
						DIO_PORTD_PIN1_INIT_DIREC,
						DIO_PORTD_PIN0_INIT_DIREC	);

	PORTA_REG = CONC(	DIO_PORTA_PIN7_INIT_VALUE,
						DIO_PORTA_PIN6_INIT_VALUE,
						DIO_PORTA_PIN5_INIT_VALUE,
						DIO_PORTA_PIN4_INIT_VALUE,
						DIO_PORTA_PIN3_INIT_VALUE,
						DIO_PORTA_PIN2_INIT_VALUE,
						DIO_PORTA_PIN1_INIT_VALUE,
						DIO_PORTA_PIN0_INIT_VALUE	);

	PORTB_REG = CONC(	DIO_PORTB_PIN7_INIT_VALUE,
						DIO_PORTB_PIN6_INIT_VALUE,
						DIO_PORTB_PIN5_INIT_VALUE,
						DIO_PORTB_PIN4_INIT_VALUE,
						DIO_PORTB_PIN3_INIT_VALUE,
						DIO_PORTB_PIN2_INIT_VALUE,
						DIO_PORTB_PIN1_INIT_VALUE,
						DIO_PORTB_PIN0_INIT_VALUE	);

	PORTC_REG = CONC(	DIO_PORTC_PIN7_INIT_VALUE,
						DIO_PORTC_PIN6_INIT_VALUE,
						DIO_PORTC_PIN5_INIT_VALUE,
						DIO_PORTC_PIN4_INIT_VALUE,
						DIO_PORTC_PIN3_INIT_VALUE,
						DIO_PORTC_PIN2_INIT_VALUE,
						DIO_PORTC_PIN1_INIT_VALUE,
						DIO_PORTC_PIN0_INIT_VALUE	);

	PORTD_REG = CONC(	DIO_PORTD_PIN7_INIT_VALUE,
						DIO_PORTD_PIN6_INIT_VALUE,
						DIO_PORTD_PIN5_INIT_VALUE,
						DIO_PORTD_PIN4_INIT_VALUE,
						DIO_PORTD_PIN3_INIT_VALUE,
						DIO_PORTD_PIN2_INIT_VALUE,
						DIO_PORTD_PIN1_INIT_VALUE,
						DIO_PORTD_PIN0_INIT_VALUE	);

}

void DIO_VidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		if(GET_BIT(u8PinDir,0) == DIO_PIN_INPUT)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : CLR_BIT(DDRA_REG,u8PinId); break;
			case DIO_PORTB : CLR_BIT(DDRB_REG,u8PinId); break;
			case DIO_PORTC : CLR_BIT(DDRC_REG,u8PinId); break;
			case DIO_PORTD : CLR_BIT(DDRD_REG,u8PinId); break;
			}
		}
		else if(GET_BIT(u8PinDir,0) == DIO_PIN_OUTPUT)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : SET_BIT(DDRA_REG,u8PinId); break;
			case DIO_PORTB : SET_BIT(DDRB_REG,u8PinId); break;
			case DIO_PORTC : SET_BIT(DDRC_REG,u8PinId); break;
			case DIO_PORTD : SET_BIT(DDRD_REG,u8PinId); break;
			}
				}
	}
	else
	{
		/* Wrong PORT ID or PIN ID*/
	}
}

void DIO_VidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		if(GET_BIT(u8PinVal,0) == DIO_PIN_LOW)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : CLR_BIT(PORTA_REG,u8PinId); break;
			case DIO_PORTB : CLR_BIT(PORTB_REG,u8PinId); break;
			case DIO_PORTC : CLR_BIT(PORTC_REG,u8PinId); break;
			case DIO_PORTD : CLR_BIT(PORTD_REG,u8PinId); break;
			}
		}
		else if(GET_BIT(u8PinVal,0) == DIO_PIN_HIGH)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : SET_BIT(PORTA_REG,u8PinId); break;
			case DIO_PORTB : SET_BIT(PORTB_REG,u8PinId); break;
			case DIO_PORTC : SET_BIT(PORTC_REG,u8PinId); break;
			case DIO_PORTD : SET_BIT(PORTD_REG,u8PinId); break;
			}
				}
	}
	else
	{
		/* Wrong PORT ID or PIN ID*/
	}
}

u8 DIO_u8GetPinVal(u8 u8PortId, u8 u8PinId)
{
	u8 u8ResultLoc=0;
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA : u8ResultLoc = GET_BIT(PINA_REG,u8PinId); break;
		case DIO_PORTB : u8ResultLoc = GET_BIT(PINB_REG,u8PinId); break;
		case DIO_PORTC : u8ResultLoc = GET_BIT(PINC_REG,u8PinId); break;
		case DIO_PORTD : u8ResultLoc = GET_BIT(PIND_REG,u8PinId); break;
		}
	}
	else
	{
		u8ResultLoc = DIO_UNDEF_VAL;
		/* Wrong PORT ID or PIN ID*/
	}
	return u8ResultLoc;

}

void DIO_VidTogglePinVal(u8 u8PortId, u8 u8PinId)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA : TOGGLE_BIT(PORTA_REG,u8PinId); break;
		case DIO_PORTB : TOGGLE_BIT(PORTB_REG,u8PinId); break;
		case DIO_PORTC : TOGGLE_BIT(PORTC_REG,u8PinId); break;
		case DIO_PORTD : TOGGLE_BIT(PORTD_REG,u8PinId); break;
		}
	}
	else
	{
		/* Wrong PORT ID or PIN ID*/
	}
}

void DIO_VidEnablePullUpRes(u8 u8PortId, u8 u8PinId)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA : SET_BIT(PORTA_REG,u8PinId); break;
		case DIO_PORTB : SET_BIT(PORTB_REG,u8PinId); break;
		case DIO_PORTC : SET_BIT(PORTC_REG,u8PinId); break;
		case DIO_PORTD : SET_BIT(PORTD_REG,u8PinId); break;
		}
	}
	else
	{
		/* Wrong PORT ID or PIN ID*/
	}
}

void DIO_VidSetPortDir(u8 u8PortId, u8 u8PortDir)
{
	switch(u8PortId)
	{
	case DIO_PORTA : DDRA_REG = u8PortDir; break;
	case DIO_PORTB : DDRB_REG = u8PortDir; break;
	case DIO_PORTC : DDRC_REG = u8PortDir; break;
	case DIO_PORTD : DDRD_REG = u8PortDir; break;
	default : /* Wrong Port Id			 */ break;
	}
}

void DIO_VidSetPortVal(u8 u8PortId, u8 u8PortVal)
{
	switch(u8PortId)
	{
	case DIO_PORTA : PORTA_REG = u8PortVal; break;
	case DIO_PORTB : PORTB_REG = u8PortVal; break;
	case DIO_PORTC : PORTC_REG = u8PortVal; break;
	case DIO_PORTD : PORTD_REG = u8PortVal; break;
	default : /* Wrong Port Id			 */ break;
	}
}
