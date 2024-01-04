#include "pitches.h"

int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Assertive Error Notification
  assertiveErrorNotification();

  delay(2000);  // Pause between patterns
}

void assertiveErrorNotification() {
  // Define musical notes for an assertive error notification
  int melody[] = {
    NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5
  };
  int noteDurations[] = {8, 8, 8, 4, 4, 4, 8, 8, 2};

  // Play the melody
  for (int i = 0; i < 255; i++) {
    int noteDuration = 2500 / noteDurations[i];
    tone(motorPin, melody[i], noteDuration);
    delay(noteDuration * 1.1);  // Add a slight pause between notes
    noTone(motorPin);  // Turn off the vibration motor
  }
}
