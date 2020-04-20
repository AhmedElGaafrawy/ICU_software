/*
 * main.c
 *
 *  Created on : Apr 20, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/AVR_REG.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../MCAL/TIMER2/TIMER2_int.h"

#include "../HAL/LCD/LCD_int.h"

#include "../SERVICE/ICU_soft_int.h"

int main ()
{
	ICU_Data Local_strData;
	Local_strData.ICU_softu8Flag=1;
	Local_strData.Timer0_u8OvfCounts =0;
	void * ptr = &Local_strData;
	u8 duty=0;
	u16 freq=0;
	DIO_PINS_enuInit();
	LCD_enuInit();
	EXT_INT_enuInit();
	TIMER0_enuInit();
	TIMER2_enuInit();

	EXT_INT_enuSelectSenceLevel(RISING_EDAGE_INT0);
	EXT_INT_enuCallBackFunction(ICU_soft_enuCaptureWave , ptr , INT0);

	TIMER0_enuEnableOVF_Interrupt();
	TIMER0_enuCallBackOVF(ICU_soft_enuTimerCounter , ptr);

	TIMER2_enuGeneratePWM(50);
	GIE_enuEnable();

	while (1)
	{
		duty= ((f32)(Local_strData.ICU_soft_u8TimeOn*100.0) /(Local_strData.ICU_soft_u8TimeOn + Local_strData.ICU_soft_u8TimeOff));
		freq = (1000000ul / (Local_strData.ICU_soft_u8TimeOn + Local_strData.ICU_soft_u8TimeOff));
		LCD_enuGoToPosition(1,1);
		LCD_enuSendString("Duty = ");
		LCD_enuGoToPosition(1,8);
		LCD_enuSendSpecialNumber(duty);
		LCD_enuGoToPosition(1,11);
		LCD_enuSendChar('%');
		LCD_enuGoToPosition(2,1);
		LCD_enuSendString("freq = ");
		LCD_enuGoToPosition(2,8);
		LCD_enuSendSpecialNumber(freq);
		LCD_enuGoToPosition(2,13);
		LCD_enuSendString("Hz");
		LCD_enuSendCommand(CLEAR_DISPLAY);
	}
	return 0;
}
