/*
 * LCD_priv.h
 *
 *  Created on : Apr 2, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_
/*****************************************************************************/
/**                                                                         **/
/**            Prototype of Function for internal usage                     **/
/**                                                                         **/
/*****************************************************************************/
ERROR_STATES LCD_enuLatch (u8 Copy_u8Data);

ERROR_STATES LCD_enuSendCommand (u8 Copy_u8Command);

ERROR_STATES LCD_enuSendChar (u8 Copy_u8Char);

u32 POWER_u32PowerNumbers(u32 Copy_u32Number , u8 Copy_u8Power);

ERROR_STATES LCD_enuGoToPosition (u8 Copy_u8Row , u8 Copy_u8Col);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**          Definitions of Commands written to LCD Display                 **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define		CLEAR_DISPLAY									0x01

#define 	RETURN_HOME										0x02

#define 	DECREMENT_CURSOR_TO_LEFT						0x04
#define 	INCREMENT_CURSOR_TO_RIGHT						0x06

#define 	SHIFT_DISPLAY_TO_RIGHT							0x05
#define 	SHIFT_DISPLAY_TO_LEFT							0x07


#define 	DISPLAY_OFF_CURSOR_OFF							0x08
#define 	DISPLAY_OFF_CURSOR_ON							0x0A
#define 	DISPLAY_ON_CURSOR_OFF							0x0C
#define 	DISPLAY_ON_CURSOR_BLINK							0x0E


#define 	SHIFT_CURSOR_POSITION_TO_LEFT					0x10
#define 	SHIFT_CURSOR_POSITION_TO_RIGHT					0x14

#define 	SHIFT_ENTRIE_DISPLAY_TO_LEFT					0x18
#define 	SHIFT_ENTRIE_DISPLAY_TO_RIGHT					0x1C

#define 	FORCE_CURSOR_START_FIRST_LINE					0x80
#define 	FORCE_CURSOR_START_SECOND_LINE					0xC0

#define     GO_TO_CGRAM										0x40

#define		EIGHT_BIT_MODE									0x38
#define		FOUR_BIT_MODE									0x28
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**              Definitions of Modes of LCD Display                        **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define 	FOUR_BIT		0
#define 	EIGHT_BIT		1
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**         Definitions Special Numbers used with LCD Display               **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define 	LCD_ZERO		0
#define 	LCD_ONE			1
#define 	LCD_TWO			2
#define 	LCD_THREE		3
#define 	LCD_FOUR		4
#define 	LCD_FIVE		5
#define 	LCD_SEX			6
#define 	LCD_SEVEN		7
#define 	LCD_TEN			10
#define		LCD_MAX_CGRAM	64
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



#endif /* LCD_PRIV_H_ */









	/****************************************************/
	/****   Select OUTPUT REG  Connected TO RS PIN   ****/
	/****************************************************/
/*
#if		RS_PORT == DIO_PORT_A
#define 	RS_PORT_REG  PORTA

#elif	RS_PORT == DIO_PORT_B
#define 	RS_PORT_REG  PORTB

#elif	RS_PORT == DIO_PORT_C
#define 	RS_PORT_REG  PORTC_REG

#elif	RS_PORT == DIO_PORT_D
#define 	RS_PORT_REG  PORTD_REG

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO RW PIN   ****/
	/****************************************************/
/*

#if		RW_PORT == DIO_PORT_A
#define 	RW_PORT_REG  *((volatile u8*) 0x3B)

#elif	RW_PORT == DIO_PORT_B
#define 	RW_PORT_REG  *((volatile u8*) 0x38)

#elif	RW_PORT == DIO_PORT_C
#define 	RW_PORT_REG  *((volatile u8*) 0x35)

#elif	RW_PORT == DIO_PORT_D
#define 	RW_PORT_REG  *((volatile u8*) 0x32)

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO EN PIN   ****/
	/****************************************************/

