#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Enable = 9;

void setup()
{
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop()
{  
  int tempIn = analogRead(A0);
  float voltage = tempIn*(5.0/ 1024.0);
  float temp  = (voltage -0.5)*100;
  Serial.print(tempIn);
  Serial.println(" C");

  if (temp <= 25) 
  {
    lcd.setCursor(0, 0);
    analogWrite(10, LOW);
    analogWrite(13, LOW);
    lcd.print("Motor is off");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.setCursor(2, 1);
    lcd.print(" C");
    lcd.setCursor(4, 1);
    //lcd.print(" ");
    lcd.print(" Fan Speed:0%");
  }
  else if (50 >= temp && temp > 25) 
  {
    analogWrite(13, LOW);
    analogWrite(Enable, 63);
    analogWrite(10, 63);   
    lcd.setCursor(0, 0);
    lcd.print("Motor is on ");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.setCursor(4, 1);
    lcd.print("C");
    lcd.setCursor(3,1);
    lcd.print(" Fan Speed:25%");    
  }
  else if (100 >temp && temp >50){
    analogWrite(13, LOW);
    analogWrite(Enable, 127);
    analogWrite(10, 127);    
    lcd.setCursor(0, 0);
    lcd.print("Motor is on ");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.setCursor(2, 1);
    lcd.print("C");   
    lcd.setCursor(3,1);
    lcd.print(" FanSpeed:50%");
    
  }
  else {
    analogWrite(13, LOW);
    analogWrite(Enable, 255);
    analogWrite(10, 255);    
    lcd.setCursor(0, 0);
    lcd.print("Motor is on ");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.setCursor(3, 1);
    lcd.print("C");   
    lcd.setCursor(3,1);
    lcd.print(" FanSpeed:100%");    
    
  }
  delay(1000);
}
