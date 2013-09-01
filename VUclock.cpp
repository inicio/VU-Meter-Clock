#include "VUclock.h"
#include "Time/Time.h"
#include "Clock.h"
#include "VUmeters.h"

#define TIMER 100

#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message

#define TEST_HEADER 'V'

#define SECOND_LEN 4
#define SECOND_HEADER 'S'

int testVal = 255;
int secondHigh = 30;

int main(void){
	init();

	Serial.begin(9600);

	time_t timeVal = 1262347200;
	setTime(timeVal);

	VUmeters vumeters, *vu;
	Clock clock;

	vu = &vumeters;

	for(;;){
		if(Serial.available()) {
			processSyncMessage();
		}
		if(timeStatus() != timeNotSet)
		{
			clock.displayTime(*vu);
		}
	}
}


void processSyncMessage(){
	while(Serial.available() >= TIME_MSG_LEN + SECOND_LEN +1){
			char c = Serial.read();
			Serial.print(c);

			if(c == TIME_HEADER){
				time_t pctime = 0;
				for(int i = 0; i < TIME_MSG_LEN -1; i++){
					c = Serial.read();
					if(c >= '0' && c <= '9'){ // is [ascii] digit
						pctime = (10 * pctime) + (c - '0');
					}
				}
				setTime(pctime);
			}
			while((c = Serial.read()) == ' ')
				; // no white spaces

			if(c == SECOND_HEADER){
				for(int i = 0; i < SECOND_LEN -1; i++){
					c = Serial.read();
					Serial.println(c);
					if(c >= '0' && c <= '9'){
						secondHigh = (10 * secondHigh) + (c - '0');
					}
				}
			}
			Serial.write("Time set");

		}

	}

time_t requestSync(){
	return 0;
}
