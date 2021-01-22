/*
 * EventList.h
 *
 * Created: 12/8/2019 4:44:09 PM
 *  Author: TC
 */ 


#ifndef TASKLIST_H_
#define TASKLIST_H_



#include "Event.h"
#include "Vector.h"


namespace TaskManager
{
	
	//EventList lightly encapsulates and abstracts custom Vector and provides a few basic services like checking if it's even sorted.
	
	class TaskList {
		private:
		Vector::Vector list;
		Event buffer;

		

		public:

		bool isEmpty() {return list.empty();}
		
		Event getNext()
		{		
			if (!isEmpty())
			{
				buffer = list.backCopy();
				list.pop_back();
				return buffer;
			} 
		};
		
		void addEvent(Event e) {list.push_back(e);};
		
		int getSize() {return list.size();};
		
		uint8_t printTask(int i) {return list[i]->taskPriority;};

		void sort(void) {list.prioritize();};

		bool isSorted()
		{
			for (int i = 0; i!=list.size(); ++i)
			{
				if (list[i+1]->taskPriority > list[i]->taskPriority) {
					return false;
				}
			}
			return true;
		};	
	};

	
}


#endif /* TASKLIST_H_ */