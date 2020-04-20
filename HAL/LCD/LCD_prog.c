/*
 * LCD_prog.c
 *
 *  Created on : Apr 2, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafarwy
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"


#include "../../MCAL/DIO/DIO_int.h"


#include "LCD_config.h"
#include "LCD_priv.h"
#include  <util/delay.h>




/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuInit.                                          **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Setting initial Commands & direction of its DIO pins. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuInit (void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	/****************************************************/
	/*********  Set Control Pins LCD to OUTPUT  *********/
	/****************************************************/
	DIO_enuSetPinDirection(RS_PORT, RS_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN , DIO_PIN_OUTPUT);
	/****************************************************/
	/****************************************************/

	/****************************************************/
	/*********   Set Data Pins' LCD to OUTPUT   *********/
	/****************************************************/

	DIO_enuSetPinDirection(D7_PORT, D7_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN , DIO_PIN_OUTPUT);

	/****************************************************/
	/****************************************************/

#if LCD_MODE == EIGHT_BIT


	/****************************************************/
	/*********   Set Data Pins' LCD to OUTPUT   *********/
	/****************************************************/
	DIO_enuSetPinDirection(D3_PORT, D3_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN , DIO_PIN_OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN , DIO_PIN_OUTPUT);
	/****************************************************/
	/****************************************************/

	/****************************************************/
	/*********      Set The Command TO LCD      *********/
	/****************************************************/

	/*********       Wait LCD to POWER ON       *********/
	_delay_ms(35);

	LCD_enuSendCommand(EIGHT_BIT_MODE);
	/****************************************************/
	/****************************************************/
	error_enuState = ES_OK;

#elif LCD_MODE == FOUR_BIT

	/****************************************************/
	/*********      Set The Command TO LCD      *********/
	/****************************************************/

	/*********       Wait LCD to POWER ON       *********/
	_delay_ms(35);

	LCD_enuSendCommand(FOUR_BIT_MODE);
	/****************************************************/
	/****************************************************/
	error_enuState = ES_OK;
#else
	error_enuState = ES_ES_OUT_OF_RANGE;
#error	"Attention, your selection Mode is Wrong"
#endif

	/*********     Wait LCD to Scan Command     *********/
	_delay_ms(1);

	LCD_enuSendCommand(DISPLAY_ON_CURSOR_BLINK);

	/*********     Wait LCD to Scan Command     *********/
	_delay_ms(1);

	LCD_enuSendCommand(CLEAR_DISPLAY);

	/*********     Wait LCD to Scan Command     *********/
	_delay_ms(2);

	//LCD_enuSendCommand(SHIFT_ENTRIE_DISPLAY_TO_LEFT);

	/*********     Wait LCD to Scan Command     *********/
	//_delay_ms(1);

	LCD_enuSendCommand(INCREMENT_CURSOR_TO_RIGHT);

	/*********     Wait LCD to Scan Command     *********/
	_delay_ms(1);

	LCD_enuSendCommand(FORCE_CURSOR_START_FIRST_LINE);

	/****************************************************/
	/****************************************************/
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuSendCommand.                                   **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Command Value.                                        **/
/** Functionality   : Writing Commands to LCD within Run time.              **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuSendCommand (u8 Copy_u8Command)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	/****************************************************/
	/*********     Write Command (RS_PIN=0)     *********/
	/****************************************************/

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_PIN_LOW);

	/****************************************************/
	/****************************************************/


	/****************************************************/
	/*********       Send Command  To LCD       *********/
	/****************************************************/

	LCD_enuLatch (Copy_u8Command);

	/****************************************************/
	/****************************************************/
	error_enuState = ES_OK;
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuSendChar.                                      **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Character Value.                                      **/
/** Functionality   : Writing Characters to LCD within Run time.            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuSendChar (u8 Copy_u8Char)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	/****************************************************/
	/*********      Write Data (RS_PIN= 1)      *********/
	/****************************************************/

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_PIN_HIGH);

	/****************************************************/
	/****************************************************/


	/****************************************************/
	/*********      Send Character  To LCD      *********/
	/****************************************************/

	LCD_enuLatch (Copy_u8Char);

	/****************************************************/
	/****************************************************/
	error_enuState = ES_OK;
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuSendString.                                    **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to String.                                    **/
/** Functionality   : Writing Strings to LCD within Run time.               **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuSendString (char * Copy_Pu8String)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	while(*Copy_Pu8String)
	{
		LCD_enuSendChar(*Copy_Pu8String);
		if (!(*(Copy_Pu8String+1))) error_enuState =ES_OK;
		Copy_Pu8String++;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuGoToPosition.                                  **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Row and Column Number.                                **/
