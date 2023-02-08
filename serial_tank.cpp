#include "serial_tank.h"
#include "Arduino.h"
#include "main.h"

unsigned int volume_value;
unsigned char valueh, valuel;

void init_serial_tank(void) 
{
    Serial.begin(19200);
    Serial.write(0xFF); //sincroniza comunicação
    Serial.write(0xFF);
    Serial.write(0xFF);   
}
/*to read volume of water in tank n return it*/
unsigned int volume(void)
{
  /*sending command to request volume of water*/
    Serial.write(VOLUME);
    /*waiting for serial data*/
    while(!Serial.available());
    /*reading the higher byte*/
    valueh = Serial.read();

    while(!Serial.available());
    /*reading the lower byte*/
    valuel = Serial.read();
    volume_value = (valueh << 8) | valuel;
    return volume_value;
    
}
void enable_inlet(void)
{
  /*to enable the inlet valve*/
    Serial.write(INLET_VALVE);
    Serial.write(ENABLE);
    
}  
void disable_inlet(void)
{
    Serial.write(INLET_VALVE);
    Serial.write(DISABLE);
    
}  
void enable_outlet(void)
{  
    Serial.write(OUTLET_VALVE);
    Serial.write(ENABLE);
    
}
void disable_outlet(void)
{  
    Serial.write(OUTLET_VALVE);
    Serial.write(DISABLE);
    
}
