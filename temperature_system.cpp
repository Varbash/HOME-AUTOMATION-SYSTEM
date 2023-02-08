#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


void init_temperature_system(void)
{
  /*Setting Heater and Cooler pin as Output pins */  
    pinMode(HEATER,OUTPUT);
    pinMode(COOLER,OUTPUT);

  /*iNITIALLY TURNING OFF THE HEATER AND COOLER*/
    digitalWrite(HEATER,LOW);
    digitalWrite(COOLER,LOW);

}

float read_temperature(void)
{
    float temperature;

  //reading the analog output voltage fromtemperature sensor and converting it to deg cel (10mv-> 1deg cel)
  temperature = float (((analogRead(A0) *(float)5/ 1023)) /(float) 0.01);

  return temperature;
}

void cooler_control(bool control)
{
  digitalWrite(COOLER,control);
   
}
void heater_control(bool control)
{
  digitalWrite(HEATER,control);
    
}
