/*
 * SleepTask.h
 *
 * Created: 12/8/2019 4:52:25 PM
 *  Author: T
 */ 


#ifndef SLEEPTASK_H_
#define SLEEPTASK_H_

#include "Task.h"
#include "Sleep.h"




namespace TaskManager
{
	

	class SleepTask :  public TaskManager::Task
	{
	
	private:
	Sleep sl;
	
	public:
	
		
	
		virtual bool test() 
		{
			return sl.shouldWeSleep();
		};
		
		virtual void execute() 
		{
			sl.sleep();
		};
				
		virtual void preempt() {}; //do I even use this?
		
		~SleepTask() {};
	};
}
#endif /* SLEEPTASK_H_ */