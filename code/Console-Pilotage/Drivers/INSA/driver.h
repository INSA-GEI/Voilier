/*
 * driver.h
 *
 *  Created on: 31 mars 2020
 *      Author: sd
 */

#ifndef INSA_DRIVER_H_
#define INSA_DRIVER_H_

#include "BaseObject.h"

class Driver : public BaseObject {
public:
	Driver();
	virtual ~Driver();
	virtual void interruptHandler(int signal) =0;
};

#endif /* INSA_DRIVER_H_ */
