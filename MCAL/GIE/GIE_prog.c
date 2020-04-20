/*
 * GIE_prog.c
 *
 *  Created on: Apr 8, 2020
 *  Version		: 1.0.0
 *  Author		: Ahmed El-Gaafarwy
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"

#include "GIE_priv.h"


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : GIE_enuEnable.                                        **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling Global Interrupt.                            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES GIE_enuEnable	(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	if (IF_GIE_DISABLE)
	{
		ENABLE_GIE;
		error_enuState =ES_OK;
	}

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : GIE_enuDisable.                                       **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Disabling Global Interrupt.                           **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES GIE_enuDisable	(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	if (IF_GIE_ENABLE)
	{
		DISABLE_GIE;
		error_enuState =ES_OK;
	}

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
