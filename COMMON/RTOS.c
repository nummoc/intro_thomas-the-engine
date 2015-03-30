/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "CLS1.h"

static portTASK_FUNCTION(T1, pvParameters) {
  for(;;) {
    LED2_Neg();
    CLS1_SendStr("Idle Task\r\n", CLS1_GetStdio()->stdOut);
    FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
  }
}

/*static void IdleTask(void *pvParameters) {
	for (;;) {
		vTask
		if (!configUSE_PREEMPTION) {
			taskYIELD();
		} else if (configIDLE_SHOULD_YIELD) {
			if ()
		}
	}
}*/

void RTOS_Run(void) {
  FRTOS1_vTaskStartScheduler();
  /* does usually not return here */
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */
  if (FRTOS1_xTaskCreate(T1, (signed portCHAR *)"T1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */
