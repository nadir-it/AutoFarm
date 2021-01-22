/*
 * Vector.h - Vector is a hack to resolve ATmega328p not having a full C++11 STL implementation 
 * On any system which supports it you might as well #include <vector> and you will get almost the same results
 * except for backCopy()... this was basically an early morning hack... or was it late night?
 * Created: 12/8/2019 6:00:49 PM
 *  Author: Tristan Callahan
 */ 


#ifndef VECTOR_H_
#define VECTOR_H_

#include "Event.h"


namespace Vector
{
	


	class Vector {

	private:

		constexpr static int max {10};
		TaskManager::Event* list[max];

	public:

		Vector () {};
		
		 boolean empty();
		 
		 TaskManager::Event* back();
		 TaskManager::Event backCopy();
		 
		 void pop_back();
		 
		 void push_back(TaskManager::Event e);
		 
		 static uint8_t type(TaskManager::Event* e);
	
		int size();
	
		void prioritize();
		
		TaskManager::Event* operator[](int n);
		~Vector() {};

	
	};


}
#endif /* VECTOR_H_ */