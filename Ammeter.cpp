/*
 * Ammeter.cpp
 *
 * Created: 12/20/2019 7:34:32 PM
 *  Author: User
 */ 

#include <Arduino.h>
#include "Ammeter.h"




float AmperageSensor::getAmps()
{
	sensorValue = analogRead(ampSensorPin);
	
	//change 5.0 to final tested value from 5v pin on nano
	voltage = sensorValue * (5.0 / 1023.0);
	
	//return this->voltage;
	
	return voltage * 3.0; // y = mx + b  Analog input voltage back to amps
}
