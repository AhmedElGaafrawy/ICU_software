/*
 * DIO_priv.h
 *
 *  Created on : Apr 2, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/*****************************************************************************/
/***********************     Most Popular Values      ************************/
/*****************************************************************************/

#define DIO_ONE				1
#define	PIN_INPUT			0
#define	PIN_OUTPUT			1

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/************************     Concatenation Macros      **********************/
/*****************************************************************************/

#define CONC_HELP(H,G,F,E,D,C,B,A)		0b##A##B##C##D##E##F##G##H
#define CONC_HELP2(H,G,F,E,D,C,B,A)		CONC_HELP(H,G,F,E,D,C,B,A)
#define CONC(H,G,F,E,D,C,B,A)			CONC_HELP2(H,G,F,E,D,C,B,A)

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/************   Concatenation of initial Ports ' Direction Value    **********/
/*****************************************************************************/

#define DIO_U8_PORTA_DIRECTION		CONC(DIO_U8_PIN0_DIRECTION  , DIO_U8_PIN1_DIRECTION  , DIO_U8_PIN2_DIRECTION  , DIO_U8_PIN3_DIRECTION  , DIO_U8_PIN4_DIRECTION  , DIO_U8_PIN5_DIRECTION  , DIO_U8_PIN6_DIRECTION  , DIO_U8_PIN7_DIRECTION)

#define DIO_U8_PORTB_DIRECTION		CONC(DIO_U8_PIN8_DIRECTION  , DIO_U8_PIN9_DIRECTION  , DIO_U8_PIN10_DIRECTION , DIO_U8_PIN11_DIRECTION , DIO_U8_PIN12_DIRECTION , DIO_U8_PIN13_DIRECTION , DIO_U8_PIN14_DIRECTION , DIO_U8_PIN15_DIRECTION)

#define DIO_U8_PORTC_DIRECTION		CONC(DIO_U8_PIN16_DIRECTION , DIO_U8_PIN17_DIRECTION , DIO_U8_PIN18_DIRECTION , DIO_U8_PIN19_DIRECTION , DIO_U8_PIN20_DIRECTION , DIO_U8_PIN21_DIRECTION , DIO_U8_PIN22_DIRECTION , DIO_U8_PIN23_DIRECTION)

#define DIO_U8_PORTD_DIRECTION		CONC(DIO_U8_PIN24_DIRECTION , DIO_U8_PIN25_DIRECTION , DIO_U8_PIN26_DIRECTION , DIO_U8_PIN27_DIRECTION , DIO_U8_PIN28_DIRECTION , DIO_U8_PIN29_DIRECTION , DIO_U8_PIN30_DIRECTION , DIO_U8_PIN31_DIRECTION)

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*********************   Naming of DIO Pins and Ports    *********************/
/*****************************************************************************/

typedef enum
{
	DIO_PORT_A,			DIO_PORT_B,			DIO_PORT_C,			DIO_PORT_D,

	DIO_PIN0=0,			DIO_PIN1,			DIO_PIN2,			DIO_PIN3,
	DIO_PIN4,			DIO_PIN5,			DIO_PIN6,			DIO_PIN7,
	DIO_PIN8,			DIO_PIN9,			DIO_PIN10,			DIO_PIN11,
	DIO_PIN12,			DIO_PIN13,			DIO_PIN14,			DIO_PIN15,
	DIO_PIN16,			DIO_PIN17,			DIO_PIN18,			DIO_PIN19,
	DIO_PIN20,			DIO_PIN21,			DIO_PIN22,			DIO_PIN23,
	DIO_PIN24,			DIO_PIN25,			DIO_PIN26,			DIO_PIN27,
	DIO_PIN28,			DIO_PIN29,			DIO_PIN30,			DIO_PIN31,

	ALL_PORT_LOW=0,				ALL_PORT_HIGH=0xff,
	ALL_PORT_INPUT=0,			ALL_PORT_OUTPUT=0xff,

	PIN_LOW=0,					PIN_HIGH=1,
}DIO_Info;

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/**********************   Definitions of NULL Address   **********************/
/*****************************************************************************/

#define NULL  ((void*)0)

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*********************   Definitions of DIO Registers    *********************/
/*****************************************************************************/

#define PORTA 	*((volatile u8*) 0x3B)
#define DDRA  	*((volatile u8*) 0x3A)
#define PINA  	*((volatile u8*) 0x39)

#define PORTB 	*((volatile u8*) 0x38)
#define DDRB  	*((volatile u8*) 0x37)
#define PINB  	*((volatile u8*) 0x36)

#define PORTC 	*((volatile u8*) 0x35)
#define DDRC  	*((volatile u8*) 0x34)
#define PINC  	*((volatile u8*) 0x33)

#define PORTD 	*((volatile u8*) 0x32)
#define DDRD  	*((volatile u8*) 0x31)
#define PIND  	*((volatile u8*) 0x30)

/*****************************************************************************/
/*****************************************************************************/


#endif /* DIO_PRIV_H_ */
