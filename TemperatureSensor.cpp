/*
 * TemperatureSensor.cpp
 *
 * Created: 12/20/2019 7:37:23 PM
 *  Author: Tristan Callahan
 */ 

#include <Arduino.h>
#include "TemperatureSensor.h"





float TempSensor::getTempFahrenheit()
{
	Vout = analogRead(tempSensorPin);
	
	R2 = R1 * (1023.0 / Vout - 1.0);
	LogR2 = log(R2);
	Temperature = (1.0 / (RconstA + RconstB * LogR2 + RconstC * LogR2 * LogR2 * LogR2 ));
	Temperature = Temperature - 273.15;
	Temperature = (Temperature * 9.0) / 5.0 + 32.0;
	
	return Temperature;
}