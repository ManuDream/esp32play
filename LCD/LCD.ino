#include <LiquidCrystal.h>

LiquidCrystal lcd(22,21,5,18,23,19);

void setup() {
  // put your setup code here, to run once:
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("How to Interface");

    // go to row 1 column 0, note that this is indexed at 0
    lcd.setCursor(0,1); 
    lcd.print ("Kaesebrot       ");
    lcd.setCursor(17,1); 
    lcd.print ("fuer Fluffy     ");
}

void loop() {
  // put your main code here, to run repeatedly:

}
