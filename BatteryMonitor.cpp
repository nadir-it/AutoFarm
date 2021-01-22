/*
 * BatteryMonitor.cpp
 *
 * Created: 12/20/2019 7:42:52 PM
 *  Author: Tristan Callahan
 */ 


#include <Arduino.h>
#include "BatteryMonitor.h"



void BatteryMonitor::checkBattery()
{
	
	struct Samples {
		float volts[5];
		float amps [5];
		float temp[5];
		
	};
	
	Samples sample;
	
	for (int i = 0; i < 5; ++i)
	{
		
		sample.volts[i] = voltmeter.getVolts();
		sample.amps[i] = ammeter.getAmps();
		sample.temp[i] = thermometer.getTempFahrenheit();
		
	}
	
	float Vtemp;
	float Atemp;
	float Ttemp;
	
	for (int i = 0; i < 5; ++i)
	{
		Vtemp = Vtemp + sample.volts[i];
		Atemp = Atemp + sample.amps[i];
		Ttemp = Ttemp + sample.temp[i];
	}
	
	Vtemp = Vtemp / 5;
	Atemp = Atemp / 5;
	Ttemp = Ttemp / 5;
	
	status.temp = Vtemp;
	status.amps = Atemp;
	status.temp = Ttemp;
}


float BatteryMonitor::getAmps()
{
	return status.amps;
}
float BatteryMonitor::getVolts()
{
	return status.volts;
}
float BatteryMonitor::getTemp()
{
	return status.temp;
}

void BatteryMonitor::openBatteryRelay()
{
	digitalWrite(batteryRelayPin,HIGH);
	isBatteryRelayPinHigh = true;
	timeRelayOpened = AutoFarm::Clock::currentTimeStamp();
}

void BatteryMonitor::closeBatteryRelay()
{
	if ( isBatteryRelayPinHigh == true)
	{
		digitalWrite(batteryRelayPin,LOW);
		isBatteryRelayPinHigh = false;
	}
	
}

bool BatteryMonitor::isBatteryChargingCorrectly()
{
	
	checkBattery();
	AutoFarm::TimeStamp ts = AutoFarm::Clock::currentTimeStamp();
	if ((ts.unixtime - chargeHistory.lastBatteryCheck.unixtime) > 3600 ) //1 hour in seconds
	{
		chargeHistory.lastBatteryCheck = ts;
		chargeHistory.hoursCharged = chargeHistory.hoursCharged + 1;
		chargeHistory.ampHours = chargeHistory.ampHours + status.amps;
		
		if (chargeHistory.hoursCharged > 23)
		{
			chargeHistory.hoursCharged = 0;
			chargeHistory.ampHours = 0;
		}
	}
	
	if (status.volts > 14.8 ||
		status.amps > 10 ||
		status.temp > 90 ||
		chargeHistory.ampHours > 11
	)
	{
		shouldWeOpenBatteryRelay = true;
		return false;
	}
	
	
	shouldWeOpenBatteryRelay = false;
	return true;
}

void BatteryMonitor::execute()
{
	if (shouldWeOpenBatteryRelay == true)
	{
		openBatteryRelay();
	}
	else
	{
		closeBatteryRelay();
	}
	
}