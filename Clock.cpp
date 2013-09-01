/*
 * Clock.cpp
 *
 * Created on: 2012-06-04
 * Author: Royal Nasno
 */

#include "Clock.h"

int	minuteMarks[60] = {1,2,3,4,5,6,7,8,9,10,
			   11,12,13,14,15,16,17,18,19,20,
			   21,22,23,24,25,26,27,28,29,30,
			   31,32,33,34,35,36,37,38,39,40,
			   41,42,44,46,48,50,52,54,56,60,
			   65,70,75,80,85,90,95,100,105,110};

Clock::Clock() {
	time_t inittime = 1262347200;
	setTime(inittime);
	secPWM = 0;
	secIndex = 0;
}

Clock::~Clock() {

}

void Clock::secondRegulator(){
	if(secIndex <= secPWM && t%200 == 0) {
		secIndex++;
	}
	if(secIndex >= secPWM && t%200 == 0) {
		secIndex--;
	}
	if(t >= TIMER) {
		t = 0;
	}

	t++;
	secPWM = (second()%2) ? SECOND_MAX : 0;
}

void Clock::displayTime(VUmeters vu){
	vu.setVU(0,getTick());
	vu.setVU(1,getSecond());
	vu.setVU(2,getMinute());
	vu.setVU(3,getHour());
}

int Clock::getTick(){
	secondRegulator();
	return secIndex;
}

int Clock::getSecond(){
	switch(second()){
		case '0':
			multiplier = 1;
			break;
		case '15':
			multiplier = 1;
			break;
		case '25':
			multiplier = 2;
			break;
		case '30':
			multiplier = 7;
			break;
		case '45':
			multiplier = 25;
			break;
	}
	return minuteMarks[(int)second()];
}


int Clock::getMinute(){
	return (int)(square(minute())*2);
}
int Clock::getHour(){
	return (int)(square(hour())*2);
}
