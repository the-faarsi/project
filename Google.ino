#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"
#define server "io.adafruit.com"
#define port 1883
#define username "Dhamodharan"
#define key "a4ab2d4c62314244958a82948dc60ece"
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp, server, port, username, key);
Adafruit_MQTT_Subscribe feed = Adafruit_MQTT_Subscribe(&mqtt, username "/feeds/Dhamo1");
#define wifi "Dhamu"
#define password "Dhamu1234"
void setup()
{
  Serial.begin(9600);
  pinMode(16,OUTPUT);
  Serial.println(wifi);
  WiFi.begin(wifi, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println("Wifi Connected");
  Serial.println("IPADD:");
  Serial.println(WiFi.localIP());
  mqtt.subscribe(&feed);
  while (mqtt.connect())
  {
    Serial.println("..");
  }
  
  
  Serial.println("MQTT Basic");

}


void loop()
{
  while (mqtt.readSubscription(5000))
  {
    Serial.print("GOT ");
    Serial.print((char *)feed.lastread);
                  int a=atoi((char *)feed.lastread);
                  if(a==1)
                {
                  digitalWrite(16,LOW);
                }
                  else
                {
                  digitalWrite(16,HIGH);
                }
  }                
  }
