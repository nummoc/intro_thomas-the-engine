/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "Event.h"

void RTOS_Run(void) {
	FRTOS1_vTaskStartScheduler();
	/* does usually not return here */
}

void RTOS_Init(void) {
	/*! \todo Add tasks here */
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */
