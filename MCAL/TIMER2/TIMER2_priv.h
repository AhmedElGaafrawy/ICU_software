/*
 * TIMER0_priv.h
 *
 *  Created on : Apr 17, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef MCAL_TIMER2_PRIV_H_
#define MCAL_TIMER2_PRIV_H_

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                      Address of TIMER0 registers                        **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define TCCR2_REG									*((volatile u8*) 0x45)
#define TCNT2_REG									*((volatile u8*) 0x44)
#define OCR2_REG									*((volatile u8*) 0x43)
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
#define TIMER2_F_CPU								8000
#define TIMER2_OVF_COUNTS							256
#define TIMER2_PHASE_COUNTS							510
#define TIMER2_PERCENTAGE_RATIO						100.0
#define TIMER2_FIXED_NUM_TWO						2.0
/*****************************************************************************/


/*****************************************************************************/
/**                 Definitions of Call back Pointers                       **/
/*****************************************************************************/
#define TIMER2_DELAY_CALLBACK						0
#define TIMER2_OVF_CALLBACK							1
#define TIMER2_CTC_CALLBACK							2
#define TIMER2_CALL_BACK							3
/*****************************************************************************/


/*****************************************************************************/
/**            Definitions of Vector Number of TIMER0 OVF and CTC           **/
/*****************************************************************************/
#define TIMER2_OVF_VEC								__vector_5
#define TIMER2_CTC_VEC								__vector_4
/*****************************************************************************/



/*****************************************************************************/
/**            Definitions of TIMER0 PRESCALER configuration                **/
/*****************************************************************************/
#define TIMER2_NO_CLOCK_SOURCE						0

#define TIMER2_PRESCALER_1							1

#define TIMER2_PRESCALER_8							8

#define TIMER2_PRESCALER_32							32

#define TIMER2_PRESCALER_64							64

#define TIMER2_PRESCALER_128						128

#define TIMER2_PRESCALER_256						256

#define TIMER2_PRESCALER_1024						1024



#define SET_TIMER2_NO_CLOCK_SOURCE					TCCR2_REG&=~(1<<0)&(~(1<<1))&(~(1<<2))

#define SET_TIMER2_PRESCALER_1						TCCR2_REG&=~(1<<1)&(~(1<<2));\
													TCCR2_REG|=(1<<0)

#define SET_TIMER2_PRESCALER_8						TCCR2_REG&=~(1<<0)&(~(1<<2));\
													TCCR2_REG|=(1<<1)

#define SET_TIMER2_PRESCALER_32						TCCR2_REG&=~(1<<2);\
													TCCR2_REG|=(1<<0)|(1<<1)

#define SET_TIMER2_PRESCALER_64						TCCR2_REG&=~(1<<0)&(~(1<<1));\
													TCCR2_REG|=(1<<2)

#define SET_TIMER2_PRESCALER_128					TCCR2_REG&=~(1<<1);\
													TCCR2_REG|=(1<<0)|(1<<2)

#define SET_TIMER2_PRESCALER_256					TCCR2_REG&=~(1<<0);\
													TCCR2_REG|=(1<<1)|(1<<2)

#define SET_TIMER2_PRESCALER_1024					TCCR2_REG|=(1<<0)|(1<<1)|(1<<2)

/*****************************************************************************/




/*****************************************************************************/
/**              Definitions of TIMER0 MODE configuration                   **/
/*****************************************************************************/
#define TIMER2_OVER_FLOW							17

#define TIMER2_COMPARE_MATCH						19

#define TIMER2_PHASE_CORRECT_PWM					21

#define TIMER2_FAST_PWM								23


#define SET_TIMER2_OVER_FLOW						TCCR2_REG&=~(1<<3)&(~(1<<6))

#define SET_TIMER2_COMPARE_MATCH					TCCR2_REG&=~(1<<6);\
													TCCR2_REG|=(1<<3)

