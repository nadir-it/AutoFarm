/*
 * Task.h
 *
 * Created: 12/8/2019 4:43:23 PM
 *  Author: TC
 */ 


#ifndef TASK_H_
#define TASK_H_

namespace TaskManager {
	
	class Task
	{
		
		public:
		
		virtual bool test() = 0;
		virtual void execute() = 0;	//execute this task. overridden as a call to singleton with static members
		virtual void preempt() = 0; //do I even use this?
		
		virtual ~Task() {};
				
	};
	
	
}



#endif /* TASK_H_ */