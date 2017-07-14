#include "MotorShield.h"

MS_DCMotor motorA(MOTOR_A);
MS_DCMotor motorB(MOTOR_B);

unsigned int MOTOR_SPEED = 0;
unsigned int MOTOR_RPM = 0;
String readString = "";

unsigned int IR1 = A3;
unsigned int IR2 = A2;
unsigned int ir_val_1 = 0;
unsigned int ir_val_2 = 0;

const unsigned int SECOND = 1000;
unsigned long counts = 0;

unsigned long previousMillis = 0;

void setup()
{
  motorA.setSpeed(MOTOR_SPEED);
  motorB.setSpeed(MOTOR_SPEED);

  motorA.run(BACKWARD);
  motorB.run(FORWARD);

  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();
  
  while (Serial.available())
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  if (readString.length() > 0)
  {
    Serial.println("Setting Speed to: " + readString);
    MOTOR_SPEED = readString.toInt();
    motorA.setSpeed(MOTOR_SPEED);
    motorB.setSpeed(MOTOR_SPEED);
    readString = "";
  }

  ir_val_1 = analogRead(IR1);
  ir_val_2 = analogRead(IR2);

  if (currentMillis - previousMillis >= SECOND)
  {
    MOTOR_RPM = counts;
    previousMillis = currentMillis;
    counts = 0;

    Serial.println("Current RPS: " + String(MOTOR_RPM));
  }
  else if (ir_val_2 < 800)
  {
    counts++;
    delay(1);
    //Serial.println("IR Sensor 2 Detection!: " + String(ir_val_1));
  }
}

int RPM_TO_SPEED(int rmp)
{
  return 0;
}

int SPEED_TO_RPM(int spd)
{
  return 0;
}


