#include <Servo.h>

char buffer[11];
Servo servo1;  // Create a servo object for the first servo
Servo servo2;  // Create a servo object for the second servo

void setup() {
  servo1.attach(5);  // Attaches the servo on pin 5 to the servo1 object
  servo2.attach(6);  // Attaches the servo on pin 6 to the servo2 object
  Serial.begin(9600);
  // Clear any existing data from serial buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  servo1.write(90);  // Put servo1 at home position
  servo2.write(90);  // Put servo2 at home position
  Serial.println("STARTING...");
}

void loop() {
  if (Serial.available() > 0) {
    delay(100);  // Let the buffer fill up
    int index = 0;
    while (Serial.available() > 0 && index < 10) {
      buffer[index++] = Serial.read();  // Fill the buffer with the string
    }
    buffer[index] = '\0';  // Properly terminate the string
    splitString(buffer);  // Run splitString function
    // Clear the buffer for the next command
    memset(buffer, 0, sizeof(buffer));
  }
}

void splitString(char* data) {
  Serial.print("Data entered: ");
  Serial.println(data);
  
  char* parameter = strtok(data, " ,");  // Split string into tokens
  while (parameter != NULL) {
    setServo(parameter);  // Run the setServo function for each parameter
    parameter = strtok(NULL, " ,");
  }
}

void setServo(char* data) {
  if ((data[0] == 'L') || (data[0] == 'l')) {
    int firstVal = strtol(data + 1, NULL, 10);  // Convert string to long integer
    firstVal = constrain(firstVal, 0, 180);  // Constrain values to valid range for servo
    servo1.write(firstVal);
    Serial.print("Servo1 is set to: ");
    Serial.println(firstVal);
  } else if ((data[0] == 'R') || (data[0] == 'r')) {
    int secondVal = strtol(data + 1, NULL, 10);  // Convert string to long integer
    secondVal = constrain(secondVal, 0, 180);  // Corrected to constrain to 180 instead of 255
    servo2.write(secondVal);
    Serial.print("Servo2 is set to: ");
    Serial.println(secondVal);
  }
}
