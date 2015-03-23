/**
 * \file
 * \brief Event driver interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements a generic event driver. We are using numbered events starting with zero.
 * EVNT_HandleEvent() can be used to process the pending events. Note that the event with the number zero
 * has the highest priority and will be handled first
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "Platform.h"

#if PL_HAS_EVENTS

typedef enum EVNT_Handle {
  EVNT_STARTUP,			/*!< System startup Event */
  EVNT_LED_HEARTBEAT,	/*!< LED heartbeat */
  EVNT_SW1_PRESSED,		/*!< Button 1 pressed */
  EVNT_SW1_LPRESSED,	/*!< Button 1 long pressed */
  EVNT_SW1_RELEASED,	/*!< Button 1 released */
  EVNT_SW2_PRESSED,		/*!< Button 2 pressed */
  EVNT_SW2_LPRESSED,	/*!< Button 2 long pressed */
  EVNT_SW2_RELEASED,	/*!< Button 2 released */
  EVNT_SW3_PRESSED,		/*!< Button 3 pressed */
  EVNT_SW3_LPRESSED,	/*!< Button 3 long pressed */
  EVNT_SW3_RELEASED,	/*!< Button 3 released */
  EVNT_SW4_PRESSED,		/*!< Button 4 pressed */
  EVNT_SW4_LPRESSED,	/*!< Button 4 long pressed */
  EVNT_SW4_RELEASED,	/*!< Button 4 released */
  EVNT_SW5_PRESSED,		/*!< Button 5 pressed */
  EVNT_SW5_LPRESSED,	/*!< Button 5 long pressed */
  EVNT_SW5_RELEASED,	/*!< Button 5 released */
  EVNT_SW6_PRESSED,		/*!< Button 6 pressed */
  EVNT_SW6_LPRESSED,	/*!< Button 6 long pressed */
  EVNT_SW6_RELEASED,	/*!< Button 6 released */
  EVNT_SW7_PRESSED,		/*!< Button 7 pressed */
  EVNT_SW7_LPRESSED,	/*!< Button 7 long pressed */
  EVNT_SW7_RELEASED,	/*!< Button 7 released */
  EVNT_NOF_EVENTS       /*!< Must be last one! */
} EVNT_Handle;

/*!
 * \brief Sets an event.
 * \param[in] event The handle of the event to set.
 */
void EVNT_SetEvent(EVNT_Handle event);

/*!
 * \brief Clears an event.
 * \param[in] event The event handle of the event to clear.
 */
void EVNT_ClearEvent(EVNT_Handle event);

/*!
 * \brief Returns the status of an event.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSet(EVNT_Handle event);

/*!
 * \brief Returns the status of an event. As a side effect, the event gets cleared.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSetAutoClear(EVNT_Handle event);

/*!
 * \brief Routine to check if an event is pending. If an event is pending, the event is cleared and the provided callback is called.
 * \param[in] callback Callback routine to be called. The event handle is passed as argument to the callback.
 */
void EVNT_HandleEvent(void (*callback)(EVNT_Handle));

/*! \brief Event module initialization */
void EVNT_Init(void);

/*! \brief Event module de-initialization */
void EVNT_Deinit(void);

#endif /* PL_HAS_EVENTS */


#endif /* EVENT_H_ */
