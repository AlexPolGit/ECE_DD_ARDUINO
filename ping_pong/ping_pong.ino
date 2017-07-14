#include "MotorShield.h"

MS_DCMotor motorA(MOTOR_A);
MS_DCMotor motorB(MOTOR_B);

int MOTOR_SPEED = 0;
int MOTOR_RPM = 0;
String readString = "";

int IR1 = A3;
int IR2 = A2;
int ir_val_1 = 0;
int ir_val_2 = 0;

int writeValues = 0;

long second = 0;
long counts = 0;

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
  if (second < millis())
  {
    second++;
  }
  
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

  if (second = 1000)
  {
    MOTOR_RPM = counts;
    second = 0;
    counts = 0;
  }
  else if (ir_val_2 < 900)
  {
    counts++;
    Serial.println("Current RPM: " + String(MOTOR_RPM));
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


