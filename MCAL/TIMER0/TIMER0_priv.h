/*
 * TIMER0_priv.h
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef MCAL_TIMER0_PRIV_H_
#define MCAL_TIMER0_PRIV_H_

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                      Address of TIMER0 registers                        **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define TCCR0_REG									*((volatile u8*) 0x53)
#define TCNT0_REG									*((volatile u8*) 0x52)
#define OCR0_REG									*((volatile u8*) 0x5c)
#ifndef _TIMSK_REG_
#define	_TIMSK_REG_
#define TIMSK_REG									*((volatile u8*) 0x59)
#endif
#ifndef _TIFR_REG_
#define	_TIFR_REG_
#define TIFR_REG									*((volatile u8*) 0x58)
#endif
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                 Definitions of TIMER0 configuration                     **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/**    Definitions of some Constant Number using in TIMER0 Calculations     **/
/*****************************************************************************/
#define TIMER0_F_CPU								8000
#define TIMER0_OVF_COUNTS							256
#define TIMER0_PHASE_COUNTS							510
#define TIMER0_PERCENTAGE_RATIO						100.0
#define TIMER0_FIXED_NUM_TWO						2.0
/*****************************************************************************/


/*****************************************************************************/
/**                 Definitions of Call back Pointers                       **/
/*****************************************************************************/
#define TIMER0_DELAY_CALLBACK						0
#define TIMER0_OVF_CALLBACK							1
#define TIMER0_CTC_CALLBACK							2
#define TIMER0_CALL_BACK							3
/*****************************************************************************/


/*****************************************************************************/
/**            Definitions of Vector Number of TIMER0 OVF and CTC           **/
/*****************************************************************************/
#define TIMER0_OVF_VEC								__vector_11
#define TIMER0_CTC_VEC								__vector_10
/*****************************************************************************/



/*****************************************************************************/
/**            Definitions of TIMER0 PRESCALER configuration                **/
/*****************************************************************************/
#define TIMER0_NO_CLOCK_SOURCE						0

#define TIMER0_PRESCALER_1							1

#define TIMER0_PRESCALER_8							8

#define TIMER0_PRESCALER_64							64

#define TIMER0_PRESCALER_256						256

#define TIMER0_PRESCALER_1024						1024

#define TIMER0_EXT_CLOCK_FALLING_EDGE				13

#define TIMER0_EXT_CLOCK_RISING_EDGE				15


#define SET_TIMER0_NO_CLOCK_SOURCE					TCCR0_REG&=~(1<<0)&(~(1<<1))&(~(1<<2))

#define SET_TIMER0_PRESCALER_1						TCCR0_REG&=~(1<<1)&(~(1<<2));\
													TCCR0_REG|=(1<<0)

#define SET_TIMER0_PRESCALER_8						TCCR0_REG&=~(1<<0)&(~(1<<2));\
													TCCR0_REG|=(1<<1)

#define SET_TIMER0_PRESCALER_64						TCCR0_REG&=~(1<<2);\
													TCCR0_REG|=(1<<0)|(1<<1)

#define SET_TIMER0_PRESCALER_256					TCCR0_REG&=~(1<<0)&(~(1<<1));\
													TCCR0_REG|=(1<<2)

#define SET_TIMER0_PRESCALER_1024					TCCR0_REG&=~(1<<1);\
													TCCR0_REG|=(1<<0)|(1<<2)

#define SET_TIMER0_EXT_CLOCK_FALLING_EDGE			TCCR0_REG&=~(1<<0);\
													TCCR0_REG|=(1<<1)|(1<<2)

#define SET_TIMER0_EXT_CLOCK_RISING_EDGE			TCCR0_REG|=(1<<0)|(1<<1)|(1<<2)
/*****************************************************************************/




/*****************************************************************************/
/**              Definitions of TIMER0 MODE configuration                   **/
/*****************************************************************************/
#define TIMER0_OVER_FLOW							17

#define TIMER0_COMPARE_MATCH						19

#define TIMER0_PHASE_CORRECT_PWM					21

#define TIMER0_FAST_PWM								23


