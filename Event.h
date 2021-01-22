/*
 * Event.h
 *
 * Created: 12/8/2019 2:31:05 PM
 *  Author: Tristan Callahan
 */ 


#ifndef EVENT_H_
#define EVENT_H_

#include "TimeStamp.h"
#include "Task.h"

namespace TaskManager
{
	struct Event 
	{
		uint8_t taskPriority;
		AutoFarm::TimeStamp time;
		Task* task;			
	};
}


#endif /* EVENT_H_ */