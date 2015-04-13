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
#include "RTOS.h"
#include "FRTOS1.h"

/*!
 * \brief Application event handler
 * \param event Event to be handled
 */
static void APP_HandleEvents(EVNT_Handle event) {
  switch(event) {
    case EVNT_STARTUP:
    	LED1_On();
    	WAIT1_Waitms(50);
    	LED1_Off();
    	break;
    case EVNT_LED_HEARTBEAT:
    	LED1_Neg();
    	LED2_Neg();
    	LED3_Neg();
    	break;
    case EVNT_SW1_PRESSED:
    	CLS1_SendStr("EVNT_SW1_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW1_LPRESSED:
    	CLS1_SendStr("EVNT_SE1_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW1_RELEASED:
    	CLS1_SendStr("EVNT_SW1_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW2_PRESSED:
    	CLS1_SendStr("EVNT_SW2_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW2_LPRESSED:
    	CLS1_SendStr("EVNT_SE2_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW2_RELEASED:
    	CLS1_SendStr("EVNT_SW2_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW3_PRESSED:
    	CLS1_SendStr("EVNT_SW3_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW3_LPRESSED:
    	CLS1_SendStr("EVNT_SE3_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW3_RELEASED:
    	CLS1_SendStr("EVNT_SW3_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW4_PRESSED:
    	CLS1_SendStr("EVNT_SW4_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW4_LPRESSED:
    	CLS1_SendStr("EVNT_SE4_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW4_RELEASED:
    	CLS1_SendStr("EVNT_SW4_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW5_PRESSED:
    	CLS1_SendStr("EVNT_SW5_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW5_LPRESSED:
    	CLS1_SendStr("EVNT_SE5_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW5_RELEASED:
    	CLS1_SendStr("EVNT_SW5_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW6_PRESSED:
    	CLS1_SendStr("EVNT_SW6_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW6_LPRESSED:
    	CLS1_SendStr("EVNT_SE6_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW6_RELEASED:
    	CLS1_SendStr("EVNT_SW6_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW7_PRESSED:
    	CLS1_SendStr("EVNT_SW7_PRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW7_LPRESSED:
    	CLS1_SendStr("EVNT_SE7_LPRESSED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    case EVNT_SW7_RELEASED:
    	CLS1_SendStr("EVNT_SW7_RELEASED\r\n", CLS1_GetStdio()->stdOut);
    	break;
    default:
      break;
  }
}

/*!
 * Main Task function.
 * @param pvParameters
 */
static void MainTask(void *pvParameters) {
	(void) pvParameters;
	for(;;) {
		KEY_Scan();
		EVNT_HandleEvent(APP_HandleEvents);
		FRTOS1_vTaskDelay(50/portTICK_RATE_MS);
	}
}

/*!
 * HeartBleed function.
 * @param pvParameters
 */
static void HeartBleed(void *pvParameters) {
	(void) pvParameters;
	for(;;) {
		EVNT_SetEvent(EVNT_LED_HEARTBEAT);
		FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
	}
}

/*!
 * \brief Application main 'task'.
 */
static void APP_Task(void) {
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */

  /* Create tasks here */
  if (FRTOS1_xTaskCreate(MainTask, "Main", configMINIMAL_STACK_SIZE+100, (void*)NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
  //if (FRTOS1_xTaskCreate(HeartBleed, "HeartBleed", configMINIMAL_STACK_SIZE+100, (void*)NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
  //  for(;;){} /* error */
  //}

  RTOS_Run();
}

void APP_Run(void) {
  PL_Init();

  APP_Task(); /* does not return */
}
