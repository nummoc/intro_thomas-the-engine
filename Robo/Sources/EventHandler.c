/*
 * EventHandler.c
 *
 *  Created on: 10.03.2015
 *      Author: Cyrill
 */
#include "EventHandler.h"
#include "../../Common/Led.h"
#include "WAIT1.h"
#include "CLS1.h"
#include "../../Common/Buzzer.h"
#include "../../Common/Trigger.h"
#include "../../Common/ShellQueue.h"
#include "../../Common/Reflectance.h"
#include "Logic.h"

void ProcessInitEvent(void);
void ProcessSW1Event(void);
void ProcessSW1EventLong(void);
void ProcessSW1EventReleased(void);
void ProcessLEDHeartbeatEcent(void);
void TurnOffHeartBeat(TRG_CallBackDataPtr data);
void SendStringToUSB(char* string);

EventAllocation evtAlloc[] = {
		{EVNT_INIT, ProcessInitEvent},
		{EVNT_SW1_PRESSED, ProcessSW1Event},
		{EVNT_SW1_LPRESSED, ProcessSW1EventLong},
		{EVNT_SW1_RELEASED, ProcessSW1EventReleased}
}; /*!< Allocation between event type and handler function*/

void EventHandler_HandleEvent(void) {
	EVNT_HandleEvent(evtAlloc, sizeof(evtAlloc));
}

void SendStringToUSB(char* string){
#if PL_HAS_SHELL_QUEUE
	SQUEUE_SendString(string);
#else
	CLS1_SendStr(string, CLS1_GetStdio()->stdOut);
#endif
}

void ProcessInitEvent(void) {
	SendStringToUSB("Thomas the tank engine\r\n" );
	BUZ_Beep(250,600);
	for (int i = 0; i < 3; i++) {
		LED2_On();
		WAIT1_Waitms(100);
		LED2_Off();
		WAIT1_Waitms(100);
	}
}
void ProcessSW1Event(void) {
	LOGIC_Toggle();
}
void ProcessSW1EventLong(void){
	REF_StartStopCallibration();
}
void ProcessSW1EventReleased(void){
}

