#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define ANALOG_LDR_PIN A0
#define DIGITAL_LDR_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(ANALOG_LDR_PIN, INPUT);
  pinMode(DIGITAL_LDR_PIN, INPUT);
}

void loop()
{
  int digitalValue = digitalRead(DIGITAL_LDR_PIN);
  int analogValue = analogRead(ANALOG_LDR_PIN);

  int percentage = map(analogValue, 0, 1023, 0, 100);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light State: ");
  lcd.print(digitalValue == LOW ? "On" : "Off");
  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(100 - percentage);
  lcd.print(" %");

  delay(1000);
}
