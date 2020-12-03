/*
 * BatteryMonitorTask.h
 *
 * Created: 12/8/2019 4:51:50 PM
 *  Author: T
 */ 


#ifndef BATTERYMONITORTASK_H_
#define BATTERYMONITORTASK_H_

#include "Task.h"
#include "BatteryMonitor.h"

namespace TaskManager
{
	


	class BatteryMonitorTask :  public Task
	{
	
		private:
		BatteryMonitor bm;
		
		public:
		BatteryMonitorTask() = default;
		~BatteryMonitorTask() = default;
	
	
		virtual bool test() { bm.isBatteryChargingCorrectly();};
		virtual void execute() 	{ bm.execute();	};	//execute this task. overridden as a call to singleton with static members
		virtual void preempt() {}; //do I even use this?
		
	};

}
	
#endif /* BATTERYMONITORTASK_H_ */