/*
 * Platform.h
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#define LED_ENABLE (1)
#define LED_TEST (LED_ENABLE & 1)

// Initialization
void PL_Init(void);
void PL_Deinit(void);


#endif /* PLATFORM_H_ */
