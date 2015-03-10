/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "../../COMMON/Application.h"
#include "../../COMMON/Platform.h"
#include "../../COMMON/LED.h"
#include "../../COMMON/Event.h"
#include "LED_WAIT.h"

void APP_Start(void) {
	// Initialize Platform
	PL_Init();

	// Do work
	LED_On(LED_BLUE);
	for(;;) {
		EVNT_HandleEvent(APP_HandleEvent);
	}

	// Finalize Platform
	PL_Deinit();
}

void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
		case EVNT_INIT:
			break;
		case EVNT_LED_ON:
			LED_On(LED_ALL);
			break;
		case EVNT_LED_OFF:
			LED_All_Off();
			break;
		case EVNT_LED_NEG:
			LED_Neg(LED_ALL);
			break;
		default: /* do nothing */
			break;
	}
}
