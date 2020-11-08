#include <Servo.h>
#include <math.h>  

double P = 15;
double Rx;
double czas;
double PoczatkowaOdleglosc = 100;
double ObecnaOdleglosc;
double Dlugosc= 8;
Servo servo;
int SPin = 5;
int start = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(3);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  czas = pulseIn(echoPin, HIGH);
  return 0.017 * time;
}

void setup()
{
  Serial.begin(9600);
  servo.attach(SPin);
  servo.write(0);
}

void loop()
{
ObecnaOdlegosc = readUltrasonicDistance(7, 7) - PoczatkowaOdleglosc
  start = int(ObecnaOdleglosc / 10) * P;
Rx = atan(start/dlugosc)*180/3.14;
 
  Serial.println(Rx);
  servo.write(P*Rx);
}

