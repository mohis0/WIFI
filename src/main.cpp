#include <Arduino.h>
#include <ESP8266WiFi.h>
String SSID;
String PASS;
void smartWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.beginSmartConfig();
  Serial.println();
  Serial.print("starting smart configuration");
  while (1)
  {
    delay(500);
    Serial.print(".");
    if(WiFi.smartConfigDone())
    {
      Serial.print("smart config done");
      Serial.println();
      Serial.println("trying to connect to :");
      Serial.print(WiFi.SSID());
      break;
    }
  }
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  SSID = WiFi.SSID();
  PASS = WiFi.psk();
  return ;
}
void wifiConnect()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID.c_str(), PASS.c_str()); //start connecting to wifi
  Serial.println();
  Serial.print("connecting to wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("connected successfuly");
  return;
}
void WifiInfo()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println();
    Serial.println("connection is valid");
    Serial.print("IP : ");
    Serial.println(WiFi.localIP());
    Serial.print("SSID : ");
    Serial.println(SSID);
  }
  return;
}
void setup() {
  smartWiFi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED)
    wifiConnect();
}