/*
#if		EN_PORT == DIO_PORT_A
#define 	EN_PORT_REG  PORTA

#elif	EN_PORT == DIO_PORT_B
#define 	EN_PORT_REG  *((volatile u8*) 0x38)

#elif	EN_PORT == DIO_PORT_C
#define 	EN_PORT_REG  PORTC

#elif	EN_PORT == DIO_PORT_D
#define 	EN_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D0 PIN   ****/
	/****************************************************/

/*
#if		D0_PORT == DIO_PORT_A
#define 	D0_PORT_REG  PORTA

#elif	D0_PORT == DIO_PORT_B
#define 	D0_PORT_REG  PORTB

#elif	D0_PORT == DIO_PORT_C
#define 	D0_PORT_REG  PORTC

#elif	D0_PORT == DIO_PORT_D
#define 	D0_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D1 PIN   ****/
	/****************************************************/

/*
#if		D1_PORT == DIO_PORT_A
#define 	D1_PORT_REG  PORTA

#elif	D1_PORT == DIO_PORT_B
#define 	D1_PORT_REG  PORTB

#elif	D1_PORT == DIO_PORT_C
#define 	D1_PORT_REG  PORTC

#elif	D1_PORT == DIO_PORT_D
#define 	D1_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D2 PIN   ****/
	/****************************************************/

/*
#if		D2_PORT == DIO_PORT_A
#define 	D2_PORT_REG  PORTA

#elif	D2_PORT == DIO_PORT_B
#define 	D2_PORT_REG  PORTB

#elif	D2_PORT == DIO_PORT_C
#define 	D2_PORT_REG  PORTC

#elif	D2_PORT == DIO_PORT_D
#define 	D2_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D3 PIN   ****/
	/****************************************************/

/*
#if		D3_PORT == DIO_PORT_A
#define 	D3_PORT_REG  PORTA

#elif	D3_PORT == DIO_PORT_B
#define 	D3_PORT_REG  PORTB

#elif	D3_PORT == DIO_PORT_C
#define 	D3_PORT_REG  PORTC

#elif	D3_PORT == DIO_PORT_D
#define 	D3_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D4 PIN   ****/
	/****************************************************/

/*
#if		D4_PORT == DIO_PORT_A
#define 	D4_PORT_REG  PORTA

#elif	D4_PORT == DIO_PORT_B
#define 	D4_PORT_REG  PORTB

#elif	D4_PORT == DIO_PORT_C
#define 	D4_PORT_REG  PORTC

#elif	D4_PORT == DIO_PORT_D
#define 	D4_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D5 PIN   ****/
	/****************************************************/

/*
#if		D5_PORT == DIO_PORT_A
#define 	D5_PORT_REG  PORTA

#elif	D5_PORT == DIO_PORT_B
#define 	D5_PORT_REG  PORTB

#elif	D5_PORT == DIO_PORT_C
#define 	D5_PORT_REG  PORTC

#elif	D5_PORT == DIO_PORT_D
#define 	D5_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D6 PIN   ****/
	/****************************************************/
/*

#if		D6_PORT == DIO_PORT_A
#define 	D6_PORT_REG  PORTA

#elif	D6_PORT == DIO_PORT_B
#define 	D6_PORT_REG  PORTB

#elif	D6_PORT == DIO_PORT_C
#define 	D6_PORT_REG  PORTC

#elif	D6_PORT == DIO_PORT_D
#define 	D6_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/
	/****************************************************/
	/****   Select OUTPUT REG  Connected TO D7 PIN   ****/
	/****************************************************/

/*
#if		D7_PORT == DIO_PORT_A
#define 	D7_PORT_REG  PORTA

#elif	D7_PORT == DIO_PORT_B
#define 	D7_PORT_REG  PORTB

#elif	D7_PORT == DIO_PORT_C
#define 	D7_PORT_REG  PORTC

#elif	D7_PORT == DIO_PORT_D
#define 	D7_PORT_REG  PORTD

#else
#error	"Attention, your Port Selection is Wrong"
#endif
*/



/*
 #define PUT_BIT(reg1,index1,reg2,index2) reg2=(((reg1>>index1)&0x01)<<index2)^((reg2)&(~(1<<index2)))


 */
