/*
 * Vector.cpp
 *
 * Created: 12/20/2019 12:40:51 PM
 *  Author: T
 */ 

//#include "Priority.h"
#include "Event.h"
#include "Vector.h"



namespace Vector {
	
//boolean : test if array is empty	
	boolean Vector::empty()
	{
		for(int i = 0; i < max; ++i)
		{
			if ( list[i] != nullptr )
			{
				return false;
			}
		}
		return true;
	}
	


//returns a pointer to the last element in the array
	TaskManager::Event Vector::backCopy()
	{
		if (!empty())
		{
			for (int i = 0; i < max; ++i)
			{
				if ( list[i] == nullptr )
				{
					TaskManager::Event ee;
						ee.taskPriority = list[i-1]->taskPriority;
						ee.time = list[i-1]->time;
						*ee.task = *list[i-1]->task;
					return ee;
				} 
				else if (i == (max - 1))
				{
					TaskManager::Event ee;
						ee.taskPriority = list[i]->taskPriority;
						ee.time = list[i]->time;
						*ee.task = *list[i]->task;
					return ee;	
				}
			}
		} 
	
	}
	
	TaskManager::Event* Vector::back()
	{
		if (!empty())
		{
			for (int i = 0; i < max; ++i)
			{
				if ( list[i] == nullptr )
				{
					return list[i-1];
				}
				else if (i == (max - 1))
				{
					return list[i];
				}
			}
		}
		
	}
	
	
	
	//deletes the last element in the array
	void Vector::pop_back()
	{		
		delete back();
	}

	
//takes an event data packet and pushes it on the stack.
	void Vector::push_back(TaskManager::Event e)
	{
		for (int i = 0; i < max; ++i)
		{
			if (list[i] == nullptr)
			{
				list[i] == new TaskManager::Event{e};
			}
		}
	}
	
	
	//return taskPriority which is also event type from event pointer
	uint8_t Vector::type(TaskManager::Event* e)
	{
		 return e->taskPriority;
	}
	
	//count number of nullptr elements in array
	int Vector::size()
	{
		int count {0};
		for(int i = 0; i < max; ++i)
		{
			if (list[i] == nullptr)
			{
				return count;
			} else if (i == (max-1) && list[i] != nullptr)
			{
				return count;
			}
			++count;
		}
	}
	
	//sort array by taskPriority
	void Vector::prioritize() {
		for (int i = 0; i < max; ++i)
		if (list[i+1]->taskPriority > list[i]->taskPriority)
		{
			TaskManager::Event* Buff {list[i+1]};
			list[i+1] = list[i];
			list[i] = Buff;
		}
		
	}
	
	TaskManager::Event* Vector::operator[](int n)
	{
		return list[n];
	}
		
}