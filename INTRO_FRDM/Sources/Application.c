/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "../../COMMON/Application.h"
#include "../../COMMON/Platform.h"
#include "../../COMMON/LED.h"
#include "LED_WAIT.h"

void exe(void (*function)(void)) {
	function();
}

void APP_Start(void) {
	// Initialize Platform
	PL_Init();

	// Do work
	LED_Test();
	LED_On(LED_BLUE);
	for(;;) {
		LED_WAIT_Waitms(500);
		LED_Neg(LED_MAGENTA);
	}

	// Finalize Platform
	PL_Deinit();
}
