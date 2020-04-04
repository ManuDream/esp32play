#include <STEMMA_LiquidCrystal.h>

STEMMA_LiquidCrystal lcd;

void setup() {
  // put your setup code here, to run once:
    lcd.begin(16, 2);
    //lcd.cursor();
    //delay(2000);
    //lcd.noCursor();
    //delay(2000);
    //lcd.cursor();
    while(1){
    lcd.print("1234");
    delay(2000);
    lcd.print("5678");
    delay(2000);
    lcd.print("9112");
    delay(2000);
    lcd.print("9112");
    delay(2000);
    }
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
