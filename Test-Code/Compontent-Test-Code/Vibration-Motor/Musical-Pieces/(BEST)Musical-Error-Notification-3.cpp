#include "pitches.h"

int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Pattern: Assertive Error Notification
  assertiveErrorNotification();

  delay(2000);  // Pause between patterns
}

void assertiveErrorNotification() {
  // Define musical notes for an assertive error sound
  int melody[] = {
    NOTE_A6, NOTE_A6, NOTE_A6, NOTE_G6, NOTE_G6, NOTE_G6,
    NOTE_F6, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6
  };
  int noteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

  // Play the melody
  for (int i = 0; i < 12; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(motorPin, melody[i], noteDuration);
    delay(noteDuration * 1.1);  // Add a slight pause between notes
    noTone(motorPin);  // Turn off the vibration motor
  }
}
