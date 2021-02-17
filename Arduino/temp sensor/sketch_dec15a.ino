#include <LiquidCrystal.h>         

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = 0; 
const int buzzer=9;// A0 is where you connect the sensor
void setup()
{
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);
}
void loop()
{
  int value = analogRead(inPin); // read the value from the sensor
  lcd.setCursor(0,1);
  float millivolts = (value / 1024.0) * 5; 
  float celsius = (millivolts-0.5)*100;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print((celsius * 9)/5 + 32); //turning the celsius into fahrehait
  lcd.print("F");
  delay(1000);
  if(celsius>28.0){tone(buzzer,1000);delay(1000);noTone(buzzer);
  delay(1000);}
}
