#include "pitches.h"

const int speakerPin = 10;

const int rows = 4; // Four rows
const int cols = 4; // Four columns

// Define the row and column pin numbers
int rowPins[rows] = {5, 4, 3, 2};
int colPins[cols] = {6, 7, 8, 9};

// Define melodies (simplified and inspired by various Taylor Swift song styles)
// Each melody array represents a different song style
int melodies[16][8] = {
  // Button 1: Inspired by "Love Story"
  {NOTE_C4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_G4, NOTE_F4},
  // Button 2: Inspired by "You Belong With Me"
  {NOTE_E4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_E4, NOTE_B4, NOTE_A4},
  // Button 3: Inspired by "Shake It Off"
  {NOTE_G4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_D4, NOTE_C4},
  // Button 4: Inspired by "Blank Space"
  {NOTE_A4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_E4, NOTE_D4},
  // Button 5: Inspired by "Wildest Dreams"
  {NOTE_D4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_A4, NOTE_G4},
  // Button 6: Inspired by "Bad Blood"
  {NOTE_C5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C5, NOTE_G4, NOTE_F4},
  // Button 7: Inspired by "22"
  {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_E5, NOTE_B4, NOTE_A4},
  // Button 8: Inspired by "I Knew You Were Trouble"
  {NOTE_G5, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G5, NOTE_D4, NOTE_C4},
  // Button 9: Inspired by "We Are Never Ever Getting Back Together"
  {NOTE_A5, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_A5, NOTE_E4, NOTE_D4},
  // Button 10: Inspired by "Style"
  {NOTE_D5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_A4, NOTE_G4},
  // Button 11: Inspired by "Delicate"
  {NOTE_C6, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C6, NOTE_G4, NOTE_F4},
  // Button 12: Inspired by "Look What You Made Me Do"
  {NOTE_E6, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_E6, NOTE_B4, NOTE_A4},
  // Button 13: Inspired by "End Game"
  {NOTE_G6, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G6, NOTE_D4, NOTE_C4},
  // Button 14: Inspired by "Lover"
  {NOTE_A6, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_A6, NOTE_E4, NOTE_D4},
  // Button 15: Inspired by "Me!"
  {NOTE_D6, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D6, NOTE_A4, NOTE_G4},
  // Button 16: Inspired by "Cardigan"
  {NOTE_C7, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_C7, NOTE_G4, NOTE_F4}
};

// Define durations for each note in the melodies
int durations[16][8] = {
  // Durations for "Love Story" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "You Belong With Me" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Shake It Off" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Blank Space" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Wildest Dreams" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Bad Blood" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "22" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "I Knew You Were Trouble" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "We Are Never Ever Getting Back Together" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Style" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Delicate" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Look What You Made Me Do" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "End Game" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Lover" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Me!" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8},
  // Durations for "Cardigan" inspired melody
  {8, 8, 8, 8, 8, 8, 8, 8}
};


void setup() {
  // Initialize row pins as outputs
  for (int i = 0; i < rows; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  
  // Initialize column pins as inputs
  for (int i = 0; i < cols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int row = 0; row < rows; row++) {
    digitalWrite(rowPins[row], LOW);
    
    for (int col = 0; col < cols; col++) {
      if (digitalRead(colPins[col]) == LOW) {
        // Calculate the index for the melody based on the row and column
        int melodyIndex = row * cols + col;
        
        // Play the melody for the button
        // Change the condition to allow all buttons to work
        if (melodyIndex < 16) {
          playMelody(melodyIndex);
          // Add a delay after playing the melody to avoid bouncing and rapid re-triggering
          delay(300); 
        }
      }
    }
    
    digitalWrite(rowPins[row], HIGH);
  }
}

void playMelody(int melodyIndex) {
  // Ensure the melody plays for the entire length
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / durations[melodyIndex][thisNote];
    tone(speakerPin, melodies[melodyIndex][thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerPin);
  }
}
