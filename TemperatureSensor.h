/*
 * TemperatureSensor.h
 *
 * Created: 12/8/2019 4:41:16 PM
 *  Author: T
 */ 


#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include <Arduino.h>

class TempSensor {
	
	private:
	static TempSensor* instance;
	
	const int tempSensorPin {A2};	//input pin for temp sensor
	int Vout;
	const float R1 {100000.0};			//value of permanent/constant resistor
	float LogR2, R2, Temperature;
	//Steinhart-Hart Constants  -- google it
	const float RconstA { -14.74289710e-3};
	const float RconstB {22.20533572e-4};
	float RconstC {-48.73544255e-7};
	
	//assign input pin for a temp sensor on creation.
	//Requires PinNumber, Steinhart Constants A,B,C, and value of Resistor 1 in V divider circuit
	//TempSensor thermometer {A2, -14.74289710e-3, 22.20533572e-4, -48.73544255e-7, 100000.0};
	//values presently assume S1 temp sensor {A2, -14.74289710e-3, 22.20533572e-4, -48.73544255e-7, 100000.0};
	
	
	
	public:
	
	TempSensor() {
		
		pinMode(tempSensorPin, INPUT);
	}
	
	//returns Temperature in Fahrenheit
	float getTempFahrenheit();
	
	
	
	
};



#endif /* TEMPERATURESENSOR_H_ */