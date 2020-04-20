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
/**                    TIMER2 Libraries Inclusion                           **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#include "TIMER2_priv.h"
#include "TIMER2_config.h"
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
volatile u8  TIMER2_u8NumberOfOverflow=0;
volatile u8  TIMER2_u8Preload = 0;
volatile u32 TIMER2_u32StartDelay=0;
volatile u32 TIMER2_u32StopTime=0;
volatile u32 ISR_TIMER2_u32Counter=0;
volatile u32 ISR_TIMER2_u32ActionCounter=1;

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**   Global Pointers are dealing with Delay, Call back functions and ISR   **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
void (*TIMER2_APfunCallBack [TIMER2_CALL_BACK])(void*)= {NULL,NULL,NULL};
void  *TIMER2_APvidParameter[TIMER2_CALL_BACK]        = {NULL,NULL,NULL};
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuInit.                                       **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Setting the prescaler and mode.                       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuInit					(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
/***********************************************************/
/**              Selection TIMER0_PRESCALER               **/
/***********************************************************/
#if		TIMER2_PRESCALER == TIMER2_NO_CLOCK_SOURCE
	SET_TIMER2_NO_CLOCK_SOURCE;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_1
	SET_TIMER2_PRESCALER_1;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_8
	SET_TIMER2_PRESCALER_8;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_32
	SET_TIMER2_PRESCALER_32;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_64
	SET_TIMER2_PRESCALER_64;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_128
	SET_TIMER2_PRESCALER_128;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_256
	SET_TIMER2_PRESCALER_256;
	error_enuState = ES_OK;

#elif	TIMER2_PRESCALER == TIMER2_PRESCALER_1024
	SET_TIMER2_PRESCALER_1024;
	error_enuState = ES_OK;

#else
#error "Attention!!, your TIMER2_PRESCALER Selection is Wrong...."

#endif

/***********************************************************/
/**         Selection Mode and state of OC0_PIN           **/
/***********************************************************/
#if   TIMER2_MODE == TIMER2_OVER_FLOW
	SET_TIMER2_OVER_FLOW;

	#if   TIMER2_OC2_PIN_STATE == TIMER2_OVF_DISCONNECT_OC2
		SET_TIMER2_OVF_DISCONNECT_OC2;
		error_enuState = ES_OK;

	#else
	#error"Attention!!, you must disable OC2_PIN at overflow MODE...."
	#endif

#elif TIMER2_MODE == TIMER2_COMPARE_MATCH
	SET_TIMER2_COMPARE_MATCH;

	#if   TIMER2_OC2_PIN_STATE == TIMER2_CTC_DISCONNECT_OC2
		SET_TIMER2_CTC_DISCONNECT_OC2;
		error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_CTC_TOGGLE_OC2
		SET_TIMER2_CTC_TOGGLE_OC2;
		error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_CTC_CLEAR_OC2
		SET_TIMER2_CTC_CLEAR_OC2;
		error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_CTC_SET_OC2
		SET_TIMER2_CTC_SET_OC2;
		error_enuState = ES_OK;

	#else
	#error"Attention!!, OC2_PIN state is wrong or the mode is not CTC...."
	#endif

#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM
	SET_TIMER2_PHASE_CORRECT_PWM;

	#if   TIMER2_OC2_PIN_STATE == TIMER2_PHASE_CLEAR_CTC_SET_TOP
	SET_TIMER2_PHASE_CLEAR_CTC_SET_TOP;
	error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_PHASE_SET_CTC_CLEAR_TOP
	SET_TIMER2_PHASE_SET_CTC_CLEAR_TOP;
	error_enuState = ES_OK;

	#else
	#error"Attention!!, OC2_PIN state is wrong or the mode is not Phase Correct PWM...."
	#endif
#elif TIMER2_MODE == TIMER2_FAST_PWM
	SET_TIMER2_FAST_PWM;

	#if   TIMER2_OC2_PIN_STATE == TIMER2_FAST_PMW_CLEAR_CTC_SET_TOP
	SET_TIMER2_FAST_PMW_CLEAR_CTC_SET_TOP;
	error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_FAST_PMW_SET_CTC_CLEAR_TOP
	SET_TIMER2_FAST_PMW_SET_CTC_CLEAR_TOP;
	error_enuState = ES_OK;

	#else
	#error"Attention!!, OC2_PIN state is wrong or the mode is not Fast PWM...."
	#endif
