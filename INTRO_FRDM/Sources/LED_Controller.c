/*
 * LED_Controller.c
 *
 *  Created on: 24.02.2015
 *      Author: Philipp Gosswiler
 */
#include "LED_Controller.h"
#include "LED_RED.h"
#include "LED_BLUE.h"
#include "LED_GREEN.h"

#ifdef __cplusplus
extern "C" {
#endif

void LED_Swap(LED leds) {
	if (leds & GREEN) LED_GREEN_NegVal();
	if (leds & BLUE) LED_BLUE_NegVal();
	if (leds & RED) LED_RED_NegVal();
}

void LED_Off(void) {
	LED_GREEN_PutVal(TRUE);
	LED_RED_PutVal(TRUE);
	LED_BLUE_PutVal(TRUE);
}

void LED_On(LED leds) {
	if (leds & GREEN) LED_GREEN_PutVal(FALSE);
	if (leds & RED) LED_RED_PutVal(FALSE);
	if (leds & BLUE) LED_BLUE_PutVal(FALSE);
}

#ifdef __cplusplus
}  /* extern "C" */
#endif
