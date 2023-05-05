#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

const int cable = D12;
const int buzzer = D0;
const int button = D15;

int degmeSayisi = 0;

static void giris_lcd(void);
static void oyun_start_yazi(void);
static void oyun_baslama(void);
static void oyun_yuklenme(void);

bool statebutton = false;
bool statecable = false;
bool loopstate = false;

void setup() 
{
  pinMode(cable, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  lcd.init();
  lcd.backlight();
  giris_lcd();
}

void loop()
{
  statebutton = digitalRead(button);

  if(statebutton == true)
  {
    statebutton = false;

    oyun_yuklenme();

    oyun_baslama();

    while(loopstate)
    {
      statebutton = digitalRead(button);
      statecable = digitalRead(cable);

      if(statecable == true)
      {
        statecable = false;
        digitalWrite(buzzer, HIGH);
        degmeSayisi++;
        lcd.setCursor(2,2);
        lcd.print("DEGME SAYISI: ");
        lcd.setCursor(16,2);
        lcd.print(degmeSayisi);
        delay(250);
        digitalWrite(buzzer, LOW);
      }
      else
      {
        digitalWrite(buzzer, LOW);
      }
      if(statebutton == true)
      {
        loopstate= false;
      }
    }
  }
}

static void giris_lcd(void)
{
  lcd.setCursor(2,0);
  lcd.print("IYI EGLENCELER");
  lcd.setCursor(4,1);
  lcd.print("DENEYAP SUR");
  lcd.setCursor(0,2);
  lcd.print("Oyuna baslamak icin");
  lcd.setCursor(0,3);
  lcd.print("Tusa basiniz");
  delay(5000);
}

static void oyun_start_yazi(void)
{
  lcd.setCursor(1,0);
  lcd.print("IYI EGLENCELER");
  lcd.setCursor(4,1);
  lcd.print("DENEYAP SUR");
  lcd.setCursor(0,2);
  lcd.print("Oyuna baslamak icin");
  lcd.setCursor(0,1);
  lcd.print("Tusa basiniz");
}

static void oyun_baslama(void)
{
  degmeSayisi = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dikkat ediniz");
  lcd.setCursor(4,1);
  lcd.print("Bulbul otmesin");
  lcd.setCursor(2,2);
  lcd.print("DEGME SAYISI: ");
  lcd.setCursor(16,2);
  lcd.print(degmeSayisi);
}

static void oyun_yuklenme(void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Oyun yukleniyor");
  lcd.setCursor(0,1);
  lcd.print("...");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print("...");
  delay(1000);
  lcd.setCursor(6,1);
  lcd.print("...");
  delay(1000);
  loopstate = true;
}