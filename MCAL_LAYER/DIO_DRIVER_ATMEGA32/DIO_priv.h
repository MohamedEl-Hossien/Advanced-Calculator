/******************************************************/
/************* Date : 10/03/2024 **********************/
/************* File Name : DIO_Private ****************/
/************* Version : v1.0 *************************/
/************* Author : Mohamed Elhossien *************/
/******************************************************/

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/*PORT A REGISTERS DEFINITION */
#define PORTA_REG 		*((volatile u8*)0x3B)
#define DDRA_REG		*((volatile u8*)0x3A)
#define PINA_REG 		*((volatile u8*)0x39)

/*PORT B REGISTERS DEFINITION */
#define PORTB_REG  		*((volatile u8*)0x38)
#define DDRB_REG 		*((volatile u8*)0x37)
#define PINB_REG  		*((volatile u8*)0x36)

/*PORT C REGISTERS DEFINITION */
#define PORTC_REG  		*((volatile u8*)0x35)
#define DDRC_REG 		*((volatile u8*)0x34)
#define PINC_REG  		*((volatile u8*)0x33)

/*PORT D REGISTERS DEFINITION */
#define PORTD_REG  		*((volatile u8*)0x32)
#define DDRD_REG 		*((volatile u8*)0x31)
#define PIND_REG  		*((volatile u8*)0x30)


#define CONC(p7,p6,p5,p4,p3,p2,p1,p0)		CONCTemp(p7,p6,p5,p4,p3,p2,p1,p0)
#define CONCTemp(p7,p6,p5,p4,p3,p2,p1,p0)	0b##p7##p6##p5##p4##p3##p2##p1##p0

#endif /* DIO_PRIV_H_ */
