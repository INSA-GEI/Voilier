/*
 * ServiceSink.h
 *
 *  Created on: 17 avr. 2020
 *      Author: dimercur
 */

#ifndef INSA_SERVICES_SERVICESINK_H_
#define INSA_SERVICES_SERVICE_H_

#include "common/Message.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "cmsis_os.h"

#include "forward_list"

using namespace std;

class Service {
public:
	Service();
	Service(char * name);
	virtual ~Service();

	/**
	 * Methode used for adding message into service queue
	 */
	virtual int PostMsg(Message &msg);

	/**
	 * Method used for registering a service where message must be posted
	 */
	virtual int RegisterService(Service &srv);
	virtual int UnRegisterService(Service &srv);
	virtual void MessageLoop();

	static void ServiceTask(void const *argument);
private:
	QueueHandle_t messageQueue;
	osThreadId threadId;
	char* serviceName=(char *)"";

	std::forward_list<void *> registeredServices={};

	virtual void Init(char* name);
	virtual int ProcessMsg(Message *msg) = 0;
	virtual int BroadcastMsg(Message &msg);
};

#endif /* INSA_SERVICES_SERVICESINK_H_ */
