#ifndef MOTORCONTROLS_HPP_INCLUDED
#define MOTORCONTROLS_HPP
#include<Arduino.h>
#define SER D0
#define CLK D1
#define PWM_M1 D2
#define PWM_M2 D5
#define ENABLE D3
#define LATCH D4                        
void setPins(uint8_t);
void Motion(int,bool,uint8_t);
#endif