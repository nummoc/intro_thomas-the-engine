/*!
 * \file
 * \brief	
 * \author	Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author	Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 *
 */
#include "FRTOS1.h"
#include "CLS1.h"
#include "../../Common/Motor.h"
#include "../../Common/Reflectance.h"

int toggleDrive = 0;

void LOGIC_ToggleDrive() {
	if (toggleDrive) {
		toggleDrive = 0;
	} else {
		toggleDrive = 1;
	}
}

void forward() {
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), (MOT_SpeedPercent) 10);
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), (MOT_SpeedPercent) 10);
}

void stop() {
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), (MOT_SpeedPercent) 0);
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), (MOT_SpeedPercent) 0);
}

void reverse() {
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), (MOT_SpeedPercent) -10);
	MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), (MOT_SpeedPercent) -10);
}

static void MotorTask(void* param) {
	uint16_t result;
	for(;;) {
		if (toggleDrive) {
			stop();
		} else {
			result = REF_GetLineValue();
			CLS1_SendNum16u(result, CLS1_GetStdio()->stdOut);
			CLS1_SendStr((unsigned char*)"\r\n", CLS1_GetStdio()->stdOut);
			if (result < 200) {
				reverse();
				FRTOS1_vTaskDelay(250 / portTICK_RATE_MS);
				forward();
			} else {
				forward();
			}
		}
		FRTOS1_vTaskDelay(100 / portTICK_RATE_MS);
	}
}

void LOGIC_Init() {
	 if (FRTOS1_xTaskCreate(MotorTask, (signed portCHAR *)"MotorTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL) != pdPASS) {
	   for(;;){} /* error */
	 }
}

void LOGIC_DEINIT() {}
