const int sensor1 = D12;
const int sensor2 = D13;
const int sensor3 = D14;
const int sensor4 = D15;

#define FRONT_LEFT D12 // pin 2 for front-left sensor
#define FRONT_RIGHT D13 // pin 3 for front-right sensor
#define REAR_LEFT D14 // pin 4 for rear-left sensor
#define REAR_RIGHT D15 // pin 5 for rear-right sensor
#define BREAK 8 // pin 8 to apply break or turn LED ON
#define FRONT_OB 9 // pin 9 when obstacle is at front
#define REAR_OB 10 // pin 10 when obstacle is at rear

void setup() {
  Serial.begin(9600);
  pinMode(FRONT_LEFT, INPUT);//define front-left input pin
  pinMode(FRONT_RIGHT, INPUT);//define front-right input pin
  // 4 Infrared Obstacle code for Robojax.com
  pinMode(REAR_LEFT, INPUT);//define rear-left input pin
  pinMode(REAR_RIGHT, INPUT);//define rear-right input pin
}

void loop() 
{
  int FR = digitalRead(FRONT_RIGHT);// read FRONT_LEFT sensor
  int FL = digitalRead(FRONT_LEFT);// read FRONT_RIGHT sensor
  int RR = digitalRead(REAR_RIGHT);// read REAR_RIGHT sensor
  int RL = digitalRead(REAR_LEFT);// read REAR_LEFT sensor   

  if( FR == LOW || FL == LOW)
  {
    Serial.println("1");
  }
  else
  {
    Serial.println("2");
  }


  if( RR == LOW || RL == LOW )
  {
    Serial.println("3");
  }
  else
  {
    Serial.println("4");
  }

  delay(200);
}

/*
int ENA = D9;
int ENB = A5;

const int IN1 = D10;
const int IN2 = D2;
const int IN3 = D3;
const int IN4 = A6;

static void turn_right(void);
static void turn_left(void);
static void go_forward(void);
static void go_back(void);
static void stop(void);
static void test(void);

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  turn_right();
  delay(1000);
  turn_left();
  delay(1000);
  go_forward();
  delay(1000);
  go_back();
  delay(1000);
  stop();
  delay(1000);
}

static void test(void)
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
}

static void turn_right(void)
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, HIGH);
}

static void turn_left(void)
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, LOW);
}

static void go_forward(void)
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
}

static void go_back(void)
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
}

static void stop(void)
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
}
*/