/*
 * TIMER0_prog.c
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                          Libraries Inclusion                            **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**              Global Interrupt Library Inclusion                         **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#include "../GIE/GIE_priv.h"

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                    TIMER0 Libraries Inclusion                           **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#include "../TIMER0/TIMER0_config.h"
#include "../TIMER0/TIMER0_priv.h"
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**      Global Variables are dealing with Delay function and ISR           **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
volatile u8  TIMER0_u8NumberOfOverflow=0;
volatile u8  TIMER0_u8Preload = 0;
volatile u32 TIMER0_u32StartDelay=0;
volatile u32 TIMER0_u32StopTime=0;
volatile u32 ISR_u32Counter=0;
volatile u32 ISR_u32ActionCounter=1;

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**   Global Pointers are dealing with Delay, Call back functions and ISR   **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
void (*TIMER0_APfunCallBack [TIMER0_CALL_BACK])(void*)= {NULL,NULL,NULL};
void  *TIMER0_APvidParameter[TIMER0_CALL_BACK]        = {NULL,NULL,NULL};
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuInit.                                       **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Setting the prescaler and mode.                       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuInit					(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
/***********************************************************/
/**              Selection TIMER0_PRESCALER               **/
/***********************************************************/
#if		TIMER0_PRESCALER == TIMER0_NO_CLOCK_SOURCE
	SET_TIMER0_NO_CLOCK_SOURCE;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_PRESCALER_1
	SET_TIMER0_PRESCALER_1;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_PRESCALER_8
	SET_TIMER0_PRESCALER_8;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_PRESCALER_64
	SET_TIMER0_PRESCALER_64;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_PRESCALER_256
	SET_TIMER0_PRESCALER_256;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_PRESCALER_1024
	SET_TIMER0_PRESCALER_1024;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_EXT_CLOCK_FALLING_EDGE
	SET_TIMER0_EXT_CLOCK_FALLING_EDGE;
	error_enuState = ES_OK;

#elif	TIMER0_PRESCALER == TIMER0_EXT_CLOCK_RISING_EDGE
	SET_TIMER0_EXT_CLOCK_RISING_EDGE;
	error_enuState = ES_OK;

#else
#error "Attention!!, your TIMER0_PRESCALER Selection is Wrong...."

#endif

/***********************************************************/
/**         Selection Mode and state of OC0_PIN           **/
/***********************************************************/
#if   TIMER0_MODE == TIMER0_OVER_FLOW
	SET_TIMER0_OVER_FLOW;

	#if   TIMER0_OC0_PIN_STATE == TIMER0_OVF_DISCONNECT_OC0
		SET_TIMER0_OVF_DISCONNECT_OC0;
		error_enuState = ES_OK;

	#else
	#error"Attention!!, you must disable OC0_PIN at overflow MODE...."
	#endif

#elif TIMER0_MODE == TIMER0_COMPARE_MATCH
	SET_TIMER0_COMPARE_MATCH;

	#if   TIMER0_OC0_PIN_STATE == TIMER0_CTC_DISCONNECT_OC0
		SET_TIMER0_CTC_DISCONNECT_OC0;
		error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_CTC_TOGGLE_OC0
		SET_TIMER0_CTC_TOGGLE_OC0;
		error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_CTC_CLEAR_OC0
		SET_TIMER0_CTC_CLEAR_OC0;
		error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_CTC_SET_OC0
		SET_TIMER0_CTC_SET_OC0;
		error_enuState = ES_OK;

	#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not CTC...."
	#endif

#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM
	SET_TIMER0_PHASE_CORRECT_PWM;

	#if   TIMER0_OC0_PIN_STATE == TIMER0_PHASE_CLEAR_CTC_SET_TOP
	SET_TIMER0_PHASE_CLEAR_CTC_SET_TOP;
	error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_PHASE_SET_CTC_CLEAR_TOP
	SET_TIMER0_PHASE_SET_CTC_CLEAR_TOP;
	error_enuState = ES_OK;

	#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not Phase Correct PWM...."
	#endif
