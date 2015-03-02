/*
 * LED_Robo.h
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#ifndef LED_ROBO_H_
#define LED_ROBO_H_

typedef enum
{
	NONE = (1<<0),
	OFF = NONE,
	RED = (1<<1),
	GREEN = (1<<2),
	BLUE = (1<<3),
	CYAN = GREEN | BLUE,
	MAGENTA = RED | BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
	ALL = WHITE
} LED_Set;


#endif /* LED_ROBO_H_ */
