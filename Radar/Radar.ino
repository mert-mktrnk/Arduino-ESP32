#include <Servo.h>

const int trigPin = D0;
const int echoPin = D1;

float sure = 0;
int mesafe = 0;

Servo myServo;

void setup() 
{
  myServo.attach(D9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  for(int i = 15; i <= 165; i++)
  {
    myServo.write(i);
    delay(30);
    mesafe = mesafeHesaplama();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(mesafe);
    Serial.print(".");
  }
  for(int i = 165; i > 15; i--)
  {  
    myServo.write(i);
    delay(30);
    mesafe = mesafeHesaplama();
    Serial.print(i);
    Serial.print(",");
    Serial.print(mesafe);
    Serial.print(".");
  }
}

int mesafeHesaplama()
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure * 0.034 / 2;
  return mesafe;
}