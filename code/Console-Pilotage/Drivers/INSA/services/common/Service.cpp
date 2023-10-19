/*
 * ServiceSink.cpp
 *
 *  Created on: 17 avr. 2020
 *      Author: dimercur
 */

#include <common/Service.h>
#include "queue.h"
#include "algorithm"

Service::Service() {
	Init((char*)"Unnamed Service");
}

Service::Service(char* name) {
	Init(name);
}

void Service::Init(char* name) {
	osThreadDef_t threadDef;

	this->serviceName=name;
	/* Create a queue capable of containing 10 unsigned long values. */
	messageQueue = xQueueCreate( 20, sizeof( Message& ) );

	if( messageQueue == NULL )
	{
		/* Queue was not created and must not be used. */
		while (1);
	}

	threadDef.name =name;
	threadDef.instances=0;
	threadDef.tpriority = osPriorityNormal;
	threadDef.stacksize = 4096;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpmf-conversions"
	threadDef.pthread = (void (*)(const void*))(&Service::ServiceTask);
#pragma GCC diagnostic pop

	threadId = osThreadCreate(&threadDef, (void*)this);
}

Service::~Service() {
	vQueueDelete(messageQueue);
	osThreadTerminate(this->threadId);
}

int Service::PostMsg(Message &msg) {
	if (xQueueSendToBack(messageQueue,(const void *)&msg, 10) != pdPASS)
		return 0;

	return 1;
}

int Service::RegisterService(Service &srv) {
	registeredServices.push_front((void*)&srv);

	return 1;
}

int Service::UnRegisterService(Service &srv) {
	registeredServices.remove((void*)&srv);

	return 1;
}

int Service::BroadcastMsg(Message &msg) {
	for (auto it = registeredServices.cbegin(); it != registeredServices.cend(); it++) {
		((Service*)&it)->PostMsg(msg);
	}

	return 1;
}

void Service::ServiceTask(void const *argument) {
	Service *obj = (Service*) argument;

	obj->MessageLoop();
}

void Service::MessageLoop() {
	Message *msg=nullptr;

	while (1)
	{
		/* Service loop */

		if (xQueueReceive(messageQueue, msg, portMAX_DELAY) == pdPASS) {
			ProcessMsg(msg);
		}
	}
}
