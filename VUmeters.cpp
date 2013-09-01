/*
 * VUmeters.cpp
 *
 * Created on: 2012-06-02
 * Author: Royal Nason
 */

#include "VUmeters.h"


VUmeters::VUmeters() {
	screens = {3,5,6,9,10};

	for(int i = 0; i < PWMs; i++){
		pinMode(screens[i],OUTPUT);
	}

}

VUmeters::~VUmeters() {

}

void VUmeters::setVU(int screen, int val){
	int *p;
	p = &screens[screen];
	analogWrite(*p,val);
}
