/*
 * TaskManager.cpp
 *
 * Created: 12/27/2019 10:45:17 AM
 *  Author: TC
 */ 

#include "TaskManager.h"
namespace TaskManager 
{
	

	void TaskManager::initialize()
	{
		eventListener = new EventListener;
		taskList = new TaskList;
		batteryMonitorTask = new BatteryMonitorTask;
		rainGaugeTask = new RainGaugeTask;
		irrigationTask = new IrrigationTask;
		sleepTask = new SleepTask;
		
		
		
		eventListener->addSubscription(batteryMonitorTask);
		eventListener->addSubscription(rainGaugeTask);
		eventListener->addSubscription(irrigationTask);
		eventListener->addSubscription(sleepTask);		
	}
	
	
	void TaskManager::checkEvents()
	{
		Event e;
		
		if ( !eventListener->isEmpty() )
		{
			
				Node* n = eventListener->getStart();
			
				
				auto makeEvent = [&e](Node* n) 
				{
					e.taskPriority = n->priority;
					e.time = AutoFarm::Clock::currentTimeStamp();
					e.task = n->task;
				};
				
				if (n->task->test() )
				{
					makeEvent(n);
					taskList->addEvent(e);
				}
			
				while (n->nextNode != nullptr )
				{
					n = eventListener->getNext(n);
					if (n->task->test() )
					{
						makeEvent(n);
						taskList->addEvent(e);
					}
				}	
		}	
	}
	
	void TaskManager::prioritize()
	{
		while ( !taskList->isEmpty() )
		{
			if( !taskList->isSorted() )
			{
				taskList->sort();
			}
		}
	}	
	
	void TaskManager::performOutputs()
	{
		Event e;
		while(!taskList->isEmpty())
		{
			e = taskList->getNext();
			e.task->execute();
		}
	}
	

	
	void TaskManager::mainLoop()
	{
		checkEvents();
		prioritize();
		performOutputs();	
	}


}