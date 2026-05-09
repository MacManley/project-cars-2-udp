//File: testPC2.ino

//#include "Wifi.h" // ESP32 WiFi include
#include <ESP8266WiFi.h> // ESP8266 WiFi include
#include <PCars2_UDP.h>

const char *SSID = "Your Wifi SSID";
const char *Password = "Your Wifi Password";

void startWiFi();

PCars2_Parser parser;

void setup() 
{ 
  Serial.begin(115200);
  startWiFi();
  parser.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{     
  parser.read();
  float speed = (parser.packetTelemetryData()->sTelemetryData().sSpeed) * 3.6;  
  Serial.println(speed);
}

void startWiFi()
{
