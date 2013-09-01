/*
 * Clock.h
 *
 * Created on: 2012-06-04
 * Author: Royal Nason
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "Time/Time.h"
#include "VUmeters.h"

class Clock {
public:
	Clock();
	virtual ~Clock();

	void secondRegulator();
	void displayTime(VUmeters);

	int getSecond();
	int getMinute();
	int getHour();
	int getTick();

private:
	#define TIMER 1000
	#define SECOND_MAX 40

	int multiplier;
	int secPWM, secIndex;
	int t;
};

#endif /* CLOCK_H_ */
