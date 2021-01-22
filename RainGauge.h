/*
 * RainGauge.h
 *
 * Created: 12/8/2019 4:41:01 PM
 *  Author: TC
 */ 


#ifndef RAINGAUGE_H_
#define RAINGAUGE_H_
#include <Arduino.h>
#include "Clock.h"
#include "Interrupt.h"

class RainGauge {
	

	private:
	
	  
	  AutoFarm::TimeStamp timeValveOpened;
	
	public:
	
	RainGauge()
	{
		//_init();
		pinMode(Interrupts::rainGaugeValve,OUTPUT);
		pinMode(Interrupts::rainGaugeSwitch,INPUT);
		
		//tickCount = 0;
		//attachInterrupt(digitalPinToInterrupt(rainGaugeSwitch), Interrupts::Interrupt::rainGaugeISR(), RISING);
		 //volatile = rainGaugeState may be tripped by interrupt  now
	};
	
	

	
	
	 void openValve();
	 void closeValve();
	 int getSwitchState();
	 int getValveState();
	
	
	~RainGauge()  {};
};

#endif /* RAINGAUGE_H_ */