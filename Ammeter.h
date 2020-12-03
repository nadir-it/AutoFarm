/*
 * Ammeter.h
 *
 * Created: 12/8/2019 4:41:29 PM
 *  Author: T
 */ 


#ifndef AMMETER_H_
#define AMMETER_H_

#include <Arduino.h>

class AmperageSensor {
	
	private:
	
	
	const int ampSensorPin = A0;
	int sensorValue;
	float voltage;
	
	
	
	//default Amperage Sensor to pin A0
	
	
	public:
	
	AmperageSensor() {
		
		//this->ampSensorPin = A0;
		pinMode(this->ampSensorPin, INPUT);
		voltage = 0.0f;
	}
		
	
	float getAmps();
	~AmperageSensor() {};	
		
};




#endif /* AMMETER_H_ */