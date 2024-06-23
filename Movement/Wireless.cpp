#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Wireless.hpp"
#include "MotorControls.hpp"

#ifndef STASSID
#define STASSID "Airtel_geor_5270"
#define STAPSK "air38530"
#endif

extern int startingTorque;
unsigned int localPort = 8888;  // local port to listen on
IPAddress subnet(255,255,255,0);
IPAddress localIp(192,168,1,10);
IPAddress gateway(192,168,1,0);
// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1];  // buffer to hold incoming packet,
//char ReplyBuffer[] = "acknowledged\r\n";        // a string to send back

WiFiUDP Udp;

void wirelessSetup() {
  WiFi.mode(WIFI_STA);
  WiFi.config(localIp,gateway,subnet);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);
}

void wirelessLoop() {
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.printf("Received packet of size %d from %s:%d\n    (to %s:%d, free heap = %d B)\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort(), Udp.destinationIP().toString().c_str(), Udp.localPort(), ESP.getFreeHeap());
    uint8_t motorNo,inversion,pwm;
    // read the packet into packetBufffer
    Udp.read((char*)&motorNo,1);
    Udp.read((char*)&inversion,1);
    Udp.read((char*)&pwm,1);
    if(motorNo==0){
      startingTorque=pwm;
    }
    else{
      Serial.println("Contents:");
      Serial.println(motorNo,DEC);
      Serial.println(inversion,DEC);
      Serial.println(pwm,DEC);
      Motion(motorNo,inversion,pwm);
    }

  }
}