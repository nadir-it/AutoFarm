/*
 * Priority.h
 *
 * Created: 12/8/2019 4:42:57 PM
 *  Author: T
 */ 


#ifndef PRIORITY_H_
#define PRIORITY_H_

namespace TaskManager
{
	enum priority	
	{
		pullBatteryRelay = 0,
		releaseBatteryRelay = 1,
		rainGaugePurge = 2,
		rainGaugeTick = 3,
		lightSensorHigh = 4,
		lightSensorLow = 5,
		irrigationValve = 6,
		batteryMonitor = 7,
		sleep = 8,
		nada = 99
	
		
	};
}



#endif /* PRIORITY_H_ */