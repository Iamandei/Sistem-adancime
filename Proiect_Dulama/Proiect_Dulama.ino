//lcd
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//Marimi
float cm;
float m;
//proxy
int current;
int last;
int reset;

void setup() {
  //proxy
  pinMode(10,INPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);
  last= digitalRead(8);
  //lcd
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(7,0);
  lcd.print("LCD");
  lcd.setCursor(2,1);
  lcd.print("Se porneste");
  delay(500);
  lcd.clear();
}

void loop() {
  //proxy
  current = digitalRead(8);
  reset= digitalRead(10);
  delay(10);
  if(current != last){
 cm= cm + 4.908;
  }
  else{ }
  last=current;
  //reset
  if(reset == HIGH){
    cm=0;
    lcd.clear();
  }
  else{ }
  //conversie
  m= cm * 0.01;
  //afisaj
 lcd.setCursor(0,0);
 lcd.print("Val(CM):");
 lcd.setCursor(8,0);
 lcd.print(cm);
 lcd.setCursor(0,1);
 lcd.print("Val(M):");
 lcd.setCursor(7,1);
 lcd.print(m);
}
