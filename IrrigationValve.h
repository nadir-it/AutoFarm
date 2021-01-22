/*
 * IrrigationValve.h
 *
 * Created: 12/8/2019 4:40:44 PM
 *  Author: TC
 */ 


#ifndef IRRIGATIONVALVE_H_
#define IRRIGATIONVALVE_H_

#include <Arduino.h>
#include "Clock.h"
#include "Interrupt.h"

class IrrigationValve {
	
	private:
	
	struct Day
	{
		boolean didWeWaterToday = false;
		AutoFarm::TimeStamp time = AutoFarm::Clock::currentTimeStamp();
		long inchesOfRain = 0;
	};
	
	static const short daysInAWeek = 7;
	
	Day pastWeek[daysInAWeek];
	static const int irrigationValvePin {10};
	AutoFarm::TimeStamp timeValveOpened;
	int irrigationValveState;
	
	
	public:
	
	 IrrigationValve () {};
	 
	  void openValve(void);
	
	  void closeValve(void);
	 
	  long getRainInInches();

	 boolean shouldWeIrrigate();
	 
	 int getIrrigationValveState();
	 
	 AutoFarm::TimeStamp getLastIrrigationReport();
	 
	 void saveIrrigationReport();
	 
	 void weWateredToday();
	 	
	~IrrigationValve() {};
};





#endif /* IRRIGATIONVALVE_H_ */