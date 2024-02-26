//File: testPC2.ino

//#include "Wifi.h" // ESP32 WiFi include
#include <ESP8266WiFi.h> // ESP8266 WiFi include
#include <WiFiUdp.h>
#include <PCars2_UDP.h>

const char *SSID = "Your Wifi SSID";
const char *Password = "Your Wifi Password";

void startWiFi();
 
//The IP address that this ESP32 / ESP8266 has requested to be assigned to.
IPAddress ip();
WiFiUDP Udp;

unsigned int localPort = 5606; // Port that is used in game, default is 20777

PCars2_Parser* parser;

void setup() 
{ 
  parser = new PCars2_Parser();
  Serial.begin(115200);
  startWiFi();
  Udp.begin(localPort);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int packetSize = Udp.parsePacket(); 
  
    if(packetSize) 
    {
       char packetBuffer[packetSize];
       while(Udp.available())
       {
        Udp.read(packetBuffer, packetSize);
       }
       parser->push(packetBuffer);
      
      unsigned short localParticipantIndex = parser->packetTimingsData()->sLocalParticipantIndex();
      float speed = (parser->packetTelemetryData()->sTelemetryData().sSpeed) * 3.6;  
      Serial.println(speed);
      delay(15);
  }
}
void startWiFi()
{
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, Password);
  Serial.print("Attempting to connect to "); 
  Serial.println(SSID);
 
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(250);
 
    if ((++i % 16) == 0)
    {
      Serial.println(F(" still trying to connect"));
    }
  }
 
  Serial.print(F("Connection Successful | IP Address: "));
  Serial.println(WiFi.localIP());
}