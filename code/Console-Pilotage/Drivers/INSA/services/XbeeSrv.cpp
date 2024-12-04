/*
 * Xbee.cpp
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#include <XbeeSrv.h>

XbeeSrv::XbeeSrv(Uart &uart) {

}

virtual XbeeSrv::~XbeeSrv() {

}

int XbeeSrv::Setup(int ownAddress) {

}

int XbeeSrv::GetLastRSSI() {
	return lastRSSI;
}

int XbeeSrv::GetLastStatus() {
	return lastStatus;
}

void XbeeSrv::ChangeOwnAddress(int ownAddress) {
	this->ownAddress= ownAddress;
}

void XbeeSrv::SetDefaultDestinationAddress(int desAddress) {

}
