#include "MotorShield.h"

MS_DCMotor motorA(MOTOR_A);
MS_DCMotor motorB(MOTOR_B);

int MOTOR_SPEED = 0;
String readString = "";

int IR1 = A3;
int IR2 = A2;
int ir_val_1 = 0;
int ir_val_2 = 0;

int writeValues = 0;

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

  if (ir_val_1 < 900)
  {
    //Serial.println("IR Sensor 1 Detection!: " + String(ir_val_1));
  }
  if (ir_val_2 < 900)
  {
    Serial.println("IR Changes: " + String(counts++));
    //Serial.println("IR Sensor 2 Detection!: " + String(ir_val_1));
  }

  writeValues++;

  if (writeValues >= 500)
  {
    //Serial.println("Current Motor Speed: " + String(MOTOR_SPEED));
    //Serial.println("IR Sensor 1: " + String(ir_val_1));
    //Serial.println("IR Sensor 2: " + String(ir_val_2) + '\n');
    writeValues = 0;
  }
}

// helper function to print the motor's states in human-readable strings.
String decodeState(int state)
{
  String result = "";
  switch (state) {
    case FORWARD:
      result = "Forward";
      break;
    case BACKWARD:
      result = "Backward";
      break;
    case BRAKE:
     result = "Brake";
     break;
   case RELEASE:
     result = "Release";
     break;
   }
  return result;
}
