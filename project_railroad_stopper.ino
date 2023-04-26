//import servo motor
#include <Servo.h>
Servo myservo;
//set pin
const int trigPin=4;
const int echoPin=6; 
long tmeduration;
int distance;

int buzzer=2;
int c=268;
int d=294;

void setup() 
{
  myservo.attach(2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);  
  pinMode(buzzer,OUTPUT);
}
 
void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  tmeduration=pulseIn(echoPin,HIGH);
  distance=(0.034*tmeduration)/2;
 
if(distance<=10)
{
  tone(buzzer,c,500);
  delay(300);
  tone(buzzer,d,500);
  delay(300);
  myservo.write(0);
  delay(1800);
}
else
{
  myservo.write(90);
  delay(50);
}
  
}


