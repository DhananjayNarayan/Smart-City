#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(11, 12); // RX, TX

#define TRIGGER 9
#define ECHO 8




char auth[] = "efc3b8d9af644f44adc7136a96bc9a4";

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
  distance = (duration/2) / 29.1;
  Blynk.virtualWrite(V5, distance);
  delay(200);
  Blynk.run();
  
}