#elif TIMER0_MODE == TIMER0_FAST_PWM
	SET_TIMER0_FAST_PWM;

	#if   TIMER0_OC0_PIN_STATE == TIMER0_FAST_PMW_CLEAR_CTC_SET_TOP
	SET_TIMER0_FAST_PMW_CLEAR_CTC_SET_TOP;
	error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_FAST_PMW_SET_CTC_CLEAR_TOP
	SET_TIMER0_FAST_PMW_SET_CTC_CLEAR_TOP;
	error_enuState = ES_OK;

	#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not Fast PWM...."
	#endif
#else
#error "Attention!!, your TIMER0_MODE Selection is Wrong...."
#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuSetPreload.                                 **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Preload Value.                                        **/
/** Functionality   : Assigning The Preload Value.                          **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuSetPreload					(u8 Copy_u8Preload)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER0_VIOD_SET_PRELOAD(Copy_u8Preload);

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuSetCTC_Value.                               **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : CTC Value.                                            **/
/** Functionality   : Assigning The CTC Value.                              **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuSetCTC_Value					(u8 Copy_u8CTC_Value)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER0_VIOD_SET_CTC_VALUE(Copy_u8CTC_Value);

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuEnableOVF_Interrupt.                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Enabling TIMER0 OVF Interrupt.                        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuEnableOVF_Interrupt					(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER0_VOID_ENABLE_OVF_INTERRUPT();

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuEnableCTC_Interrupt.                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Enabling TIMER0 CTC Interrupt.                        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuEnableCTC_Interrupt					(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER0_VOID_ENABLE_CTC_INTERRUPT();

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuDelayMilliSecond.                           **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Ptr to fun,Generic Ptr,Delay Time and Stop Time.      **/
/** Functionality   : Working at OVF mode at one and eight prescaler.       **/
/**	                : and any prescaler at CTC mode.                        **/
/**	                : Highest accuracy at CTC mode and 64_Prescaler.        **/
/**                 : Be ensure that OCR0_REG is assigned before Calling.   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuDelayMilliSecond 				(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter , u32 Copy_u32StartDelay , u32 Copy_u32StopTime)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

#if		TIMER0_PRESCALER == TIMER0_NO_CLOCK_SOURCE && TIMER0_MODE == TIMER0_OVER_FLOW
	#warning"Attention!!, TIMER0_PRESCALER is disabled so delay function has no effect..."

#elif  (TIMER0_PRESCALER == TIMER0_PRESCALER_1 || TIMER0_PRESCALER == TIMER0_PRESCALER_8)  && TIMER0_MODE == TIMER0_OVER_FLOW
	u16 Local_u16Counts= (TIMER0_F_CPU / TIMER0_PRESCALER);
	f32 Local_f32OVF_Counts = ((f32)Local_u16Counts / TIMER0_OVF_COUNTS);
	TIMER0_u8NumberOfOverflow = ((u8)Local_f32OVF_Counts +1);
	Local_f32OVF_Counts = Local_f32OVF_Counts - ((u32)Local_f32OVF_Counts) ;
	TIMER0_u8Preload = TIMER0_OVF_COUNTS - (Local_f32OVF_Counts * TIMER0_OVF_COUNTS);
	TIMER0_VIOD_SET_PRELOAD(TIMER0_u8Preload);

	TIMER0_u32StartDelay = Copy_u32StartDelay;
	TIMER0_u32StopTime = Copy_u32StopTime;
	TIMER0_APfunCallBack [TIMER0_DELAY_CALLBACK] = Copy_PfunCallBack;
	TIMER0_APvidParameter[TIMER0_DELAY_CALLBACK] = Copy_PvidParameter;
	error_enuState = ES_OK;

#elif (TIMER0_PRESCALER == TIMER0_PRESCALER_1 || TIMER0_PRESCALER == TIMER0_PRESCALER_8 || TIMER0_PRESCALER == TIMER0_PRESCALER_64 || TIMER0_PRESCALER == TIMER0_PRESCALER_256 || TIMER0_PRESCALER == TIMER0_PRESCALER_1024) && TIMER0_MODE == TIMER0_COMPARE_MATCH
#warning "Be ensure that OCR0_REG is assigned before Calling delay function...."
	if (OCR0_REG>0)
	{
		u16 Local_u16Counts= (TIMER0_F_CPU / TIMER0_PRESCALER);
		f32 Local_f32OVF_Counts = ((f32)Local_u16Counts / (OCR0_REG+1));
		if ((Local_f32OVF_Counts - ((u32)Local_f32OVF_Counts)) > 0 )
		{
			TIMER0_u8NumberOfOverflow = ((u8)Local_f32OVF_Counts +1);
			Local_f32OVF_Counts = Local_f32OVF_Counts - ((u32)Local_f32OVF_Counts) ;
			TIMER0_u8Preload = (OCR0_REG+1) - (Local_f32OVF_Counts * (OCR0_REG+1));
			TIMER0_VIOD_SET_PRELOAD(TIMER0_u8Preload);
		}
		else
		{
			TIMER0_u8NumberOfOverflow = ((u8)Local_f32OVF_Counts);
		}

		TIMER0_u32StartDelay = Copy_u32StartDelay;
		TIMER0_u32StopTime = Copy_u32StopTime;
		TIMER0_APfunCallBack [TIMER0_DELAY_CALLBACK] = Copy_PfunCallBack;
		TIMER0_APvidParameter[TIMER0_DELAY_CALLBACK] = Copy_PvidParameter;
		error_enuState = ES_OK;
	}
	else
	{
		error_enuState = ES_OUT_OF_RANGE;
	}
#else
#warning "Attention!!, Delay function has no effect at this mode or prescaler...."
#warning "To take high accuracy on Delay function, Choose OVF mode and one or eight prescaler";\
 "OR CTC mode , 64 prescaler and OCR0 = 124"
#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuGeneratePWM.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Duty cycle of PWM.                                    **/
/** Functionality   : At Fast PWM, the frequency equals :                   **/
/**	                : PRE_1= 31250 Hz, PRE_8= 39026.25 Hz, PRE_64= 488.3 Hz.**/
/**	                : PRE_256= 122 Hz, PRE_1024= 30.5 Hz.                   **/
/**	                                                                        **/
/**	                : At Phase Correct PWM, the frequency equals :          **/
/**	                : PRE_1= 15686.3 Hz, PRE_8= 1960.8 Hz, PRE_64= 245.1 Hz.**/
/**	                : PRE_256= 61.3 Hz, PRE_1024= 15.3 Hz.                  **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuGeneratePWM						(u8 Copy_u8DutyCycle )
{
	ERROR_STATES error_enuState = ES_NOT_OK;

#if   TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM

	#if   TIMER0_OC0_PIN_STATE == TIMER0_PHASE_CLEAR_CTC_SET_TOP
		u8 Local_u8OCR_Value = (TIMER0_PHASE_COUNTS * (f32)((f32)Copy_u8DutyCycle /(TIMER0_PERCENTAGE_RATIO * TIMER0_FIXED_NUM_TWO)));
		TIMER0_VIOD_SET_CTC_VALUE(Local_u8OCR_Value);
		error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_PHASE_SET_CTC_CLEAR_TOP
		u8 Local_u8OCR_Value = (TIMER0_PHASE_COUNTS / TIMER0_FIXED_NUM_TWO)-(TIMER0_PHASE_COUNTS * (f32)((f32)Copy_u8DutyCycle /(TIMER0_PERCENTAGE_RATIO * TIMER0_FIXED_NUM_TWO)));
		TIMER0_VIOD_SET_CTC_VALUE(Local_u8OCR_Value);
		error_enuState = ES_OK;

	#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not Phase Correct PWM...."
	#endif
#elif TIMER0_MODE == TIMER0_FAST_PWM
	#if   TIMER0_OC0_PIN_STATE == TIMER0_FAST_PMW_CLEAR_CTC_SET_TOP
		u8 Local_u8OCR_Value = ((f32)Copy_u8DutyCycle/TIMER0_PERCENTAGE_RATIO) * (f32)TIMER0_OVF_COUNTS;
		TIMER0_VIOD_SET_CTC_VALUE(--Local_u8OCR_Value);
		error_enuState = ES_OK;

	#elif TIMER0_OC0_PIN_STATE == TIMER0_FAST_PMW_SET_CTC_CLEAR_TOP
		u8 Local_u8OCR_Value = TIMER0_OVF_COUNTS - (TIMER0_OVF_COUNTS * ((f32)Copy_u8DutyCycle /TIMER0_PERCENTAGE_RATIO));
		TIMER0_VIOD_SET_CTC_VALUE(--Local_u8OCR_Value);
		error_enuState = ES_OK;

	#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not Fast PWM...."
	#endif
#else
#warning "Attention!!, Generation of PWM doesn't work at this mode...."
#endif
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuCallBackOVF.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Ptr to fun,Generic Ptr.                               **/
/** Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuCallBackOVF						(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER0_APfunCallBack [TIMER0_OVF_CALLBACK] = Copy_PfunCallBack;
	TIMER0_APvidParameter[TIMER0_OVF_CALLBACK] = Copy_PvidParameter;
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER0_enuCallBackCTC.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Ptr to fun,Generic Ptr.                               **/
/** Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER0_enuCallBackCTC						(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER0_APfunCallBack [TIMER0_CTC_CALLBACK] = Copy_PfunCallBack;
	TIMER0_APvidParameter[TIMER0_CTC_CALLBACK] = Copy_PvidParameter;
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : ISR (__vector_10).                                    **/
/** Return Type     : void.                                                 **/
/** Arguments       : Number of interrupt vector.                           **/
/** Functionality   : Handling of TIMER0_CTC Interrupt.                     **/
/*****************************************************************************/
/*****************************************************************************/

