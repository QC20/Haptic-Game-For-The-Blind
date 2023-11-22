// Says ba dum tisssch ba dum tisssch

#include "pitches.h"

int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Pattern: Quick and Harsh Error Notification
  quickHarshErrorNotification();

  delay(2000);  // Pause between patterns
}

void quickHarshErrorNotification() {
  // Define musical notes for a quick and harsh error sound
  int melody[] = {
    NOTE_A7, NOTE_G7, NOTE_F7, NOTE_F7
  };
  int noteDurations[] = {8, 8, 8, 8};

  // Play the melody
  for (int i = 0; i < 200; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(motorPin, melody[i], noteDuration);
    delay(noteDuration * 1.1);  // Add a slight pause between notes
    noTone(motorPin);  // Turn off the vibration motor
  }
}
