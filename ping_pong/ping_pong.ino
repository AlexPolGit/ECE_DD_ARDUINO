#include "MotorShield.h"
#include <SoftwareSerial.h>

MS_DCMotor motorA(MOTOR_A);
MS_DCMotor motorB(MOTOR_B);

const unsigned int BLUETOOTH_PIN = 10;

SoftwareSerial blueSerial(0, 1);

unsigned int MOTOR_SPEED = 0;
unsigned int MOTOR_RPM = 0;
String readString = "";

/*
unsigned int IR1 = A3;
unsigned int IR2 = A2;
unsigned int ir_val_1 = 0;
unsigned int ir_val_2 = 0;

const unsigned int SECOND = 1000;
unsigned long counts = 0;

unsigned long previousMillis = 0;
*/

int test = 0;

void setup()
{
  pinMode(BLUETOOTH_PIN, OUTPUT);
  digitalWrite(BLUETOOTH_PIN, HIGH);
  
  motorA.setSpeed(MOTOR_SPEED);
  motorB.setSpeed(MOTOR_SPEED);

  motorA.run(BACKWARD);
  motorB.run(FORWARD);

  blueSerial.begin(9600);

  blueSerial.
}

void loop()
{
  while (blueSerial.available() > 0)
  {
    char c = blueSerial.read();
    readString += c;
    delay(2);
  }
  
  if (readString.length() > 0)
  {
    blueSerial.println("Setting Speed to: " + readString);
    MOTOR_SPEED = readString.toInt();
    motorA.setSpeed(MOTOR_SPEED);
    motorB.setSpeed(MOTOR_SPEED);
    readString = "";
  }
/*
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
    //delay(1);
    //Serial.println("IR Sensor 2 Detection!: " + String(ir_val_1));
  }
  */
}