ISR(TIMER0_CTC_VEC)
{
	if (TIMER0_APfunCallBack[TIMER0_DELAY_CALLBACK] != NULL && ISR_u32Counter == TIMER0_u8NumberOfOverflow * TIMER0_u32StartDelay && (ISR_u32ActionCounter * TIMER0_u32StartDelay) <= TIMER0_u32StopTime)
	{
		ISR_u32ActionCounter++;
		TIMER0_APfunCallBack[TIMER0_DELAY_CALLBACK](TIMER0_APvidParameter[TIMER0_DELAY_CALLBACK]);
		ISR_u32Counter=0;
	}
	else
	{
		ISR_u32Counter++;
		if ( (!(ISR_u32Counter % TIMER0_u8NumberOfOverflow)) && TIMER0_u8Preload )
		{
			TIMER0_VIOD_SET_PRELOAD(TIMER0_u8Preload);
		}
	}

	if (TIMER0_APfunCallBack[TIMER0_CTC_CALLBACK] != NULL)
	{
		TIMER0_APfunCallBack[TIMER0_CTC_CALLBACK](TIMER0_APvidParameter[TIMER0_CTC_CALLBACK]);
	}
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : ISR (__vector_11).                                    **/
/** Return Type     : void.                                                 **/
/** Arguments       : Number of interrupt vector.                           **/
/** Functionality   : Handling of TIMER0_OVF Interrupt.                     **/
/*****************************************************************************/
/*****************************************************************************/
ISR(TIMER0_OVF_VEC)
{
	if (TIMER0_APfunCallBack[TIMER0_DELAY_CALLBACK] != NULL && (ISR_u32Counter == (TIMER0_u8NumberOfOverflow * TIMER0_u32StartDelay)) && (ISR_u32ActionCounter * TIMER0_u32StartDelay) <= TIMER0_u32StopTime)
	{
		ISR_u32ActionCounter++;
		TIMER0_APfunCallBack[TIMER0_DELAY_CALLBACK](TIMER0_APvidParameter[TIMER0_DELAY_CALLBACK]);
		ISR_u32Counter=0;
	}
	else
	{
		ISR_u32Counter++;
		if ( ((ISR_u32Counter % TIMER0_u8NumberOfOverflow) ==0 ) && TIMER0_u8Preload !=0 )
		{
			TIMER0_VIOD_SET_PRELOAD(TIMER0_u8Preload);
		}
	}

	if (TIMER0_APfunCallBack[TIMER0_OVF_CALLBACK] != NULL)
	{
		TIMER0_APfunCallBack[TIMER0_OVF_CALLBACK](TIMER0_APvidParameter[TIMER0_OVF_CALLBACK]);
	}
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

