/*
 * EXT_INT_prog.c
 *
 *  Created on: Apr 10, 2020
 *  Version		: 1.0.0
 *  Author		: Ahmed El-Gaafarwy
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"
#include "../../LIBRARY/AVR_REG.h"

#include "../GIE/GIE_priv.h"
#include "../GIE/GIE_int.h"

#include "EXT_INT_priv.h"
#include "EXT_INT_config.h"
#include "EXT_INT_int.h"

void (*EXT_INT_APF_CallBack  [EXT_INT_NUMs] )(void*)= {NULL,NULL,NULL};
void *EXT_INT_APvoidCallBack [EXT_INT_NUMs]         = {NULL,NULL,NULL};



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : EXT_INT_enuInit.                                      **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Setting which peripheral is enabled.                  **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES EXT_INT_enuInit				(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;

#if   ENABLE_PERIPHERALS == INT_ZERO
	SET_ENABLE_INT0;
	error_enuState = ES_OK;
#elif ENABLE_PERIPHERALS == INT_ONE
	SET_ENABLE_INT1;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_TWO
	SET_ENABLE_INT2;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_ONE
	SET_ENABLE_INT0;
	SET_ENABLE_INT1;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_TWO
	SET_ENABLE_INT0;
	SET_ENABLE_INT2;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_ONE_AND_TWO
	SET_ENABLE_INT1;
	SET_ENABLE_INT2;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_ONE_AND_TWO
	SET_ENABLE_INT2;
	SET_ENABLE_INT0;
	SET_ENABLE_INT1;
	error_enuState = ES_OK;

#else
#error"Attention!!!, your peripheral selection is wrong"
#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : EXT_INT_enuSelectSenceLevel.                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Sense Level of any EXT_INT.                           **/
/**	Functionality   : Setting the Sense Level of any EXT_INT.               **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES EXT_INT_enuSelectSenceLevel	(u8 Copy_u8SenseLevel)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
#if   ENABLE_PERIPHERALS == INT_ZERO
	switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL_INT0:
			SET_LOW_LEVEL_INT0;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT0:
			SET_ANY_LOGICAL_CHANGE_INT0;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT0:
			SET_FALLING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT0:
			SET_RISING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ONE
	switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL_INT1:
			SET_LOW_LEVEL_INT1;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT1:
			SET_ANY_LOGICAL_CHANGE_INT1;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT1:
			SET_FALLING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT1:
			SET_RISING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_TWO
	switch(Copy_u8SenseLevel)
		{
		case FALLING_EDAGE_INT2:
			SET_FALLING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT2:
			SET_RISING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_ONE
	switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL_INT0:
			SET_LOW_LEVEL_INT0;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT0:
			SET_ANY_LOGICAL_CHANGE_INT0;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT0:
			SET_FALLING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT0:
			SET_RISING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;
		case LOW_LEVEL_INT1:
			SET_LOW_LEVEL_INT1;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT1:
			SET_ANY_LOGICAL_CHANGE_INT1;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT1:
			SET_FALLING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT1:
			SET_RISING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_TWO
	switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL_INT0:
			SET_LOW_LEVEL_INT0;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT0:
			SET_ANY_LOGICAL_CHANGE_INT0;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT0:
			SET_FALLING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT0:
			SET_RISING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;

		case FALLING_EDAGE_INT2:
			SET_FALLING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT2:
			SET_RISING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ONE_AND_TWO
	switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL_INT1:
			SET_LOW_LEVEL_INT1;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT1:
			SET_ANY_LOGICAL_CHANGE_INT1;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT1:
			SET_FALLING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT1:
			SET_RISING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;

		case FALLING_EDAGE_INT2:
			SET_FALLING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT2:
			SET_RISING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_ONE_AND_TWO
	switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL_INT0:
			SET_LOW_LEVEL_INT0;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT0:
			SET_ANY_LOGICAL_CHANGE_INT0;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT0:
			SET_FALLING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT0:
			SET_RISING_EDAGE_INT0;
			error_enuState = ES_OK;
			break;
		case LOW_LEVEL_INT1:
			SET_LOW_LEVEL_INT1;
			error_enuState = ES_OK;
			break;
		case ANY_LOGICAL_CHANGE_INT1:
			SET_ANY_LOGICAL_CHANGE_INT1;
			error_enuState = ES_OK;
			break;
		case FALLING_EDAGE_INT1:
			SET_FALLING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT1:
			SET_RISING_EDAGE_INT1;
			error_enuState = ES_OK;
			break;

		case FALLING_EDAGE_INT2:
			SET_FALLING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;
		case RISING_EDAGE_INT2:
			SET_RISING_EDAGE_INT2;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#else
#error"Attention!!!, your peripheral selection is wrong"
#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : EXT_INT_enuCallBackFunction.                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Ptr to void func , its generic Ptr and num of EXT_INT.**/
/**	Functionality   : Calling back the function to run at ISR Handler.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES EXT_INT_enuCallBackFunction	(void(*Copy_PF_CallBack)(void*) , void* Copy_PvoidParameter , u8 Copy_u8NumberOfINT)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
#if   ENABLE_PERIPHERALS == INT_ZERO
	EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO]   = Copy_PF_CallBack;
	EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO] = Copy_PvoidParameter;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_ONE
	EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO]   = Copy_PF_CallBack;
	EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO] = Copy_PvoidParameter;
	error_enuState = ES_OK;

#elif ENABLE_PERIPHERALS == INT_TWO
	EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ONE]   = Copy_PF_CallBack;
	EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ONE] = Copy_PvoidParameter;
	error_enuState = ES_OK;


#elif ENABLE_PERIPHERALS == INT_ZERO_AND_ONE
	switch(Copy_u8NumberOfINT)
		{
		case INT_ZERO:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		case INT_ONE:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_TWO
	switch(Copy_u8NumberOfINT)
		{
		case INT_ZERO:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		case INT_TWO:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ONE]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ONE] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ONE_AND_TWO
	switch(Copy_u8NumberOfINT)
		{
		case INT_ONE:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		case INT_TWO:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ONE]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ONE] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#elif ENABLE_PERIPHERALS == INT_ZERO_AND_ONE_AND_TWO
	switch(Copy_u8NumberOfINT)
		{
		case INT_ZERO:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		case INT_ONE:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ZERO-INT_ZERO] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		case INT_TWO:
			EXT_INT_APF_CallBack[Copy_u8NumberOfINT-INT_ONE]   = Copy_PF_CallBack;
			EXT_INT_APvoidCallBack[Copy_u8NumberOfINT-INT_ONE] = Copy_PvoidParameter;
			error_enuState = ES_OK;
			break;

		default :
			error_enuState = ES_OUT_OF_RANGE;
			break;
		}

#else
#error"Attention!!!, your peripheral selection is wrong"
#endif


	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ISR (__vector_1).                                     **/