#define SET_TIMER0_OVER_FLOW						TCCR0_REG&=~(1<<3)&(~(1<<6))

#define SET_TIMER0_COMPARE_MATCH					TCCR0_REG&=~(1<<6);\
													TCCR0_REG|=(1<<3)

#define SET_TIMER0_PHASE_CORRECT_PWM				TCCR0_REG&=~(1<<3);\
													TCCR0_REG|=(1<<6)

#define SET_TIMER0_FAST_PWM							TCCR0_REG|=(1<<3)|(1<<6)
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**             Definitions of TIMER0 OC0_PIN configuration                 **/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/**           Definitions of TIMER0 OC0_PIN State at OVF_MODE               **/
/*****************************************************************************/
#define TIMER0_OVF_DISCONNECT_OC0					25

#define SET_TIMER0_OVF_DISCONNECT_OC0				TCCR0_REG&=~(1<<4)&(~(1<<5))
/*****************************************************************************/


/*****************************************************************************/
/**           Definitions of TIMER0 OC0_PIN State at CTC_MODE               **/
/*****************************************************************************/
#define TIMER0_CTC_DISCONNECT_OC0					27

#define TIMER0_CTC_TOGGLE_OC0						29

#define TIMER0_CTC_CLEAR_OC0						31

#define TIMER0_CTC_SET_OC0							33


#define SET_TIMER0_CTC_DISCONNECT_OC0				TCCR0_REG&=~(1<<4)&(~(1<<5))

#define SET_TIMER0_CTC_TOGGLE_OC0					TCCR0_REG&=~(1<<5);\
													TCCR0_REG|=(1<<4)

#define SET_TIMER0_CTC_CLEAR_OC0					TCCR0_REG&=~(1<<4);\
													TCCR0_REG|=(1<<5)

#define SET_TIMER0_CTC_SET_OC0						TCCR0_REG|=(1<<4)|(1<<5)
/*****************************************************************************/


/*****************************************************************************/
/**        Definitions of TIMER0 OC0_PIN State at FAST_PWM_MODE             **/
/*****************************************************************************/
#define TIMER0_FAST_PMW_CLEAR_CTC_SET_TOP			35

#define TIMER0_FAST_PMW_SET_CTC_CLEAR_TOP			37


#define SET_TIMER0_FAST_PMW_CLEAR_CTC_SET_TOP		TCCR0_REG&=~(1<<4);\
													TCCR0_REG|=(1<<5)

#define SET_TIMER0_FAST_PMW_SET_CTC_CLEAR_TOP		TCCR0_REG|=(1<<4)|(1<<5)
/*****************************************************************************/


/*****************************************************************************/
/**     Definitions of TIMER0 OC0_PIN State at PHASE_CORRECT_PWM_MODE       **/
/*****************************************************************************/
#define TIMER0_PHASE_CLEAR_CTC_SET_TOP				39

#define TIMER0_PHASE_SET_CTC_CLEAR_TOP				41


#define SET_TIMER0_PHASE_CLEAR_CTC_SET_TOP			TCCR0_REG&=~(1<<4);\
													TCCR0_REG|=(1<<5)

#define SET_TIMER0_PHASE_SET_CTC_CLEAR_TOP			TCCR0_REG|=(1<<4)|(1<<5)
/*****************************************************************************/


/*****************************************************************************/
/**     Definitions of TIMER0 OC0_PIN State at PHASE_CORRECT_PWM_MODE       **/
/*****************************************************************************/
#define TIMER0_VIOD_SET_PRELOAD(COPY_U8PRELOAD)			TCNT0_REG=COPY_U8PRELOAD

#define TIMER0_VIOD_SET_CTC_VALUE(COPY_U8CTC_VALUE)		OCR0_REG=COPY_U8CTC_VALUE

#define TIMER0_VOID_ENABLE_OVF_INTERRUPT()				TIMSK_REG|=(1<<0);\
														TIMSK_REG&=~(1<<1)

#define TIMER0_VOID_ENABLE_CTC_INTERRUPT()				TIMSK_REG|=(1<<1);\
														TIMSK_REG&=~(1<<0)




/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

#endif /* MCAL_TIMER0_PRIV_H_ */