#else
#error "Attention!!, your TIMER2_MODE Selection is Wrong...."
#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuSetPreload.                                 **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Preload Value.                                        **/
/** Functionality   : Assigning The Preload Value.                          **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuSetPreload					(u8 Copy_u8Preload)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER2_VIOD_SET_PRELOAD(Copy_u8Preload);

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuSetCTC_Value.                               **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : CTC Value.                                            **/
/** Functionality   : Assigning The CTC Value.                              **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuSetCTC_Value					(u8 Copy_u8CTC_Value)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER2_VIOD_SET_CTC_VALUE(Copy_u8CTC_Value);

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuEnableOVF_Interrupt.                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Enabling TIMER2 OVF Interrupt.                        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuEnableOVF_Interrupt					(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER2_VOID_ENABLE_OVF_INTERRUPT();

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuEnableCTC_Interrupt.                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Enabling TIMER2 CTC Interrupt.                        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuEnableCTC_Interrupt					(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER2_VOID_ENABLE_CTC_INTERRUPT();

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuDelayMilliSecond.                           **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Ptr to fun,Generic Ptr,Delay Time and Stop Time.      **/
/** Functionality   : Working at OVF mode at one and eight prescaler.       **/
/**	                : and any prescaler at CTC mode.                        **/
/**	                : Highest accuracy at CTC mode and 64_Prescaler.        **/
/**                 : Be ensure that OCR0_REG is assigned before Calling.   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuDelayMilliSecond 				(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter , u32 Copy_u32StartDelay , u32 Copy_u32StopTime)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

#if		TIMER2_PRESCALER == TIMER2_NO_CLOCK_SOURCE && TIMER2_MODE == TIMER2_OVER_FLOW
	#warning"Attention!!, TIMER2_PRESCALER is disabled so delay function has no effect..."

#elif  (TIMER2_PRESCALER == TIMER2_PRESCALER_1 || TIMER2_PRESCALER == TIMER2_PRESCALER_8)  && TIMER2_MODE == TIMER2_OVER_FLOW
	u16 Local_u16Counts= (TIMER2_F_CPU / TIMER2_PRESCALER);
	f32 Local_f32OVF_Counts = ((f32)Local_u16Counts / TIMER2_OVF_COUNTS);
	TIMER2_u8NumberOfOverflow = ((u8)Local_f32OVF_Counts +1);
	Local_f32OVF_Counts = Local_f32OVF_Counts - ((u32)Local_f32OVF_Counts) ;
	TIMER2_u8Preload = TIMER2_OVF_COUNTS - (Local_f32OVF_Counts * TIMER2_OVF_COUNTS);
	TIMER2_VIOD_SET_PRELOAD(TIMER2_u8Preload);

	TIMER2_u32StartDelay = Copy_u32StartDelay;
	TIMER2_u32StopTime = Copy_u32StopTime;
	TIMER2_APfunCallBack [TIMER2_DELAY_CALLBACK] = Copy_PfunCallBack;
	TIMER2_APvidParameter[TIMER2_DELAY_CALLBACK] = Copy_PvidParameter;
	error_enuState = ES_OK;

#elif (TIMER2_PRESCALER == TIMER2_PRESCALER_1 || TIMER2_PRESCALER == TIMER2_PRESCALER_8 || TIMER2_PRESCALER == TIMER2_PRESCALER_32 || TIMER2_PRESCALER == TIMER2_PRESCALER_64 || TIMER2_PRESCALER == TIMER2_PRESCALER_128 || TIMER2_PRESCALER == TIMER2_PRESCALER_256 || TIMER2_PRESCALER == TIMER2_PRESCALER_1024) && TIMER2_MODE == TIMER2_COMPARE_MATCH
#warning "Be ensure that OCR2_REG is assigned before Calling delay function...."
#warning "To take high accuracy on Delay function, Choose OVF mode and one or eight prescaler";\
 "OR CTC mode , 64 prescaler and OCR2 = 124 , 32 prescaler and OCR_REG = 249"
	if (OCR2_REG>0)
	{
		u16 Local_u16Counts= (TIMER2_F_CPU / TIMER2_PRESCALER);
		f32 Local_f32OVF_Counts = ((f32)Local_u16Counts / (OCR2_REG+1));
		if ((Local_f32OVF_Counts - ((u32)Local_f32OVF_Counts)) > 0 )
		{
			TIMER2_u8NumberOfOverflow = ((u8)Local_f32OVF_Counts +1);
			Local_f32OVF_Counts = Local_f32OVF_Counts - ((u32)Local_f32OVF_Counts) ;
			TIMER2_u8Preload = (OCR2_REG+1) - (Local_f32OVF_Counts * (OCR2_REG+1));
			TIMER2_VIOD_SET_PRELOAD(TIMER2_u8Preload);
		}
		else
		{
			TIMER2_u8NumberOfOverflow = ((u8)Local_f32OVF_Counts);
		}

		TIMER2_u32StartDelay = Copy_u32StartDelay;
		TIMER2_u32StopTime = Copy_u32StopTime;
		TIMER2_APfunCallBack [TIMER2_DELAY_CALLBACK] = Copy_PfunCallBack;
		TIMER2_APvidParameter[TIMER2_DELAY_CALLBACK] = Copy_PvidParameter;
		error_enuState = ES_OK;
	}
	else
	{
		error_enuState = ES_OUT_OF_RANGE;
	}
#else
#warning "Attention!!, Delay function (TIMER2) has no effect at this mode or prescaler...."
#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuGeneratePWM.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Duty cycle of PWM.                                    **/
/** Functionality   : At Fast PWM, the frequency equals :                   **/
/**	                : PRE_1= 31250 Hz, PRE_8= 39026.25 Hz, PRE_32= 976.6 Hz.**/
/**                 : PRE_64= 488.3 Hz,        PRE_128= 244.15 Hz.          **/
/**	                : PRE_256= 122 Hz,         PRE_1024= 30.5 Hz.           **/
/**	                                                                        **/
/**	                : At Phase Correct PWM, the frequency equals :          **/
/**	                : PRE_1= 15686.3 Hz, PRE_8= 1960.8 Hz, PRE_32= 490.2 Hz.**/
/**                 : PRE_64= 245.1 Hz,        PRE_128= 122.55 Hz.          **/
/**	                : PRE_256= 61.3 Hz, PRE_1024= 15.3 Hz.                  **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuGeneratePWM						(u8 Copy_u8DutyCycle )
{
	ERROR_STATES error_enuState = ES_NOT_OK;

#if   TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM

	#if   TIMER2_OC2_PIN_STATE == TIMER2_PHASE_CLEAR_CTC_SET_TOP
		u8 Local_u8OCR_Value = (TIMER2_PHASE_COUNTS * (f32)((f32)Copy_u8DutyCycle /(TIMER2_PERCENTAGE_RATIO * TIMER2_FIXED_NUM_TWO)));
		TIMER2_VIOD_SET_CTC_VALUE(Local_u8OCR_Value);
		error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_PHASE_SET_CTC_CLEAR_TOP
		u8 Local_u8OCR_Value = (TIMER2_PHASE_COUNTS / TIMER2_FIXED_NUM_TWO)-(TIMER2_PHASE_COUNTS * (f32)((f32)Copy_u8DutyCycle /(TIMER2_PERCENTAGE_RATIO * TIMER2_FIXED_NUM_TWO)));
		TIMER2_VIOD_SET_CTC_VALUE(Local_u8OCR_Value);
		error_enuState = ES_OK;

	#else
	#error"Attention!!, OC2_PIN state is wrong or the mode is not Phase Correct PWM...."
	#endif
#elif TIMER2_MODE == TIMER2_FAST_PWM
	#if   TIMER2_OC2_PIN_STATE == TIMER2_FAST_PMW_CLEAR_CTC_SET_TOP
		u8 Local_u8OCR_Value = ((f32)Copy_u8DutyCycle/TIMER2_PERCENTAGE_RATIO) * (f32)TIMER2_OVF_COUNTS;
		TIMER2_VIOD_SET_CTC_VALUE(--Local_u8OCR_Value);
		error_enuState = ES_OK;

	#elif TIMER2_OC2_PIN_STATE == TIMER2_FAST_PMW_SET_CTC_CLEAR_TOP
		u8 Local_u8OCR_Value = TIMER2_OVF_COUNTS - (TIMER2_OVF_COUNTS * ((f32)Copy_u8DutyCycle /TIMER2_PERCENTAGE_RATIO));
		TIMER2_VIOD_SET_CTC_VALUE(--Local_u8OCR_Value);
		error_enuState = ES_OK;

	#else
	#error"Attention!!, OC2_PIN state is wrong or the mode is not Fast PWM...."
	#endif
#else
#warning "Attention!!, Generation of PWM (TIMER2) doesn't work at this mode...."
#endif
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuCallBackOVF.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Ptr to fun,Generic Ptr.                               **/
/** Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuCallBackOVF						(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER2_APfunCallBack [TIMER2_OVF_CALLBACK] = Copy_PfunCallBack;
	TIMER2_APvidParameter[TIMER2_OVF_CALLBACK] = Copy_PvidParameter;
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : TIMER2_enuCallBackCTC.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Ptr to fun,Generic Ptr.                               **/
/** Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES TIMER2_enuCallBackCTC						(void (*Copy_PfunCallBack)(void*) , void * Copy_PvidParameter)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

	TIMER2_APfunCallBack [TIMER2_CTC_CALLBACK] = Copy_PfunCallBack;
	TIMER2_APvidParameter[TIMER2_CTC_CALLBACK] = Copy_PvidParameter;
	error_enuState = ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : ISR (__vector_4).                                    **/
