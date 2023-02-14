#include <SoftwareSerial.h>

/* Activer une communication série sur les lignes 11  et 10 
 * pin 11 arduino -> TX of HC05
 * pin 10 arduino -> RX of HC05 
 */
SoftwareSerial HC06(11,10); // 11 is RX arduino and 10 is TX arduino
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);


String messageRecu="";

void setup() {
  Serial.begin(9600);
  HC06.begin(9600);  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("STARTING...");
  delay(1000);
  lcd.clear();
  
}
 
void loop()
{
    while(HC06.available())
    {
      delay(3);
      char c = HC06.read();
      messageRecu += c;

      
    }
    if (messageRecu.length() >0)
    {
      Serial.println(messageRecu);

      lcd.clear();
      
      lcd.setCursor(3,0);
      lcd.print("RECEIVED DATA");
      lcd.setCursor(3,1);
      lcd.print(messageRecu);
      Serial.println(messageRecu);
     
      
    }
     messageRecu="";

    
}
