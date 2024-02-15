int motorPin = 3;
int lastSpeed = 0;  // Initialize to 0 or whatever default speed you want

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for Serial connection to be established
  Serial.println("Speed0to255");
}

void loop() {
  if (Serial.available()) {
    int incoming = Serial.peek();              // Peek at the next byte in the buffer
    if (incoming >= '0' && incoming <= '9') {  // Check if it's a digit
      int speed = Serial.parseInt();           // Read and parse the integer
      if (speed >= 0 && speed <= 255) {
        lastSpeed = speed;  // Update last valid speed if within range
      }
    } else {
      Serial.read();  // Remove the non-digit from the buffer
    }
  }
  analogWrite(motorPin, lastSpeed);  // Use the last valid speed
}
