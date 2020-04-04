/*
  ESP32 mDNS responder sample

  This is an example of an HTTP server that is accessible
  via http://esp32.local URL thanks to mDNS responder.

  Instructions:
  - Update WiFi SSID and password as necessary.
  - Flash the sketch to the ESP32 board
  - Install host software:
    - For Linux, install Avahi (http://avahi.org/).
    - For Windows, install Bonjour (http://www.apple.com/support/bonjour/).
    - For Mac OSX and iOS support is built in through Bonjour already.
  - Point your browser to http://esp32.local, you should see a response.

*/
#include <WiFi.h>
const char* ssid = "UPC8476216";
const char* password = "zQY5rrpr2dwx";
WiFiServer wifiServer(80);

void setup(void)
{ 
   Serial.begin(115200);
   Serial.println("Blabla");
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
   }
     Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
}

void loop(void)
{
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        client.write(c);
        Serial.println(c);
      }
 
      //delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }
       //Serial.println("Blabla");  
}
