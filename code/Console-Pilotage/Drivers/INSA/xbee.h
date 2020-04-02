/*
 * Xbee.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "uart.h"

class Xbee {
public:
	Xbee();
	virtual ~Xbee();

private:
	Uart *uart;
	int adresseDes;
	int adresseSrc;

};

#endif /* XBEE_H_ */
