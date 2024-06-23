#include "MotorControls.hpp"
#include "Wireless.hpp"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(230400);
  Serial.println("Entering Loop");
  pinMode(SER,OUTPUT);
  pinMode(ENABLE,OUTPUT);
  pinMode(PWM_M1,OUTPUT);
  pinMode(PWM_M2,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  digitalWrite(CLK,LOW);
  digitalWrite(SER,LOW);
  digitalWrite(ENABLE,LOW);
  digitalWrite(LATCH,LOW);
  analogWrite(PWM_M1,0);
  analogWrite(PWM_M2,0);
  Serial.setTimeout(1);
  wirelessSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  wirelessLoop();
  // if(Serial.available()){
  //     uint8_t motor=Serial.parseInt();
  //     int val=Serial.parseInt();
  //     uint8_t pwm=Serial.parseInt();
  //     Motion(motor,val,pwm);
  // }
}
