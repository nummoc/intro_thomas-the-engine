/*
 * mainController.c
 *
 *  Created on: 24.02.2015
 *      Author: Cyrill
 */

#include "Application.h"
#include "WAIT1.h"
#include "../../Common/Led.h"
#include "../../Common/Event.h"
#include "../../Common/Timer.h"
#include "../../Common/Platform.h"
#include "EventHandler.h"
#include "CLS1.h"
#include "FRTOS1.h"
#include "../../Common/RTOS.h"
#include "../../Common/Keys.h"
#include "../../Common/Motor.h"
#include "../../Common/Reflectance.h"
#include "Logic.h"


static void EvntHndlTask(void* param) {
	KEY_EnableInterrupts();

	EVNT_SetEvent(EVNT_INIT);
	for (;;) {
		EventHandler_HandleEvent();
		FRTOS1_vTaskDelay(50 / portTICK_RATE_MS);
	}
}

void APP_Run(void) {
	PL_Init();
	LOGIC_Init();

	if (FRTOS1_xTaskCreate(EvntHndlTask, (signed portCHAR *)"EventHandlerTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS) {
		for(;;){} /* error */
	}
	RTOS_Run();
}

