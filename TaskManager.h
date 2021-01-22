/*
 * TaskManager.h
 *
 * Created: 12/8/2019 2:33:30 PM
 *  Author: TC
 */ 


#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <Arduino.h>
#include "TimeStamp.h"
#include "Clock.h"
#include "Task.h"
#include "EventListener.h"	//inputs and timed events
#include "TaskList.h"		//output queue


#include "BatteryMonitorTask.h"
#include "RainGaugeTask.h"
#include "IrrigationTask.h"
#include "SleepTask.h"
#include "Interrupt.h"


namespace TaskManager 
{
	
	class TaskManager
	{
		private:
		
		
		EventListener* eventListener;
		TaskList* taskList;
		BatteryMonitorTask* batteryMonitorTask;
		RainGaugeTask* rainGaugeTask;
		IrrigationTask* irrigationTask;
		SleepTask* sleepTask;
		
		void checkEvents();
		void performOutputs();
		void prioritize();
			
		public:
		
		TaskManager()
		{
			
		}
		
		void initialize();
		
		void mainLoop();
		
		~TaskManager() 
		{
			
			delete eventListener;
			delete taskList;
			delete batteryMonitorTask;
			delete rainGaugeTask;
			delete irrigationTask;
			delete sleepTask;
		}	
	};
	
}


#endif /* TASKMANAGER_H_ */