/*
 * IrrigationValve.cpp
 *
 * Created: 12/20/2019 7:34:58 PM
 *  Author: T
 */ 

#include "IrrigationValve.h"


void IrrigationValve::closeValve(void) {
	if ( (AutoFarm::Clock::currentTimeStamp().unixtime - timeValveOpened.unixtime) > 300 )
	{
		digitalWrite(irrigationValvePin, LOW);
		irrigationValveState = LOW;	
	}
	
}

void IrrigationValve::openValve(void) {
	digitalWrite(irrigationValvePin, HIGH);
	irrigationValveState = HIGH;
	timeValveOpened = AutoFarm::Clock::currentTimeStamp();
	weWateredToday();
}

long IrrigationValve::getRainInInches()
{
	return Interrupts::Interrupt::getRainInInches();
}


boolean IrrigationValve::shouldWeIrrigate()
{
	float AvgRain {0};
	float last3Days{0};
		
	for (int i=0; i<daysInAWeek; ++i)
	{
		AvgRain = AvgRain + pastWeek[i].inchesOfRain;
	}
	AvgRain = AvgRain / 7;
	
	last3Days = (pastWeek[0].inchesOfRain + pastWeek[1].inchesOfRain + pastWeek[2].inchesOfRain) /3;
	
	float anyLately = (pastWeek[0].inchesOfRain + pastWeek[1].inchesOfRain + pastWeek[2].inchesOfRain);
	
	if (AvgRain < 0.5) 
	{
		return true;
	}
	if (last3Days < .5)
	{
		return true;
	}
	if (anyLately == 0)
	{
		return true;
	}
	
		return false;	
}

int IrrigationValve::getIrrigationValveState()
{
	return irrigationValveState;
}

AutoFarm::TimeStamp IrrigationValve::getLastIrrigationReport()
{
	return pastWeek[0].time;
}

void IrrigationValve::saveIrrigationReport()
{
	for(int i = 6; i > 0; ++i)
	{
		pastWeek[i] = pastWeek[i-1];
	}
	pastWeek[0].didWeWaterToday = false;
	pastWeek[0].inchesOfRain = Interrupts::Interrupt::getRainInInches();
	pastWeek[0].time = AutoFarm::Clock::currentTimeStamp();
}

void IrrigationValve::weWateredToday()
{
	pastWeek[0].didWeWaterToday = true;
}