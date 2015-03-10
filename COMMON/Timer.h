/*!
 * \file
 * \brief	
 * \author	Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author	Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 *
 */

#ifndef TIMER_H_
#define TIMER_H_

#define TMR_TICK_MS  10
  /*!< we get called every TMR_TICK_MS ms */

/*! \brief Function called from timer interrupt every TMR_TICK_MS. */
void TMR_OnInterrupt(void);

/*! \brief Timer driver initialization */
void TMR_Init(void);

/*! \brief Timer driver de-initialization */
void TMR_Deinit(void);

#endif /* TIMER_H_ */
