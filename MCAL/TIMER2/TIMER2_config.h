/*
 * TIMER0_config.h
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef MCAL_TIMER2_CONFIG_H_
#define MCAL_TIMER2_CONFIG_H_



/*****************************************************************************/
/**                                                                         **/
/**     Definitions of TIMER2 PRESCALER configuration by the following :    **/
/**             TIMER2_NO_CLOCK_SOURCE  -  TIMER2_PRESCALER_1               **/
/**             TIMER2_PRESCALER_8      -  TIMER2_PRESCALER_32              **/
/**             TIMER2_PRESCALER_64     -  TIMER2_PRESCALER_128             **/
/**             TIMER2_PRESCALER_256    -  TIMER2_PRESCALER_1024            **/
/**                                                                         **/
/*****************************************************************************/
#define TIMER2_PRESCALER				TIMER2_PRESCALER_1024
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/**                                                                         **/
/**       Definitions of TIMER2 MODE configuration by the following :       **/
/**              TIMER2_OVER_FLOW  -  TIMER2_COMPARE_MATCH                  **/
/**              TIMER2_FAST_PWM   -  TIMER2_PHASE_CORRECT_PWM              **/
/**                                                                         **/
/*****************************************************************************/
#define TIMER2_MODE						TIMER2_PHASE_CORRECT_PWM
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/**                                                                         **/
/**          Definitions of TIMER2 OC2_PIN State by the following :         **/
/**                        TIMER2_OVF_DISCONNECT_OC2                        **/
/**          TIMER2_CTC_DISCONNECT_OC2   -   TIMER2_CTC_TOGGLE_OC2          **/
/**             TIMER2_CTC_CLEAR_OC2     -   TIMER2_CTC_SET_OC2             **/
/** TIMER2_FAST_PMW_CLEAR_CTC_SET_TOP  -  TIMER2_FAST_PMW_SET_CTC_CLEAR_TOP **/
/**    TIMER2_PHASE_CLEAR_CTC_SET_TOP  -  TIMER2_PHASE_SET_CTC_CLEAR_TOP    **/
/**                                                                         **/
/*****************************************************************************/
#define TIMER2_OC2_PIN_STATE			TIMER2_PHASE_CLEAR_CTC_SET_TOP
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



#endif /* MCAL_TIMER2_CONFIG_H_ */
