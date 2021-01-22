/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "TaskManager.h"

/*End of auto generated code by Atmel studio */

//out here in the void Arduino hardware may not be initialized yet.
TaskManager::TaskManager tm; //= new TaskManager::TaskManager;




void setup() {
  
  //initialize serial communication

  Serial.begin(9600);
  //it is safer to initialize here as hardware is up and running by this stage. Setup() is only run once.
  tm.initialize();
}



void loop() {
    
   tm.mainLoop();
   
}
