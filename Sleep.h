/*
 * Sleep.h
 *
 * Created: 12/8/2019 4:54:35 PM
 *  Author: TC
 */ 


#ifndef SLEEP_H_
#define SLEEP_H_

#include "Interrupt.h"	
	
	class Sleep {
	
		private:
		
		
		public:
		
		Sleep() {};
		
		bool shouldWeSleep()
		{
			return Interrupts::Interrupt::isItTimeToSleep();
		};
		
		void sleep()
		{
			Interrupts::Interrupt::goToSleep();
		}
	
	
		~Sleep() {};
			
	};



#endif /* SLEEP_H_ */