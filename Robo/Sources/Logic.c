/*!
 * \file
 * \brief	
 * \author	Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author	Reto Ritter <reto.ritter@stud.hslu.ch>
 */
#include "Logic.h"
#include "FRTOS1.h"
#include "CLS1.h"
#include "../../Common/Motor.h"
#include "../../Common/Reflectance.h"
#include "../../Common/Drive.h"
#include "../../Common/Trigger.h"

static int toggleDrive = 0;

typedef enum {
  LOGIC_Idle,
  LOGIC_Start,
  LOGIC_Search,
  LOGIC_Attack,
  LOGIC_Backup
} LOGIC_State;
static volatile LOGIC_State logicState = LOGIC_Idle; /* state machine state */
static volatile bool run = FALSE;

void CheckForEdge() {
	uint16_t lineValue = REF_GetLineValue();
	if (lineValue > 500) {
		logicState = LOGIC_Backup;
	}
}

void Wait(int millis) {
	FRTOS1_vTaskDelay(millis / portTICK_RATE_MS);
}

static void LogicTask(void* param) {
	uint16_t result;
	for(;;) {
		if (!run) {
			DRV_SetSpeed(0, 0);
			continue;
		}
		CheckForEdge();
		switch (logicState) {
			case LOGIC_Start:

				break;
			case LOGIC_Backup:
				DRV_SetSpeed(-1000, -1000);
				Wait(100);
				DRV_SetSpeed(1000, -1000);
				Wait(100);
				DRV_SetSpeed(0, 0);
				logicState = LOGIC_Search;
				continue;
			case LOGIC_Idle:
				break;
			case LOGIC_Search:
				DRV_SetSpeed(1000, 1000);
				break;
			case LOGIC_Attack:
				break;
			default:
				break;
		}
		Wait(50);
	}
}

void LOGIC_Toggle() {
	if (run) {
		run = FALSE;
	} else {
		run = TRUE;
		logicState = LOGIC_Search;
	}
}

void LOGIC_Init() {
	 if (FRTOS1_xTaskCreate(LogicTask, (signed portCHAR *)"LogicTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL) != pdPASS) {
	   for(;;){} /* error */
	 }
}

void LOGIC_DEINIT() {}
