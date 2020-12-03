/*
 * VoltMeter.h
 *
 * Created: 12/20/2019 7:24:50 PM
 *  Author: T
 */ 


#ifndef VOLTMETER_H_
#define VOLTMETER_H_

#include <Arduino.h>

class VoltMeter {
	
	private:
	
	
	
	const int inputPin = A1;
	float Vin = 0.0;
	float Vout = 0.0;
	//set resistance values to final tested.
	const float R1 = 100000.0;
	const float R2 = 10000.0;
	
	
	public:
	
	
	VoltMeter(void) {
		pinMode(this->inputPin, INPUT);
	}
	
	float getVolts();
};



#endif /* VOLTMETER_H_ */