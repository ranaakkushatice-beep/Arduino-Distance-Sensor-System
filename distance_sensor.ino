// Pin tanımlamaları
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Bilgisayara veri göndermek için
}

void loop() {
  long duration, distance;
  
  // Sensörü tetikleme
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Ses dalgasının gidiş-dönüş süresini ölçme
  duration = pulseIn(echoPin, HIGH);
  
  // Mesafeyi cm cinsinden hesaplama
  distance = duration * 0.034 / 2;
  
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Eğer mesafe 10cm'den küçükse LED'i yak
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(500);
}