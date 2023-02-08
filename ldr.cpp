#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   
}

unsigned int input_values = 0;

void brightness_control(void)
{
  /*read the LDR values*/
input_values = analogRead(LDR_SENSOR);

/* reverse  map them from 0 to 1023 to 0*/
input_values = (1023 - input_values)/4;


/*write the values to the led */
  analogWrite(GARDEN_LIGHT,input_values);

  delay(100);
}
