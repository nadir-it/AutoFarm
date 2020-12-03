/*
 * RainGaugeTask.h
 *
 * Created: 12/8/2019 4:51:33 PM
 *  Author: T
 */ 


#ifndef RAINGAUGETASK_H_
#define RAINGAUGETASK_H_

#include "Task.h"
#include "RainGauge.h"

namespace TaskManager
{
	

	class RainGaugeTask :  public Task
	{
		private:
		RainGauge rg;
		
		public:
		
			RainGauge* getRainGaugePointer()
			{
				return &rg;
			};
		
			virtual bool test() 
			{
				if (rg.getSwitchState() == HIGH)
				{
					return true;	
				}
				else
				{
					return false;
				}	 
			};
			
			virtual void execute() 
			{
				if (rg.getValveState() == LOW)
				{
					rg.openValve();	
				}		
				rg.closeValve();	
			};	//execute this task. overridden as a call to singleton with static members
			
			virtual void preempt() {}; //do I even use this?
			
			~RainGaugeTask() {};
	};

}
#endif /* RAINGAUGETASK_H_ */