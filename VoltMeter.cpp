/*
 * VoltMeter.cpp
 *
 * Created: 12/20/2019 7:25:12 PM
 *  Author: Tristan Callahan
 */ 



#include <Arduino.h>
#include "VoltMeter.h"



float VoltMeter::getVolts() {
	int reading = analogRead(inputPin);
	
	//set 5.0 to final tested voltage from 5V on nano
	Vout = (reading * 5.0) / 1024.0;
	Vin = Vout / (R2 / R1 + R2);
	if (Vin < 0.09)
	{
		Vin = 0.0;
	}
	
	return Vin;
}
