#define echo D2
#define trig D3

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  int echoVal=0;
  uint32_t startT,stopT;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  while(!echoVal){
    echoVal=digitalRead(echo);
    if(echoVal){
      startT=micros();
    }
    if((micros()%1000==0)&&((micros()-startT)>200000)){
      Serial.println("Failed Read");
      echoVal=0;
      break;
    }
  }
  while(echoVal){
    echoVal=digitalRead(echo);
    if(!echoVal){
      stopT=micros();
    }
  }
  //Serial.println(stopT-startT);
  Serial.println((stopT-startT)/58);
}
