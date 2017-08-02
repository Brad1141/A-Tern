
//Libraries needed
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"


int pin10 = 10;//pins for RC_ControllerInput
int pin11 = 11;

int rpm1 = 0;//rpm = rotations per seconds
int rpm2 = 0;
int rpm3 = 0;
int rpm4 = 0;

Adafruit_MotorSheild AFMS = Adafruit_MotorSheild();//created a new motor sheild object 
  
  //Make MotorPorts for all 4 motors
  Adafruit_DCMotor myMotor1 = AFMS.getMotor(1);
  Adafruit_DCMotor myMotor2 = AFMS.getMotor(2);
  Adafruit_DCMotor myMotor3 = AFMS.getMotor(3);
  Adafruit_DCMotor myMotor4 = AFMS.getMotor(4);

void setup() {
  
  //establish pins as inputs
  pinMode(pin10, INPUT);
  pinMode(pin11, INPUT);
  
  
  //Start Speed can be anywhere from 0 - 255
  myMotor1->setSpeed(rpm1);
  myMotor1->run(BACKWARD); //counter-clockwise rotation 
  // turn on motor
  myMotor1->run(RELEASE);
  
  myMotor2->setSpeed(rpm2);
  myMotor2->run(FORWARD); //clock-wise rotation
  // turn on motor
  myMotor2->run(RELEASE);
  
  myMotor3->setSpeed(rpm3);
  myMotor3->run(BACKWARD); //counter-clockwise rotation 
  // turn on motor
  myMotor3->run(RELEASE);
  
  myMotor4->setSpeed(rpm4);
  myMotor4->run(FORWARD); //clock-wise rotation
  // turn on motor
  myMotor4->run(RELEASE);
}

void loop() {
    int speedValue = pulseIn(pin10, HIGH);
    int directionValue = pulseIn(pin11, HIGH);
    
    
    if(/*Range for UP motion*/) //UP 
    {
      rpm1 += 5;
      rpm2 += 5;
      rpm3 += 5;
      rpm4 += 5;
    }
    
    if(/*Range for DOWN motion*/) //DOWN 
    {
      rpm1 -= 5;
      rpm2 -= 5;
      rpm3 -= 5;
      rpm4 -= 5;
    }
    
    if(/*Range for LEFT motion*/) //LEFT 
    {
      rpm1 += 5;
      rpm2 -= 5;
      rpm3 -= 5;
      rpm4 += 5;
    }
    
    if(/*Range for RIGHT motion*/) //RIGHT 
    {
      rpm1 -= 5;
      rpm2 += 5;
      rpm3 += 5;
      rpm4 -= 5;
    }
    
    if(/*Range for FORWARD motion*/) //FOWARD 
    {
      rpm1 -= 5;
      rpm2 -= 5;
      rpm3 += 5;
      rpm4 += 5;
    }
    
    if(/*Range for DOWN motion*/) //BACKWARDS 
    {
      rpm1 += 5;
      rpm2 += 5;
      rpm3 += 5;
      rpm4 += 5;
    }
    
    analogWrite(myMotor1, rpm1);
    analogWrite(myMotor2, rpm2);
    analogWrite(myMotor3, rpm3);
    analogWrite(myMotor4, rpm4);
    
    delay(1);
}







