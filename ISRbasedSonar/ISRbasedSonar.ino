#define echo D13
#define trig D3

int flipCnt = 0;
uint32_t startT;

uint32_t volatile distance=0;
IRAM_ATTR void timeChange(){
  flipCnt++;
  distance=micros()-distance; 
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(echo,INPUT_PULLUP);
pinMode(trig,OUTPUT);
attachInterrupt(digitalPinToInterrupt(echo), timeChange, CHANGE);
Serial.print("Interrupt Enabled on ");
Serial.print(D13);
Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  distance=0;
  flipCnt=0;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delay(600);
  if(flipCnt!=2){
    Serial.println("Error");
  }
  else{
    Serial.println(distance/58);
  }
}
