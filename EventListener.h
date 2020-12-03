/*
 * EventListener.h
 *
 * Created: 12/22/2019 5:56:31 PM
 *  Author: T
 *		First come first served. Event listener gives highest priority 0 to the first event subscription
 */ 


#ifndef EVENTLISTENER_H_
#define EVENTLISTENER_H_

#include "TimeStamp.h"
#include "Clock.h"
#include "Event.h"

#include "Task.h"


namespace TaskManager
{
	//node for linked list. needs PAYLOAD (function pointers, lambda... whatever) 

	struct Node 
	{
		uint8_t priority;
		Node* nextNode;
		//payload is either this or a couple of pointers bool and void?
		Task* task;	
	};


// bool (*test)();         =func pointer that takes no arguements and returns an int
//use like bool b = (*test)();
//void (*execute)();   void?
// int (*const fncPtr)();   =const  func pointer that takes no arguements and returns an int

	class EventListener
	{
		private:
		Node* head;
		Node* tail;
		
		
		public:
		
		EventListener()   {head=nullptr; tail=nullptr;};
			
		Node* getNext(Node* node) 
		{
			if(node == nullptr)
			{
				node = head;
			}
			return node->nextNode;
		}
		
		//FIX Should be a function pointer not a Task pointer
		
		void addSubscription(  Task* t )
		{
			Node* temp = new Node;
			
			temp->nextNode = nullptr;
			//temp->test = test;
			temp->task = t;
			
			if (head == nullptr)
			{
				temp->priority = 0;
				head = temp;
				tail = temp;
			}
			else
			{
				temp->priority = tail->priority + 1;
				tail->nextNode = temp;
				tail = temp;
			}
		}
		
		
		//iterate function example
		void printList()
		{
			Node* current = head;
			
			while(current != nullptr)
			//do some stuff
			current = current->nextNode;
			
		}
		
		bool isEmpty()
		{
			if(head == nullptr)
			{
				return true;
			}
			else 
			{
				return false;
			}
			
		}
		
		Node* getStart()
		{
			return head;
		}
		
		
	};

}


#endif /* EVENTLISTENER_H_ */