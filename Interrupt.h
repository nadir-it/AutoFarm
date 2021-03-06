/*
 * Interrupt.h -- interrupts must be static on the ATmega328p... ABANDON ALL HOPE YEE WHO ENTER HERE...
 * this saves us from 2 or 3 static objects with a horrible tendency to be inserted in RAM in an order we don't have full control over.
 * For example the Rain Gauge can wake up the ECU the same as daylight... the systems need each other, but if both are static "who spawns first?"
 * Here all "interrupts" are packaged in one ugly static thing so the rest of the system can spawn on an as needed basis.
 * Created: 12/27/2019 7:18:16 PM
 * Author: Tristan Callahan
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "Arduino.h"
#include "Clock.h"
#include <avr/sleep.h>


namespace Interrupts
{
	//sleepMode
	static boolean isItBedtime;
	//raingauge
	static long rainGaugeTicks = 0;
	volatile static int rainGaugeSwitchPinState = HIGH;
	volatile static int rainGaugeValvePinState = LOW;
	static const int rainGaugeValve = 13;
	static const int rainGaugeSwitch = 2;
	static AutoFarm::TimeStamp rainGaugeValveTimeOpened;
	//lightsensor
	static const int lightSensorPin = 3;
	volatile static boolean isItDaylight = true;

	class Interrupt
	{

			private:
			
					
			public:
			
			static long getRainInInches()
			{
				long temp = rainGaugeTicks * .5; //some arbitrary number. Needs calibration with final bucket switch float switch thingy.
				rainGaugeTicks = 0;
				return temp;
			}
			
			
			
			static void setRainGaugeValvePinState(int s)
			{
				if (s == HIGH || s == LOW)
				{
					rainGaugeValvePinState = s;
				}
			}
			
			static void setRainGaugeValveOpenTime()
			{
				rainGaugeValveTimeOpened = AutoFarm::Clock::currentTimeStamp();
			}
			
			static AutoFarm::TimeStamp getRainGaugeValveOpenTime()
			{
				return rainGaugeValveTimeOpened;
			}
			
			static int getRainGaugePinState()
			{
				return rainGaugeSwitchPinState;
			}
			
			static int getRainGaugeValveState ()
			{
				return rainGaugeValvePinState;
			}
			
			static bool isItTimeToSleep() 
			{ 
				return isItBedtime;
			}
			
			
			static void goDark()
			{
				isItDaylight = false;
				isItBedtime = true;
			}
		
			static void rainGaugeISR()
			{
				detachInterrupt(digitalPinToInterrupt(rainGaugeSwitch));
				rainGaugeSwitchPinState = HIGH;
			}
			
			static void rainGaugeTickProcessed()
			{
				rainGaugeTicks = rainGaugeTicks + 1;
				rainGaugeSwitchPinState = LOW;
				attachInterrupt(digitalPinToInterrupt(rainGaugeSwitch), rainGaugeISR, RISING);
			}
			
			static void rainTickWakeUp()
			{
				sleep_disable();
				detachInterrupt(digitalPinToInterrupt(rainGaugeSwitch));
				detachInterrupt(digitalPinToInterrupt(lightSensorPin));
				rainGaugeISR();
				//need to handle waking up the light sensor to go dark again but what if it is raining at night.
				attachInterrupt(digitalPinToInterrupt( rainGaugeSwitch ), rainGaugeISR, RISING);
				attachInterrupt(digitalPinToInterrupt(lightSensorPin), goDark, LOW);
			};
			
			static void wakeUp()
			{
				sleep_disable();
				detachInterrupt(digitalPinToInterrupt(rainGaugeSwitch));
				detachInterrupt(digitalPinToInterrupt(lightSensorPin));
				isItBedtime = false;
				isItDaylight = true;
				attachInterrupt(digitalPinToInterrupt( rainGaugeSwitch ), rainGaugeISR, RISING);
				attachInterrupt(digitalPinToInterrupt(lightSensorPin), goDark, FALLING);
				//resume normal operation
			};
			
			
			 static void goToSleep()
			 {
				 detachInterrupt(digitalPinToInterrupt(rainGaugeSwitch));
				 detachInterrupt(digitalPinToInterrupt(lightSensorPin));
				 sleep_enable();
				 
				 attachInterrupt(digitalPinToInterrupt( rainGaugeSwitch ), rainTickWakeUp, RISING);
				 attachInterrupt(digitalPinToInterrupt(lightSensorPin), wakeUp, RISING);
				 
				 set_sleep_mode(SLEEP_MODE_PWR_DOWN);
				 sleep_cpu();
			 };
	};

}

#endif /* INTERRUPT_H_ */