#include <Deneyap_Servo.h>

const int Servo_sag_sol = D12;
const int Servo_ileri_geri = D13;
const int Servo_asagi_yukari = D14;
const int Servo_kiskac = D15;

const int Analog_sag_sol = A2;
const int Analog_ileri_geri = A3;
const int Analog_asagi_yukari = A1;
const int Analog_kiskac = A0;

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;

int sag_sol = 0;
int ileri_geri = 0;
int asagi_yukari = 0;
int kiskac = 0;

int sag_sol_aci = 0;
int ileri_geri_aci = 0;
int asagi_yukari_aci = 0;
int kiskac_aci = 0;

void setup() 
{
  servo_1.attach(Servo_sag_sol);
  servo_2.attach(Servo_ileri_geri);
  servo_3.attach(Servo_asagi_yukari);
  servo_4.attach(Servo_kiskac);
}

void loop()
{
  sag_sol = analogRead(Analog_sag_sol);      
  ileri_geri = analogRead(Analog_ileri_geri);
  asagi_yukari = analogRead(Analog_asagi_yukari);
  kiskac = analogRead(Analog_kiskac);

  sag_sol_aci = map(sag_sol, 0, 1023, 0,179);
  ileri_geri_aci = map(ileri_geri, 1023, 0, 20,150);
  asagi_yukari_aci = map(asagi_yukari, 0, 1023, 50,150);
  kiskac_aci = map(kiskac, 0, 1023, 10,90);

  servo_1.write(sag_sol_aci);
  servo_2.write(ileri_geri_aci);
  servo_3.write(asagi_yukari_aci);
  servo_4.write(kiskac_aci);
}