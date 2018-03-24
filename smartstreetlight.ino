int led = 2;
int led1 = 3;
int led2 = 4;

int ldr = A0;

int ir = A1;
int ir1 = A2;
int ir2 = A3;

void setup()
{
  Serial.begin (9600);
  pinMode (led,OUTPUT);
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);

  pinMode (ldr,INPUT);

  pinMode (ir,INPUT);
  pinMode (ir1,INPUT);
  pinMode (ir2,INPUT);
}
void loop()
{
  Serial.println(analogRead(A0));
   int ldrStatus = analogRead (ldr);
     if (ldrStatus >=300)
     {
      digitalWrite(led, HIGH);
      analogWrite(led,255/5);

      digitalWrite(led1, HIGH);
      analogWrite(led1,255/5);

      digitalWrite(led2, HIGH);
      analogWrite(led2,255/5);


      if(analogRead(A1)>500)
      {
        digitalWrite(led, HIGH);
        analogWrite(led,255/2);
      }
      else
      {
        digitalWrite(led, HIGH);
        delay(1000);
      }

      if(analogRead(A2)>500)
      {
        digitalWrite(led1, HIGH);
        analogWrite(led1,255/2);
      }
      else
      {
        digitalWrite(led1, HIGH);
        delay(1000);
      }

      if(analogRead(A3)>500)
      {
        digitalWrite(led2, HIGH);
        analogWrite(led2,255/2);
      }
      else
      {
        digitalWrite(led2, HIGH);
        delay(1000);
      }
     }
     else
     {
      digitalWrite(led, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
     }
}
