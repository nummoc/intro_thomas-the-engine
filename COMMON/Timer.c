/*
 * Timer.c
 *
 *  Created on: 10.03.2015
 *      Author: Cyrill
 */
#include "Timer.h"

#if PL_HAS_HAS_TIMER
#include "Event.h"
#include "Trigger.h"
#include "Tacho.h"


void TMR_OnInterrupt(void){
#if PL_HAS_TRIGGER
	TRG_IncTick();
#endif
#if PL_HAS_MOTOR_TACHO
	TACHO_Sample();
#endif
}


void TMR_Init(void){
}


void TMR_Deinit(void){
}

#endif
