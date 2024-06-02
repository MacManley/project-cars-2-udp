//File: testPC2.ino

//#include "Wifi.h" // ESP32 WiFi include
#include <ESP8266WiFi.h> // ESP8266 WiFi include
#include <PCars2_UDP.h>

const char *SSID = "Your Wifi SSID";
const char *Password = "Your Wifi Password";

void startWiFi();

PCars2_Parser* parser;

void setup() 
{ 
  parser = new PCars2_Parser();
  Serial.begin(115200);
  startWiFi();
  parser->begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{     
  parser->read();
  float speed = (parser->packetTelemetryData()->sTelemetryData().sSpeed) * 3.6;  
  Serial.println(speed);
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