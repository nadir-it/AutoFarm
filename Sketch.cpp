/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "TaskManager.h"

/*End of auto generated code by Atmel studio */

TaskManager::TaskManager tm; //= new TaskManager::TaskManager;




void setup() {
  
  //initialize serial communication

  Serial.begin(9600);
  
  tm.initialize();
}



void loop() {
    
   tm.mainLoop();
   
}
