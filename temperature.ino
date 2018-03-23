#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>


char auth[] = "f6753691aa3441b28f19bdc5c90ed28d"; 
float temp;
int tempPin = 14; 

SimpleTimer timer;

void setup()
{
  Serial.begin(9600); 
  Blynk.begin(auth, "SRM-Event", "SRMist#4444"); 
  timer.setInterval(1000L, sendUptime);
}


void sendUptime()
{
   Blynk.virtualWrite(10, temp); 
}
