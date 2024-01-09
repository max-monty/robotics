int switch_pin = 3;
int led_pin = 12;
//int led_pin2 = 13;
byte leds = 0;

void setup() {
  pinMode(switch_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}
//To add another LED, copy the code and edit for pin
void loop() {
  if(digitalRead(switch_pin) == HIGH){
    digitalWrite(led_pin, LOW);
  }
  if(digitalRead(switch_pin) == LOW){
    digitalWrite(led_pin, HIGH);
  }
}