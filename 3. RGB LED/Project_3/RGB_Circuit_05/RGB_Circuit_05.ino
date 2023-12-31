int sensorPin = A0; 
int sensorValue = 0; 
int red = 11; 
int green = 10;
int blue = 9;

unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT); 
  pinMode(blue,OUTPUT);
  Serial.begin(9600);
}

void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void ShowBatteryPercentage() {
  PercentFull = (double)batteryLevel / batteryCapacity * 100;
  Serial.print(PercentFull);
  Serial.println("%");
  
  if (PercentFull > 0 && PercentFull <= 25) {
    RGB_color(125, 0, 0); // red
  } else if (PercentFull > 25 && PercentFull <= 50) {
    RGB_color(125, 80, 0); // yellow-ish
  } else if (PercentFull > 50 && PercentFull <= 75) {
    RGB_color(0, 125, 125); // blue-ish
  } else if (PercentFull > 75 && PercentFull < 100) {
    RGB_color(125, 125, 125); // white
  }
}

void loop() { 
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue; 
  ticks += wait;

  if (batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms     ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
    ticks = 0;
    RGB_color(0, 125, 0); // Green for charging complete 
    delay(30000); // long pause
  } else {
    ShowBatteryPercentage();
  }
  delay(wait);
}