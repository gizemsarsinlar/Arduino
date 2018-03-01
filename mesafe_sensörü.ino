int trigPin = 8;
int echoPin = 7;
long sure;
long uzaklik;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  uzaklik = (sure / 2) / 29.1;

  if (uzaklik > 20 && uzaklik < 32 )
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(4, LOW);
  }
  else if (uzaklik > 31 && uzaklik < 42 )
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(4, LOW);
  }
  else if (uzaklik > 41)
  {
   digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(4, HIGH); 
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(4, LOW);
  }

  Serial.print("Uzaklik: ");
  Serial.print(uzaklik);
  Serial.println(" cm");
  delay(250);

}
