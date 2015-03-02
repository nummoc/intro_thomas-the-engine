/*
 * Platform.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */
#include "Platform.h"

void PL_Init(void) {
	#if LED_ENABLE
	LED_Init();
	#endif
}

void PL_Deinit(void) {
	#if LED_ENABLE
	LED_Deinit();
	#endif
}
