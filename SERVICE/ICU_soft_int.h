/*
 * ICU_soft_int.h
 *
 *  Created on : Apr 20, 2020
 *  Version	   : 1.0.0
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef SERVICE_ICU_SOFT_INT_H_
#define SERVICE_ICU_SOFT_INT_H_

void ICU_soft_enuTimerCounter (void * Copy_PvoidParameter);

void ICU_soft_enuCaptureWave(void * Copy_PvoidParameter);

typedef struct
{
	u8 Timer0_u8OvfCounts;
	u8 ICU_softu8Flag;
	u32 ICU_soft_u8TimeOn;
	u32 ICU_soft_u8TimeOff;

}ICU_Data;


#define TIMER_PRESCALER			1024



#endif /* SERVICE_ICU_SOFT_INT_H_ */
