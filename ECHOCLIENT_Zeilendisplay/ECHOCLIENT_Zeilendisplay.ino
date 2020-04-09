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
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const char* ssid = "UPC8476216";
const char* password = "zQY5rrpr2dwx";
WiFiServer wifiServer(80);

char Empfang[20];
int count = 0;
void setup(void)
{ 
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0,0); 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    lcd.print("Connecting to WiFi..");
  }
   lcd.setCursor(0,0); 
   lcd.print("Connected to WiFi   ");
   lcd.setCursor(0,1);
   lcd.print(WiFi.localIP());
  
  wifiServer.begin();
}

void loop(void)
{
  WiFiClient client = wifiServer.available();
 
  if (client) {
    lcd.setCursor(0,2);
    lcd.print("Client connected   ");
    lcd.setCursor(0,3);
    
    
    while (client.connected()) {
      count=0;
      while (client.available()>0) 
      {
        char c = client.read();
        //client.write(c);
        
        if(c == '.')
        {
          int j = 0;
          while (j != count)
          {
            lcd.print(Empfang[j++]);
          }
        }
        else  Empfang[count++] = c;
      }
 
      //delay(10);
    }
    lcd.print(Empfang);
    client.stop();
    lcd.setCursor(0,2);
    lcd.print("Client disconnected");
 
  }
       //Serial.println("Blabla");  
}
