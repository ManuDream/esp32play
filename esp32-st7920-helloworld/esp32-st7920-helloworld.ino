
#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, 18, 19, 21, 22);       //Enable, RW, RS, RESET esp32 


//Icons für wifi und bluetooth
static unsigned char bluetooth_bits[] = {
   0x10, 0x32, 0x54, 0x38, 0x38, 0x54, 0x32, 0x10 };

static unsigned char wifi_bits[] = {
   0x7e, 0x81, 0x3c, 0x42, 0x18, 0x00, 0x18, 0x18 };




/*******************************************************************
 *                       SETUP
 *****************************************************************/

void setup(void) {
  
  u8g2.begin();  //starte bildschirm
  
}


void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_6x12_tr);  //schriftart setzen
    u8g2.drawStr(0,24,"Wurstbrot");  //schreibe hello world auf x0 y24
    u8g2.drawXBM(10, 0, 8, 8, wifi_bits); //Zeichne definiertes Bild in 8x8 auf x10y0
    u8g2.drawRFrame(20,15,30,22,7);
    u8g2.drawBox(124,60,4,4);
    u8g2.drawFrame(5,5,110,40);
    u8g2.drawCircle(64, 32, 30, U8G2_DRAW_ALL);
  } while ( u8g2.nextPage() );
  //delay(1000);
}