/** Functionality   : Forcing Cursor to start from Special Position.        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuGoToPosition (u8 Copy_u8Row , u8 Copy_u8Col)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	u8 Local_u8RowLocation [] = {FORCE_CURSOR_START_FIRST_LINE , FORCE_CURSOR_START_SECOND_LINE};
	LCD_enuSendCommand(Local_u8RowLocation [Copy_u8Row-LCD_ONE]+(Copy_u8Col-LCD_ONE));
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuSendExtraChar.                                 **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Row, Column Number and Ptr to Drawing Pattern.        **/
/** Functionality   : Writing Special Patterns to LCD within Run time.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuSendExtraChar (u8 Copy_u8RowPosition , u8 Copy_u8ColPosition , u8 *Copy_u8PExtraChar )
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	u8 Local_u8Iteration;

	LCD_enuSendCommand(GO_TO_CGRAM);
	for (Local_u8Iteration= LCD_ZERO; Local_u8Iteration <LCD_MAX_CGRAM ;Local_u8Iteration++)
	{
		LCD_enuSendChar(Copy_u8PExtraChar[Local_u8Iteration]);
	}

	LCD_enuSendCommand(FORCE_CURSOR_START_FIRST_LINE);
	LCD_enuGoToPosition(Copy_u8RowPosition, Copy_u8ColPosition);

	for (Local_u8Iteration= LCD_ZERO; Local_u8Iteration <=LCD_SEVEN ;Local_u8Iteration++)
	{
		LCD_enuSendChar(Local_u8Iteration);
	}
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuSendExtraChar.                                 **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Row, Column Number and Ptr to Drawing Pattern.        **/
/** Functionality   : Writing Special Patterns to LCD within Run time.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuSendSpecialNumber(u32 Copy_u32Number)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	u8 Local_u8Iteration , Local_u8NumOfDigits=LCD_ZERO;
	u32 Local_u32Reminder , Local_u8PowerTen ;
	Local_u32Reminder=Copy_u32Number;

	for (Local_u8Iteration = LCD_ONE ;  ; Local_u8Iteration++)
	{
		Copy_u32Number=Local_u32Reminder;
		Local_u8PowerTen=POWER_u32PowerNumbers( LCD_TEN , Local_u8Iteration);
		Copy_u32Number /= Local_u8PowerTen;

		if (! (Copy_u32Number))
		{
			Local_u8NumOfDigits=Local_u8Iteration;
			break;
		}
	}

	for (Local_u8Iteration = Local_u8NumOfDigits ; Local_u8Iteration > LCD_ZERO ;Local_u8Iteration--)
	{
		Copy_u32Number=Local_u32Reminder;
		Local_u8PowerTen=POWER_u32PowerNumbers( LCD_TEN , Local_u8Iteration - LCD_ONE);

		Local_u32Reminder  %= Local_u8PowerTen;

		Copy_u32Number /= (Local_u8PowerTen);

		LCD_enuSendChar (Copy_u32Number+'0');
	}
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LCD_enuLatch.                                         **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Sending Data.                                         **/
/** Functionality   : Writing Datas to LCD and Latching.                    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES LCD_enuLatch (u8 Copy_u8Data)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	/****************************************************/
	/*********     Write On LCD (RW_PIN= 0)     *********/
	/****************************************************/

	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_PIN_LOW);

	/****************************************************/
	/****************************************************/

	/****************************************************/
	/*********        Write Data  On LCD        *********/
	/****************************************************/

	if (Copy_u8Data == FOUR_BIT_MODE)
	{
		DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data >> LCD_SEVEN) & LCD_ONE));
		DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data >> LCD_SEX)   & LCD_ONE));
		DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data >> LCD_FIVE)  & LCD_ONE));
		DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data >> LCD_FOUR)  & LCD_ONE));

		/****************************************************/
		/*********         Latch on  EN_PIN         *********/
		/****************************************************/

		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_PIN_HIGH);
		_delay_us(1);
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_PIN_LOW);

		/****************************************************/
		/****************************************************/

		/****************************************************/
		/*********      Wait LCD  to Scan Data      *********/
		/****************************************************/
		_delay_ms(50);
		/****************************************************/
		/****************************************************/
	}

	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data >> LCD_SEVEN) & LCD_ONE));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data >> LCD_SEX)   & LCD_ONE));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data >> LCD_FIVE)  & LCD_ONE));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data >> LCD_FOUR)  & LCD_ONE));

#if 	LCD_MODE == EIGHT_BIT

	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Data >> LCD_THREE) & LCD_ONE));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Data >> LCD_TWO)   & LCD_ONE));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Data >> LCD_ONE)   & LCD_ONE));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Data >> LCD_ZERO)  & LCD_ONE));

#elif LCD_MODE == FOUR_BIT

	/****************************************************/
	/*********         Latch on  EN_PIN         *********/
	/****************************************************/

	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_PIN_HIGH);
	_delay_us(1);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_PIN_LOW);

	/****************************************************/
	/****************************************************/

	/****************************************************/
	/*********      Wait LCD  to Scan Data      *********/
	/****************************************************/
	_delay_ms(50);
	/****************************************************/
	/****************************************************/

	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data >> LCD_THREE) & LCD_ONE));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data >> LCD_TWO)   & LCD_ONE));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data >> LCD_ONE)   & LCD_ONE));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data >> LCD_ZERO)  & LCD_ONE));

#else
#error	"Attention, your selection Mode is Wrong"

#endif
	/****************************************************/
	/****************************************************/

	/****************************************************/
	/*********         Latch on  EN_PIN         *********/
	/****************************************************/

	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_PIN_HIGH);
	_delay_us(1);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_PIN_LOW);

	/****************************************************/
	/****************************************************/

	/****************************************************/
	/*********      Wait LCD  to Scan Data      *********/
	/****************************************************/
	//_delay_ms(50);
	/****************************************************/
	/****************************************************/

	error_enuState = ES_OK;
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : POWER_u32PowerNumbers.                                **/
/** Return Type     : u32.                                                  **/
/** Arguments       : Base Number and Power Number.                         **/
/** Functionality   : Getting the Power of any Integer Number.              **/
/*****************************************************************************/
/*****************************************************************************/
u32 POWER_u32PowerNumbers(u32 Copy_u32Number , u8 Copy_u8Power)
{
	u32 Local_u16Result = LCD_ONE ;
	u8 Local_u8Iteration ;

	for (Local_u8Iteration = LCD_ONE ; Local_u8Iteration <= Copy_u8Power ; Local_u8Iteration++)
	{
		Local_u16Result *=Copy_u32Number ;
	}

	return Local_u16Result ;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
