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

#include <LiquidCrystal.h>
LiquidCrystal lcd(22,21,5,18,23,19);
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>

const char* ssid = "UPC8476216";
const char* password = "zQY5rrpr2dwx";

// TCP server at port 80 will respond to HTTP requests
WiFiServer server(80);

void setup(void)
{ 
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,1); 
    lcd.print ("Kaesebrot       ");
    
 
    // Connect to WiFi network
    WiFi.begin(ssid, password);
    
    // Wait for connection
    lcd.setCursor(0,1); 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        
        //lcd.print (".");
    }
    //lcd.setCursor(0,1); 
    //lcd.print("Connected to ");
    //lcd.setCursor(0,2); 
    //lcd.println(WiFi.localIP());

}

void loop(void)
{
   
}
