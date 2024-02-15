#include<Servo.h>
int tonePin = 4;
int trigPin = 10;
int echoPin = 9;
int clockPin = 11;
int latchPin = 12;
int dataPin = 13;
Servo servo;
byte possible_patterns[9] = { B00000000, B00000001,
  B00000011,
  B00000111,
  B00001111, B00011111, B00111111, B01111111, B11111111,
};
int proximity = 0;
int duration;
int distance;

void setup() {
  // Serial Port
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(tonePin, OUTPUT);
  servo.attach(6);
}

void loop() {
  digitalWrite(latchPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance > 45 || distance < 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  proximity = map(distance, 0, 54, 8, 0);
  // Serial.println(proximity);
  servo.write(proximity*20);


  if (proximity < 0) {
    proximity = 0;
  } else if (proximity >= 3 && proximity < 4) {
    tone(tonePin, 2000, 200);
  }else if (proximity >= 5 && proximity <= 6) {
    tone(tonePin, 500, 200);
  } else if (proximity >= 7 && proximity <= 8) {
    tone(tonePin, 1000, 200);
  }

  shiftOut(dataPin, clockPin, MSBFIRST, possible_patterns[proximity]);
  digitalWrite(latchPin, HIGH);
  delay(600);
  noTone(tonePin);
}
