/*
 * VUmeters.h
 *
 * Created on: 2012-06-02
 * Author: Royal Nason
 */

#ifndef VUMETERS_H_
#define VUMETERS_H_

#include "Arduino.h"

class VUmeters {
public:
	VUmeters();
	virtual ~VUmeters();

	void setVU(int screen, int val);

private:
	#define PWMs 5
	int screens[PWMs];

};

#endif /* VUMETERS_H_ */