#define SET_TIMER2_PHASE_CORRECT_PWM				TCCR2_REG&=~(1<<3);\
													TCCR2_REG|=(1<<6)

#define SET_TIMER2_FAST_PWM							TCCR2_REG|=(1<<3)|(1<<6)
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**             Definitions of TIMER0 OC0_PIN configuration                 **/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/**           Definitions of TIMER0 OC0_PIN State at OVF_MODE               **/
/*****************************************************************************/
#define TIMER2_OVF_DISCONNECT_OC2					25

#define SET_TIMER2_OVF_DISCONNECT_OC2				TCCR2_REG&=~(1<<4)&(~(1<<5))
/*****************************************************************************/


/*****************************************************************************/
/**           Definitions of TIMER0 OC0_PIN State at CTC_MODE               **/
/*****************************************************************************/
#define TIMER2_CTC_DISCONNECT_OC2					27

#define TIMER2_CTC_TOGGLE_OC2						29

#define TIMER2_CTC_CLEAR_OC2						31

#define TIMER2_CTC_SET_OC2							33


#define SET_TIMER2_CTC_DISCONNECT_OC2				TCCR2_REG&=~(1<<4)&(~(1<<5))

#define SET_TIMER2_CTC_TOGGLE_OC2					TCCR2_REG&=~(1<<5);\
													TCCR2_REG|=(1<<4)

#define SET_TIMER2_CTC_CLEAR_OC2					TCCR2_REG&=~(1<<4);\
													TCCR2_REG|=(1<<5)

#define SET_TIMER2_CTC_SET_OC2						TCCR2_REG|=(1<<4)|(1<<5)
/*****************************************************************************/


/*****************************************************************************/
/**        Definitions of TIMER0 OC0_PIN State at FAST_PWM_MODE             **/
/*****************************************************************************/
#define TIMER2_FAST_PMW_CLEAR_CTC_SET_TOP			35

#define TIMER2_FAST_PMW_SET_CTC_CLEAR_TOP			37


#define SET_TIMER2_FAST_PMW_CLEAR_CTC_SET_TOP		TCCR2_REG&=~(1<<4);\
													TCCR2_REG|=(1<<5)

#define SET_TIMER2_FAST_PMW_SET_CTC_CLEAR_TOP		TCCR2_REG|=(1<<4)|(1<<5)
/*****************************************************************************/


/*****************************************************************************/
/**     Definitions of TIMER0 OC0_PIN State at PHASE_CORRECT_PWM_MODE       **/
/*****************************************************************************/
#define TIMER2_PHASE_CLEAR_CTC_SET_TOP				39

#define TIMER2_PHASE_SET_CTC_CLEAR_TOP				41


#define SET_TIMER2_PHASE_CLEAR_CTC_SET_TOP			TCCR2_REG&=~(1<<4);\
													TCCR2_REG|=(1<<5)

#define SET_TIMER2_PHASE_SET_CTC_CLEAR_TOP			TCCR2_REG|=(1<<4)|(1<<5)
/*****************************************************************************/


/*****************************************************************************/
/**     Definitions of TIMER0 OC0_PIN State at PHASE_CORRECT_PWM_MODE       **/
/*****************************************************************************/
#define TIMER2_VIOD_SET_PRELOAD(COPY_U8PRELOAD)			TCNT2_REG=COPY_U8PRELOAD

#define TIMER2_VIOD_SET_CTC_VALUE(COPY_U8CTC_VALUE)		OCR2_REG=COPY_U8CTC_VALUE

#define TIMER2_VOID_ENABLE_OVF_INTERRUPT()				TIMSK_REG|=(1<<6);\
														TIMSK_REG&=~(1<<7)

#define TIMER2_VOID_ENABLE_CTC_INTERRUPT()				TIMSK_REG|=(1<<7);\
														TIMSK_REG&=~(1<<6)
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

#endif /* MCAL_TIMER2_PRIV_H_ */
