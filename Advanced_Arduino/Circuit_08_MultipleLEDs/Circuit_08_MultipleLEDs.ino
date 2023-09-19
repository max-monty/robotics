int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};   // Array to store the pin numbers of the 10 LEDs
int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); // Calculate the number of LEDs
int delayTime = 100;  // milliseconds to pause between LEDs


void setup()
{
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  /** Uncomment other functions as needed to try different LED displays **/
  //oneOnAtATime();
  // oneAfterAnother();  
  pingPong();
  // marquee();
  // randomLED();
}

void oneAfterAnother()
{
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}

void oneOnAtATime()
{  
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void pingPong()
{   
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void marquee()
{  
  for (int i = 0; i < numLeds / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + numLeds / 2], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[i + numLeds / 2], LOW);
  }
}

void randomLED()
{
  int randomIndex = random(numLeds);
  digitalWrite(ledPins[randomIndex], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[randomIndex], LOW);
}
