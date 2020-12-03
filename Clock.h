/*
 * Clock.h
 *
 * Created: 12/8/2019 4:43:34 PM
 *  Author: T
 */ 


#ifndef CLOCK_H_
#define CLOCK_H_

#include "RTClib.h"
#include "TimeStamp.h"



namespace AutoFarm 
{
	
	
	
	class Clock {
		
		private:
		
		
		static RTC_DS3231 rtc;
		
		static Clock* instance;
		
		Clock() {};
		
		public:
		static Clock* initialize()
		{
			if (instance == nullptr)
			{
				instance = new Clock();
			}
			return instance;	
		};
		
		static void resetClock()
		{
			if (rtc.lostPower()) {
				Serial.println("RTC lost power, lets set the time!");
				// following line sets the RTC to the date & time this sketch was compiled
				rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
				// This line sets the RTC with an explicit date & time, for example to set
				// January 21, 2014 at 3am you would call:
				// rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
			}
		};
		
		
		static AutoFarm::DateStamp currentDateStamp()
		{
			DateTime now = rtc.now();
			AutoFarm::DateStamp ds {now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second(), now.dayOfTheWeek() };
			return ds;
		};
		
		static AutoFarm::TimeStamp currentTimeStamp()
		{
			DateTime now = rtc.now();
			AutoFarm::TimeStamp ts {now.unixtime() };
			return ts;
		};
		
		
		static float getSystemTemp()
		{
			return float(rtc.getTemperature());
		};
		
	};
	
	
	

}
#endif /* CLOCK_H_ */