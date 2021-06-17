#include <Wire.h>

int sensor = 25;        //GPIO 25
int relay = 32;         //GPIO 32

void setup() 
{
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
}

bool reading(int sensor)
{
     Serial.println ("function reading");
     int reading;
     reading = analogRead(sensor);  
     Serial.println ("sensor value: ");
     Serial.println (reading);
     if(reading < 3000 && reading > 2000)
     {
        return true;
     }
     else 
     {
        return false;
     }
}

void pump(int relay, bool reading)
{
   Serial.println ("function pump");
   if(reading == true)
   {
     Serial.println ("reading == true");
     digitalWrite(relay, LOW);
     Serial.println ("pump on");
     delay(5000);
     digitalWrite(relay, HIGH);
     Serial.println ("pump off");
   }

   if(reading == false)
   {
     Serial.println ("reading == false");
     Serial.println ("pump off");
   }
}

void loop() 
{
  Serial.println ("Loop");
  pump(relay, reading(sensor));
  delay(86400000);
}
