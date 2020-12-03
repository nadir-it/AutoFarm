/*
 * RainGauge.cpp
 *
 * Created: 12/20/2019 7:36:21 PM
 *  Author: T
 */ 
#include "Arduino.h"
#include "RainGauge.h"







void RainGauge::openValve()
{
	digitalWrite(Interrupts::rainGaugeValve, HIGH);
	Interrupts::Interrupt::setRainGaugeValvePinState(HIGH);
	Interrupts::Interrupt::setRainGaugeValveOpenTime();
	
	
}

void RainGauge::closeValve()
{
	if ( (AutoFarm::Clock::currentTimeStamp().unixtime - Interrupts::Interrupt::getRainGaugeValveOpenTime().unixtime ) > 2 )
	{
		digitalWrite(Interrupts::rainGaugeValve, LOW);
		Interrupts::Interrupt::setRainGaugeValvePinState(LOW);
		Interrupts::Interrupt::rainGaugeTickProcessed();
	}
}

int RainGauge::getSwitchState() {
	return Interrupts::Interrupt::getRainGaugePinState();
}

int RainGauge::getValveState()
{
	return Interrupts::Interrupt::getRainGaugeValveState();
}