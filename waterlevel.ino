#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(11, 12); // RX, TX
 
#define TRIGGER 9
#define ECHO 8
 
 
 
 
char auth[] = "efc3b8d9af644f44adc7136a96bc9a4a";
 
SoftwareSerial SerialBLE(10, 11); // RX, TX
 
 
BLYNK_WRITE(V5)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
 
 
}
 
void setup()
{
 
  Serial.begin(9600);
 
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
 
  Serial.println("Waiting for connections...");
 
 
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}
 
void loop()
{
 
 
   long duration, distance;
  digitalWrite(TRIGGER, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(300);
 
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration*0.034 / 2;
  Blynk.virtualWrite(V5, distance);
  {
   if(distance<5)
  {
    Blynk.email("alokblackerry20@gmail.com","alert","dustbin is full");
    Blynk.notify("alert-dustbin is full");
  }
  }
  delay(200);
  Blynk.run();
 
}

