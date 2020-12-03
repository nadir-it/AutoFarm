/*
 * TimeStamp.h
 *
 * Created: 12/22/2019 9:06:55 PM
 *  Author: T
 */ 


#ifndef TIMESTAMP_H_
#define TIMESTAMP_H_

#include "RTClib.h"

namespace AutoFarm
{
	
	struct TimeStamp
	{
		uint32_t unixtime; //unix time in seconds... divide by 300 for 5 minutes for example. 
	};
	
	struct DateStamp
	{
		uint16_t year;
		uint8_t month;
		uint8_t day;
		uint8_t hour;
		uint8_t minute;
		uint8_t second;
		uint8_t dayOfWeek;	
	};

}


#endif /* TIMESTAMP_H_ */