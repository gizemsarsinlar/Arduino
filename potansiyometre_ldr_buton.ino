int led1 = 5;
int led2 = 4; 
int pot = A0; 
int potdeger; 
int button = 9;
int buttonvalue;
int ldr=A1;
int ldrvalue;
int c1;
int previous = LOW;
long time = 0;      
long debounce = 200;
int state = HIGH;

void setup() {
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(button,INPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
 }

void loop() {
  
  buttonvalue = digitalRead(button);
  
   if (buttonvalue == HIGH && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
    time = millis();    
   }
   Serial.println(state);
   
  if(state==HIGH){
    potdeger = analogRead(pot);
  

    if(potdeger > 250 && potdeger < 500){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
   }
    else if(potdeger > 501 && potdeger < 1000){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
   }
    else if(potdeger > 1001){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
   }
  }

  else {
    ldrvalue = analogRead(ldr);
     if(ldrvalue > 300){
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
     }
      else{
        digitalWrite(led1,HIGH);
        digitalWrite(led2, LOW);
     }    
  }
}
