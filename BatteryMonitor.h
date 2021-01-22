/*
 * BatteryMonitor.h
 *
 * Created: 12/8/2019 4:42:06 PM
 *  Author: TC
 */ 


#ifndef BATTERYMONITOR_H_
#define BATTERYMONITOR_H_
#include "Clock.h"
#include "Ammeter.h"
#include "VoltMeter.h"
#include "TemperatureSensor.h"



class BatteryMonitor {
	
	private:
	
	struct Status
	{
		float volts;
		float amps;
		float temp;
			
	};
	 Status status;
	
	struct ChargeLog
	{
		AutoFarm::TimeStamp lastBatteryCheck;
		float ampHours;
		short hoursCharged;		
	} chargeHistory;
	
	
	
	 AmperageSensor ammeter;
	 VoltMeter voltmeter;
	 TempSensor thermometer; 
	 static const int batteryRelayPin = 12;
	 
	 boolean shouldWeOpenBatteryRelay = false;
	 boolean isBatteryRelayPinHigh = false;
	 AutoFarm::TimeStamp timeRelayOpened;
	
	float getAmps();
	float getVolts();
	float getTemp();
	 
	 void checkBattery();
	public:
	
	BatteryMonitor() {
		pinMode(batteryRelayPin, OUTPUT);
		digitalWrite(batteryRelayPin,LOW);	
	}
	
	
	
	 bool isBatteryChargingCorrectly();
	 void openBatteryRelay();
	 void closeBatteryRelay();
	 void execute();
};




#endif /* BATTERYMONITOR_H_ */