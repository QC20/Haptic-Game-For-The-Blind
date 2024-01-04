#include "pitches.h"

int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Pattern xx: Musical Error Notification
  musicalErrorNotification();

  delay(2000);  // Pause between patterns
}

void musicalErrorNotification() {
  // Define musical notes
  int melody[] = {NOTE_A5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_F5};
  int noteDurations[] = {4, 8, 8, 4, 4, 8, 8, 2};

  // Play the melody
  for (int i = 0; i < 8; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(motorPin, melody[i], noteDuration);
    delay(noteDuration * 1.3);  // Add a slight pause between notes
    noTone(motorPin);  // Turn off the vibration motor
  }
}
