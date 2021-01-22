/*
 * IrrigationTask.h
 *
 * Created: 12/8/2019 4:51:19 PM
 *  Author: TC
 */ 


#ifndef IRRIGATIONTASK_H_
#define IRRIGATIONTASK_H_

#include "Task.h"
#include "IrrigationValve.h"
#include "Clock.h"


namespace TaskManager
{
	
	

	class IrrigationTask :  public Task
	{
		
		private:
		IrrigationValve ir;
		
		public:
	
		virtual bool test() 
		{
			if ( (ir.getLastIrrigationReport().unixtime - AutoFarm::Clock::currentTimeStamp().unixtime ) >  86400 )
			{
				ir.saveIrrigationReport();
			}
			
			
			if (ir.getIrrigationValveState() == HIGH)
			{
				return true;
			}
			return ir.shouldWeIrrigate();
		};
		
		virtual void execute() 
		{
			if(ir.getIrrigationValveState() == LOW)
			{
				ir.openValve();
			}
			ir.closeValve();
		};
			
		virtual void preempt() {}; //do I even use this?
		
	};

}
#endif /* IRRIGATIONTASK_H_ */