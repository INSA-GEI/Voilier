/*
 * Xbee.cpp
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#include "xbee.h"

Xbee::Xbee(Uart* uart) {
	// TODO Auto-generated constructor stub
	this->uart = uart;

	uart->addReceptionCallback((BaseObject*)this, this->UARTRxCallback);
	receptionBuffer.clear();
}

Xbee::~Xbee() {
	// TODO Auto-generated destructor stub
}


void Xbee::UARTRxCallback(BaseObject& obj, std::vector<uint8_t> &data) {
	Xbee& baseClass = (Xbee&)obj;

	baseClass->receptionBuffer.insert(baseClass->receptionBuffer.begin(), data.begin(), data.end());
}
