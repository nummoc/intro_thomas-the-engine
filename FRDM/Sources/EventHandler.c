/*
 * EventHandler.c
 *
 *  Created on: 10.03.2015
 *      Author: Cyrill
 */
#include "EventHandler.h"
#include "../../Common/Led.h"
#include "WAIT1.h"
#include "../../Common/Mealy.h"
#include "CLS1.h"
#include "../../Common/ShellQueue.h"
#include "Remote.h"
#include "RApp.h"
#include "RNet_App.h"

void ProcessInitEvent(void);
void ProcessSW1Event(void);
void ProcessSW2Event(void);
void ProcessSW3Event(void);
void ProcessSW4Event(void);
void ProcessSW5Event(void);
void ProcessSW6Event(void);
void ProcessSW7Event(void);
void ProcessSW1EventLong(void);
void ProcessSW2EventLong(void);
void ProcessSW3EventLong(void);
void ProcessSW4EventLong(void);
void ProcessSW5EventLong(void);
void ProcessSW6EventLong(void);
void ProcessSW7EventLong(void);
void ProcessSW1EventReleased(void);
void ProcessSW2EventReleased(void);
void ProcessSW3EventReleased(void);
void ProcessSW4EventReleased(void);
void ProcessSW5EventReleased(void);
void ProcessSW6EventReleased(void);
void ProcessSW7EventReleased(void);
void ProcessLEDHeartbeatEcent(void);
void SendStringToUSB(char* string);

EventAllocation evtAlloc[] = {
		{EVNT_INIT, ProcessInitEvent},
		{EVNT_SW1_PRESSED, ProcessSW1Event},
		{EVNT_SW2_PRESSED, ProcessSW2Event},
		{EVNT_SW3_PRESSED, ProcessSW3Event},
		{EVNT_SW4_PRESSED, ProcessSW4Event},
		{EVNT_SW5_PRESSED, ProcessSW5Event},
		{EVNT_SW6_PRESSED, ProcessSW6Event},
		{EVNT_SW7_PRESSED, ProcessSW7Event},
		{EVNT_SW1_LPRESSED, ProcessSW1EventLong},
		{EVNT_SW2_LPRESSED, ProcessSW2EventLong},
		{EVNT_SW3_LPRESSED, ProcessSW3EventLong},
		{EVNT_SW4_LPRESSED, ProcessSW4EventLong},
		{EVNT_SW5_LPRESSED, ProcessSW5EventLong},
		{EVNT_SW6_LPRESSED, ProcessSW6EventLong},
		{EVNT_SW7_LPRESSED, ProcessSW7EventLong},
		{EVNT_SW1_RELEASED, ProcessSW1EventReleased},
		{EVNT_SW2_RELEASED, ProcessSW2EventReleased},
		{EVNT_SW3_RELEASED, ProcessSW3EventReleased},
		{EVNT_SW4_RELEASED, ProcessSW4EventReleased},
		{EVNT_SW5_RELEASED, ProcessSW5EventReleased},
		{EVNT_SW6_RELEASED, ProcessSW6EventReleased},
		{EVNT_SW7_RELEASED, ProcessSW7EventReleased}
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

void SendRemoteMessage(RAPP_MSG_Type msgType, uint8_t* data) {
    (void)RAPP_SendPayloadDataBlock(data, sizeof(data), msgType, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_REQ_ACK);
}

void ProcessInitEvent(void) {
	SendStringToUSB("Hello from FRDM\r\n");
	for (int i = 0; i < 3; i++) {
		LED2_On();
		WAIT1_Waitms(100);
		LED2_Off();
		WAIT1_Waitms(100);
	}
}
void ProcessSW1Event(void) {
	SendStringToUSB("A Pressed\r\n");
	LED2_On();
}
void ProcessSW2Event(void) {
	SendStringToUSB("B Pressed\r\n");
}
void ProcessSW3Event(void) {
	SendStringToUSB("C Pressed\r\n");
	SendRemoteMessage(RAPP_MSG_TYPE_TOGGLE_MODE, (uint8_t*) NULL);
}
void ProcessSW4Event(void) {
	SendStringToUSB("D Pressed\r\n");
}
void ProcessSW5Event(void) {
	SendStringToUSB("E Pressed\r\n");
}
void ProcessSW6Event(void) {
	SendStringToUSB("F Pressed\r\n");
}
void ProcessSW7Event(void) {
	SendStringToUSB("Joystick Pressed\r\n");
}
void ProcessSW1EventLong(void)
{
	SendStringToUSB("A Long Pressed\r\n");
}
void ProcessSW2EventLong(void)
{
	uint16_t value = 250;
	SendStringToUSB("B Long Pressed\r\n");
    uint8_t buf[2];
    buf[0] = (uint8_t)(value&0xFF);
    buf[1] = (uint8_t)(value>>8);
	SendRemoteMessage(RAPP_MSG_TYPE_BOOST, buf);
}
void ProcessSW3EventLong(void)
{
	SendStringToUSB("C Long Pressed\r\n");
}
void ProcessSW4EventLong(void){
	SendStringToUSB("D Long Pressed\r\n");
}
void ProcessSW5EventLong(void){
	SendStringToUSB("E Long Pressed\r\n");
}
void ProcessSW6EventLong(void){
	SendStringToUSB("F Long Pressed\r\n");
}
void ProcessSW7EventLong(void){
	SendStringToUSB("Joystick Long Pressed\r\n");
}
void ProcessSW1EventReleased(void){
	SendStringToUSB("A Released\r\n");
}
void ProcessSW2EventReleased(void){
	uint16_t value = 150;
	SendStringToUSB("B Released\r\n");
    uint8_t buf[2];
    buf[0] = (uint8_t)(value&0xFF);
    buf[1] = (uint8_t)(value>>8);
	SendRemoteMessage(RAPP_MSG_TYPE_BOOST, buf);
}
void ProcessSW3EventReleased(void){
	SendStringToUSB("C Released\r\n");
}
void ProcessSW4EventReleased(void){
	SendStringToUSB("D Released\r\n");
}
void ProcessSW5EventReleased(void){
	SendStringToUSB("E Released\r\n");
}
void ProcessSW6EventReleased(void){
	SendStringToUSB("F Released\r\n");
}
void ProcessSW7EventReleased(void){
	SendStringToUSB("Joystick Released\r\n");
}
