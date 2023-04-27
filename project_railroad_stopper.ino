//import servo motor
#include <Servo.h>
Servo myservo;
//set pin
const int trigPin=4;
const int echoPin=6; 
long tmeduration;
int distance;

//set buzzer
int buzzer=2;
//set key melody
int c=268;
int d=294;

//set output/input
void setup() 
{
  myservo.attach(2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);  
  pinMode(buzzer,OUTPUT);
}

//loop code running program
void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  tmeduration=pulseIn(echoPin,HIGH);
  distance=(0.034*tmeduration)/2;

//condition railroad_stopper

if(distance<=10)//detect train
{
  //play sound
  tone(buzzer,c,500);
  delay(300);
  tone(buzzer,d,500);
  delay(300);
  //close barrier
  myservo.write(0);
  delay(1800);
}
else
{
  //open barrier
  myservo.write(90);
  delay(50);
}
  
}


