#include "MotorControls.hpp"
void setPins(uint8_t val){
    shiftOut(SER, CLK, LSBFIRST, val);
    digitalWrite(LATCH,HIGH);
    delay(1);
    digitalWrite(LATCH,LOW);
}

void Motion(int motor,bool inversion,uint8_t pwm){
  if(motor==1){
    
  }
  else if(motor==2){

  }
  else{
    Serial.print("Bad input - motor")
  }
}