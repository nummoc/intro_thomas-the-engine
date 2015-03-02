/*
 * LED_Local.h
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#ifndef LED_FRDM_H_
#define LED_FRDM_H_

// LEDs are low active
typedef enum {
	LED_ON = 0,
	LED_OFF = 1
} LED_Status;

typedef enum {
	LED_NONE = (0<<0),
	LED_RED = (1<<1),
	LED_GREEN = (1<<2),
	LED_BLUE = (1<<3),
	LED_CYAN = LED_GREEN | LED_BLUE,
	LED_MAGENTA = LED_RED | LED_BLUE,
	LED_YELLOW = LED_RED | LED_GREEN,
	LED_WHITE = LED_RED | LED_GREEN | LED_BLUE,
	LED_ALL = LED_WHITE
} LED_Set;

#endif /* LED_FRDM_H_ */
