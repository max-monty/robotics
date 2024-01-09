// TODO: fix 6th LED
// Combines all projects up through scrolling

const int fadeLED = 9;
int brightness = 0;
int fadeAmount = 5;

const int buttonPin = 2; 
const int ledPin = 13; 
int currentState; 
int lastState = HIGH; 
int ledState = LOW;

unsigned long prevBlinkMillis = 0;
unsigned long prevFadeMillis = 0;
unsigned long prevStringLightsMillis = 0;
const int fadeInterval = 30; 
int sensorPin = A0;  
int sensorValue = 0;

const int startPin = 3;
const int endPin = 8;
int currentPin = startPin;
bool forward = true;

int timer = 100;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(fadeLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  for (int thisPin = startPin; thisPin <= endPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  handleButtonPress();
  blinkLED();
  fadeLEDFunction();
  sequenceLights();
}

void handleButtonPress() {
  currentState = digitalRead(buttonPin);
  if (lastState == HIGH && currentState == LOW) {
    ledState = !ledState;
  }
  lastState = currentState;
  delay(50);
}

void blinkLED() {
  if (ledState == HIGH) {
    unsigned long currentMillis = millis();
    sensorValue = analogRead(sensorPin);
    if (currentMillis - prevBlinkMillis >= sensorValue) {
      if (digitalRead(ledPin) == LOW) {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
      prevBlinkMillis = currentMillis;
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void fadeLEDFunction() {
  unsigned long currentMillis = millis();
  if (currentMillis - prevFadeMillis >= fadeInterval) {
    analogWrite(fadeLED, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    prevFadeMillis = currentMillis;
  }
}

void sequenceLights() {
  unsigned long currentMillis = millis();
  if (currentMillis - prevStringLightsMillis >= timer) {
    digitalWrite(currentPin, LOW);
    if (forward) {
      currentPin++;
      if (currentPin > endPin) {
        forward = false;
        currentPin = endPin;
      }
    } else {
      currentPin--;
      if (currentPin < startPin) {
        forward = true;
        currentPin = startPin;
      }
    }
    digitalWrite(currentPin, HIGH);
    prevStringLightsMillis = currentMillis;
  }
}