/** Return Type     : void.                                                 **/
/** Arguments       : Number of interrupt vector.                           **/
/** Functionality   : Handling of TIMER4_CTC Interrupt.                     **/
/*****************************************************************************/
/*****************************************************************************/

ISR(TIMER2_CTC_VEC)
{
	if (TIMER2_APfunCallBack[TIMER2_DELAY_CALLBACK] != NULL && ISR_TIMER2_u32Counter == TIMER2_u8NumberOfOverflow * TIMER2_u32StartDelay && (ISR_TIMER2_u32ActionCounter * TIMER2_u32StartDelay) <= TIMER2_u32StopTime)
	{
		ISR_TIMER2_u32ActionCounter++;
		TIMER2_APfunCallBack[TIMER2_DELAY_CALLBACK](TIMER2_APvidParameter[TIMER2_DELAY_CALLBACK]);
		ISR_TIMER2_u32Counter=0;
	}
	else
	{
		ISR_TIMER2_u32Counter++;
		if ( (!(ISR_TIMER2_u32Counter % TIMER2_u8NumberOfOverflow)) && TIMER2_u8Preload )
		{
			TIMER2_VIOD_SET_PRELOAD(TIMER2_u8Preload);
		}
	}

	if (TIMER2_APfunCallBack[TIMER2_CTC_CALLBACK] != NULL)
	{
		TIMER2_APfunCallBack[TIMER2_CTC_CALLBACK](TIMER2_APvidParameter[TIMER2_CTC_CALLBACK]);
	}
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : ISR (__vector_5).                                    **/
/** Return Type     : void.                                                 **/
/** Arguments       : Number of interrupt vector.                           **/
/** Functionality   : Handling of TIMER2_OVF Interrupt.                     **/
/*****************************************************************************/
/*****************************************************************************/
ISR(TIMER2_OVF_VEC)
{
	if (TIMER2_APfunCallBack[TIMER2_DELAY_CALLBACK] != NULL && (ISR_TIMER2_u32Counter == (TIMER2_u8NumberOfOverflow * TIMER2_u32StartDelay)) && (ISR_TIMER2_u32ActionCounter * TIMER2_u32StartDelay) <= TIMER2_u32StopTime)
	{
		ISR_TIMER2_u32ActionCounter++;
		TIMER2_APfunCallBack[TIMER2_DELAY_CALLBACK](TIMER2_APvidParameter[TIMER2_DELAY_CALLBACK]);
		ISR_TIMER2_u32Counter=0;
	}
	else
	{
		ISR_TIMER2_u32Counter++;
		if ( ((ISR_TIMER2_u32Counter % TIMER2_u8NumberOfOverflow) ==0 ) && TIMER2_u8Preload !=0 )
		{
			TIMER2_VIOD_SET_PRELOAD(TIMER2_u8Preload);
		}
	}

	if (TIMER2_APfunCallBack[TIMER2_OVF_CALLBACK] != NULL)
	{
		TIMER2_APfunCallBack[TIMER2_OVF_CALLBACK](TIMER2_APvidParameter[TIMER2_OVF_CALLBACK]);
	}
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

