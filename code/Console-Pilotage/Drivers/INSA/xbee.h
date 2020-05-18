/*
 * Xbee.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "BaseObject.h"
#include "uart.h"
#include <vector>
#include <string>
#include <functional>

typedef std::function<void(std::vector<uint8_t> &data)> XBEEDataReceivedCallback;

class Xbee : public BaseObject  {
public:
	Xbee(Uart* uart);
	virtual ~Xbee();

	int setup(int ownAddress);
	int getLastRSSI() {return this->lastRssi;}
	int getLastStatus()  {return this->lastError;}

	void setDestinationAddress(int desAddress) {this->desAddress = desAddress; }
	int sendData(std::vector<uint8_t> data);
	int sendData(std::string str);
	int sendData(uint8_t &data, int length);

	int getReceivedLength();
	void setEndingChars(std::vector<uint8_t> endingChars) {this->endingChars = endingChars; }

	int readData(std::vector<uint8_t> &data);
	int readData(std::string &str);
	int readData(uint8_t &data, int length);

	void addReceptionCallback(BaseObject& obj, XBEEDataReceivedCallback callee) { this->rxCallbackObj = &obj;  this->rxCallback = callee; }

private:
	Uart* uart;
	int desAddress;
	int ownAddress;
	int lastRssi;
	int lastError;

	BaseObject* rxCallbackObj = nullptr;
	XBEEDataReceivedCallback rxCallback = nullptr;
	std::vector<uint8_t> endingChars;

	std::vector<uint8_t> receptionBuffer;

	static void UARTRxCallback(BaseObject* obj, std::vector<uint8_t> &data);
};

#endif /* XBEE_H_ */
