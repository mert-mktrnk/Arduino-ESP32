#include <dht11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int Dht_11 = 4;
const int Nem_Sensoru_1 = A0;
const int Nem_Sensoru_2 = A1;
const int LDR_Sensoru = A2;
const int Led_1 = D1;
const int Led_2 = D2;
const int Motor_1 = D3;
const int Motor_2 = D4;

dht11 DHT11;
LiquidCrystal_I2C lcd(0x3F,20,4);

void setup()
{
  pinMode(Nem_Sensoru_1, INPUT);
  pinMode(Nem_Sensoru_2, INPUT);
  pinMode(LDR_Sensoru, INPUT);
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Motor_1, OUTPUT);
  pinMode(Motor_2, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop()
{
  
}
