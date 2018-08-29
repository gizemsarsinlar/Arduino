#include <LiquidCrystal.h> 
LiquidCrystal LCD(11,10,9,2,3,4,5); 
  
void setup()
{
LCD.begin(16,2); 
}
  
void loop() {
int i; 
LCD.setCursor(3,0);
LCD.print("Gizem"); // İstediğinizi yazabilirsiniz. Tabi 16 karakter den küçük olmalı…
for(i=0; i<17; i++)
{
LCD.setCursor(i,1);
LCD.print("Sarsınlar"); // İstediğinizi yazabilirsiniz. Tabi 16 karakter den küçük olmalı…
delay(1000);
LCD.setCursor(i,1);
LCD.print(" ");
}
}
