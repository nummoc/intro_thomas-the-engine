/*
 * LED_Controller.h
 *
 *  Created on: 24.02.2015
 *      Author: Philipp Gosswiler
 */

#ifndef LED_CONTROLLER_H_
#define LED_CONTROLLER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	NONE = 0,
	OFF = NONE,
	RED = 1,
	GREEN = 2,
	BLUE = 4,
	CYAN = GREEN | BLUE,
	MAGENTA = RED | BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
	ALL = WHITE
} LED;

void LED_Swap(LED leds);

void LED_Off();

void LED_On(LED leds);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* LED_CONTROLLER_H_ */
