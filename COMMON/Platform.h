/*
 * Platform.h
 *
 *  Created on: 02.03.2015
 *      Author: tastyger
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "PE_Types.h" /* for common Processor Expert types used throughout the project, e.g. 'bool' */
#include "PE_Error.h" /* global error constants */

/* List of supported platforms. The PL_BOARD_IS_xxx is defined in the compiler command line settings.  */
#define PL_IS_FRDM   (defined(PL_BOARD_IS_FRDM))
#define PL_IS_ROBO  (defined(PL_BOARD_IS_ROBO))



#define PL_HAS_LED      (1)

#define PL_HAS_HAS_TIMER 	(1)
#define PL_HAS_EVENTS		(1)
#define PL_HAS_MEALY		(1)
#define PL_HAS_KEYS			(1)
#define PL_HAS_KBI			(1)
#define PL_HAS_TRIGGER		(1)
#define PL_HAS_DEBOUNCE 	(1)
#define PL_HAS_RTOS			(1)
#define PL_HAS_SHELL		(1)
#define PL_HAS_SHELL_QUEUE	(1)

#if PL_IS_FRDM
#define PL_HAS_SEMAPHORE	(1)
#define PL_HAS_BLUETHOOTH	(0)
#define PL_HAS_USB_CDC		(1)
#define PL_NOF_LEDS       	(3)
#define PL_HAS_JOYSTICK		(1)
#define PL_NOF_KEYS			(7)
#define PL_KEY_POLLED_KEY5 	(1)			//This key is beeing polled
#define PL_KEY_POLLED_KEY6 	(1)			//This key is beeing polled
#define PL_KEY_POLLED_KEY3 	(1)			//This key is beeing polled

#elif PL_IS_ROBO
#define PL_HAS_LINE_SENSOR	(1)
#define PL_HAS_BLUETHOOTH	(1)
#define PL_HAS_USB_CDC		(1)
  #define PL_NOF_LEDS       (2)
#define PL_NOF_KEYS 		(1)
#define PL_HAS_BUZZER		(1)
#else
  #error "unknown configuration?"
#endif


void PL_Init(void);
void PL_Deinit(void);

#endif /* PLATFORM_H_ */