/**	Return Type     : void.                                                 **/
/**	Arguments       : Number of interrupt vector.                           **/
/**	Functionality   : Handling of EXT_INT0 Interrupt.                       **/
/*****************************************************************************/
/*****************************************************************************/
ISR(__vector_1)
{
	if (EXT_INT_APF_CallBack[INT_ZERO - INT_ZERO] != NULL)
	{
		EXT_INT_APF_CallBack[INT_ZERO - INT_ZERO] ( EXT_INT_APvoidCallBack[INT_ZERO - INT_ZERO] );
	}
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ISR (__vector_2).                                     **/
/**	Return Type     : void.                                                 **/
/**	Arguments       : Number of interrupt vector.                           **/
/**	Functionality   : Handling of EXT_INT1 Interrupt.                       **/
/*****************************************************************************/
/*****************************************************************************/
ISR(__vector_2)
{
	if (EXT_INT_APF_CallBack[INT_ZERO] != NULL)
	{
		EXT_INT_APF_CallBack[INT_ZERO] ( EXT_INT_APvoidCallBack[INT_ZERO] );
	}
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ISR (__vector_3).                                     **/
/**	Return Type     : void.                                                 **/
/**	Arguments       : Number of interrupt vector.                           **/
/**	Functionality   : Handling of EXT_INT2 Interrupt.                       **/
/*****************************************************************************/
/*****************************************************************************/
ISR(__vector_3)
{
	if (EXT_INT_APF_CallBack[INT_TWO - INT_ONE] != NULL)
	{
		EXT_INT_APF_CallBack[INT_TWO - INT_ONE] ( EXT_INT_APvoidCallBack[INT_TWO - INT_ONE] );
	}
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
