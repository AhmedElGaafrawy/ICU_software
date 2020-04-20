/*
 * TIMER0_config.h
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef MCAL_TIMER0_CONFIG_H_
#define MCAL_TIMER0_CONFIG_H_



/*****************************************************************************/
/**                                                                         **/
/**     Definitions of TIMER0 PRESCALER configuration by the following :    **/
/**             TIMER0_NO_CLOCK_SOURCE  -  TIMER0_PRESCALER_1               **/
/**             TIMER0_PRESCALER_8      -  TIMER0_PRESCALER_64              **/
/**             TIMER0_PRESCALER_256    -  TIMER0_PRESCALER_1024            **/
/**      TIMER0_EXT_CLOCK_FALLING_EDGE  -  TIMER0_EXT_CLOCK_RISING_EDGE     **/
/**                                                                         **/
/*****************************************************************************/
#define TIMER0_PRESCALER				TIMER0_PRESCALER_1024
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/**                                                                         **/
/**       Definitions of TIMER0 MODE configuration by the following :       **/
/**              TIMER0_OVER_FLOW  -  TIMER0_COMPARE_MATCH                  **/
/**              TIMER0_FAST_PWM   -  TIMER0_PHASE_CORRECT_PWM              **/
/**                                                                         **/
/*****************************************************************************/
#define TIMER0_MODE						TIMER0_OVER_FLOW
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/**                                                                         **/
/**          Definitions of TIMER0 OC0_PIN State by the following :         **/
/**                        TIMER0_OVF_DISCONNECT_OC0                        **/
/**          TIMER0_CTC_DISCONNECT_OC0   -   TIMER0_CTC_TOGGLE_OC0          **/
/**             TIMER0_CTC_CLEAR_OC0     -   TIMER0_CTC_SET_OC0             **/
/** TIMER0_FAST_PMW_CLEAR_CTC_SET_TOP  -  TIMER0_FAST_PMW_SET_CTC_CLEAR_TOP **/
/**    TIMER0_PHASE_CLEAR_CTC_SET_TOP  -  TIMER0_PHASE_SET_CTC_CLEAR_TOP    **/
/**                                                                         **/
/*****************************************************************************/
#define TIMER0_OC0_PIN_STATE			TIMER0_OVF_DISCONNECT_OC0
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



#endif /* MCAL_TIMER0_CONFIG_H_ */
