/*
 * ICU_soft_prog.c
 *
 *  Created on : Apr 20, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/AVR_REG.h"

#include "../MCAL/TIMER0/TIMER0_int.h"

#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"

#include "ICU_soft_priv.h"
#include "ICU_soft_int.h"



void ICU_soft_enuCaptureWave(void * Copy_PvoidParameter)
{
	ICU_Data * Local_PstrData = (ICU_Data *)Copy_PvoidParameter;
	if (Local_PstrData->ICU_softu8Flag == 1)
	{
		Local_PstrData->Timer0_u8OvfCounts=0;
		Local_PstrData->ICU_softu8Flag=2;
		EXT_INT_enuSelectSenceLevel(FALLING_EDAGE_INT0);
		TIMER0_enuSetPreload(0);
	}
	else if (Local_PstrData->ICU_softu8Flag == 2)
	{
		Local_PstrData->ICU_soft_u8TimeOn =
			(f32)(TCNT0 + (TIMER_OVF_COUNTS * Local_PstrData->Timer0_u8OvfCounts))* (f32)(TIMER_PRESCALER / TIMER_F_CPU);
		Local_PstrData->Timer0_u8OvfCounts=0;
		Local_PstrData->ICU_softu8Flag=3;
		EXT_INT_enuSelectSenceLevel(RISING_EDAGE_INT0);
		TIMER0_enuSetPreload(0);
	}
	else if (Local_PstrData->ICU_softu8Flag == 3)
	{
		Local_PstrData->ICU_soft_u8TimeOff =
			(f32)(TCNT0 + (TIMER_OVF_COUNTS * Local_PstrData->Timer0_u8OvfCounts))* (f32)(TIMER_PRESCALER / TIMER_F_CPU);
		Local_PstrData->Timer0_u8OvfCounts=0;
		Local_PstrData->ICU_softu8Flag=1;
		TIMER0_enuSetPreload(0);
	}
}


void ICU_soft_enuTimerCounter (void * Copy_PvoidParameter)
{
	ICU_Data * Local_PstrData = (ICU_Data *)Copy_PvoidParameter;
	(Local_PstrData->Timer0_u8OvfCounts)++;
}
