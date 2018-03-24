#include <Blynk.h>

#define BLYNK_PRINT Serial

#include <SPI.h>



#define WIFISSID "SRM-Event"
#define PASSWORD "SRMist#4444"
char auth[] = "5f31c5e4fe6749dd980f7aa268979d68";   
WidgetLED led1(V1);   
WidgetLED led2(V2);
WidgetLED led3(V3);
int sensor1 = 2;      
int sensor2 = 3;
int sensor3 = 4;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);  
  
  pinMode(sensor3,INPUT);  
  
  pinMode(sensor2,INPUT);
  
  pinMode(sensor1,INPUT);
  client.wifiConnection(WIFISSID, PASSWORD);

  while (Blynk.connect() == false) {
    
  }
}
void loop() {  
   int sensorval1 = digitalRead(sensor1); 
   int sensorval2 = digitalRead(sensor2);
   int sensorval3 = digitalRead(sensor3);
   Serial.println(sensorval1);             
   Serial.println(sensorval2);
   Serial.println(sensorval3);
   delay(1000);
   if (sensorval1 == 1)
   {
led1.on();  
client.sendAll(true);
}
   if (sensorval2 == 1)
   {
led2.on();
client.sendAll(true);
}
   if (sensorval3 == 1)
   {

led3.on();
client.sendAll(true);
}
    if (sensorval1 == 0)
   {

led1.off();
client.sendAll(false);

}
   if (sensorval2 == 0)
   {
led2.off();
client.sendAll(false);
}
   if (sensorval3 == 0)
   {
led3.off();
client.sendAll(false);
}   
    
    Blynk.run();
    
     }
