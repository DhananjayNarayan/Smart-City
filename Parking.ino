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
