/**
 * \file
 * \brief Semaphore usage
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * Module using semaphores.
 */

#include "Platform.h" /* interface to the platform */
#if PL_HAS_SEMAPHORE
#include "FRTOS1.h"
#include "Sem.h"
#include "LED.h"

static xSemaphoreHandle MySem = NULL;

static portTASK_FUNCTION(vSlaveTask, pvParameters) {
	LED1_Off();
	LED2_Off();
	LED3_Off();
  for(;;) {
    /*! \todo Implement functionality */
	  if (FRTOS1_xSemaphoreTake(MySem, portMAX_DELAY) == pdTRUE) {
		  LED1_Neg();
		  LED2_Neg();
		  LED3_Neg();
	  }
  }
}

static portTASK_FUNCTION(vMasterTask, pvParameters) {
  for(;;) {
    /*! \todo Implement functionality */
	  FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
	  (void) FRTOS1_xSemaphoreGive(MySem);
  }
}

void SEM_Deinit(void) {
  /* nothing */
}

/*! \brief Initializes module */
void SEM_Init(void) {
	FRTOS1_vSemaphoreCreateBinary(MySem);
	if (MySem == NULL) {
		for(;;){} /* error */
	}
	if (FRTOS1_xTaskCreate(vMasterTask, "Master", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL) != pdPASS) {
		for(;;){} /* error */
	}
	if (FRTOS1_xTaskCreate(vSlaveTask, "Slave", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL) != pdPASS) {
		for(;;){} /* error */
	}
}
#endif /* PL_HAS_SEMAPHORE */
