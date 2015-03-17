/**
 * \file
 * \brief Application entry point and core functionality.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * In this module the application logic is implemented.
 */

#include "Platform.h"
#include "Application.h"
#include "LED.h"
#include "WAIT1.h"
#include "Event.h"
#include "CLS1.h"
#include "Keys.h"

/*!
 * \brief Application event handler
 * \param event Event to be handled
 */
static void APP_HandleEvents(EVNT_Handle event) {
  switch(event) {
    case EVNT_STARTUP:
    	CLS1_SendStr("EVNT_STARTUP\r\n", CLS1_GetStdio()->stdOut);
    	LED1_On();
    	WAIT1_Waitms(50);
    	LED1_Off();
    	break;
    case EVNT_LED_HEARTBEAT:
    	CLS1_SendStr("EVNT_LED_HEARTBEAT\r\n", CLS1_GetStdio()->stdOut);
    	LED1_Neg();
    	break;
    case EVNT_SW1_PRESSED:
    	CLS1_SendStr("EVNT_SW1_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW2_PRESSED:
    	CLS1_SendStr("EVNT_SW2_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW3_PRESSED:
    	CLS1_SendStr("EVNT_SW3_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW4_PRESSED:
    	CLS1_SendStr("EVNT_SW4_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW5_PRESSED:
    	CLS1_SendStr("EVNT_SW5_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW6_PRESSED:
    	CLS1_SendStr("EVNT_SW6_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW7_PRESSED:
    	CLS1_SendStr("EVNT_SW7_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    default:
      break;
  }
}

/*!
 * \brief Application main 'task'.
 */
static void APP_Task(void) {
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */
  for(;;) {
	  KEY_Scan();
	  EVNT_HandleEvent(APP_HandleEvents);
	  WAIT1_Waitms(50); /* wait some time */
  }
}

void APP_Run(void) {
  PL_Init();

  APP_Task(); /* does not return */
}
