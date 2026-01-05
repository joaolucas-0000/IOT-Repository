// OBS: Lista de materiais e link do projeto no final do código foram perdidos.


#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

int op;
int ledVerde = 6;
int ledBranco=7;

void setup()
{
  pinMode(ledBranco,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Acender: V ou A");
  //Serial.write("acender: v ou a");
  lcd.setCursor(0,1);
  //lcd.print("Apagar: v ou a");
  //Serial.write("Acender v ou a");
  delay(5000);
  lcd.clear();
}

void loop()
{
  
  if (Serial.available())
  {
  op = Serial.read();
    if (op=86)
    {
     digitalWrite(ledVerde, HIGH);
     lcd.setCursor(0,0);
     lcd.print("led verde aceso");
    }
    if (op==118)
    {
     digitalWrite(ledVerde,LOW);
     lcd.setCursor(0,0);
     lcd.print("led apagado");
    }
    if(op==65)
    {
     digitalWrite(ledBranco,HIGH);
     lcd.setCursor(0,1);
     lcd.print("led azul acendeu");
    }
    if (op==97) {
     digitalWrite(ledBranco, LOW);
     lcd.setCursor(0,1);
     lcd.print("Led azul apagado");
    }
  }
}
