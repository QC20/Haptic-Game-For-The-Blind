int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Pattern 1: Short Burst
  hapticFeedback();

  delay(1000);  // Pause between patterns

  // Pattern 2: Double Burst
  doubleBurst();

  delay(1000);  // Pause between patterns

  // Pattern 3: Alternating Burst
  alternatingBurst();

  delay(1000);  // Pause between patterns

  // Pattern 4: Quick Pulsation
  quickPulsation();

  delay(1000);  // Pause between patterns

  // Pattern 5: Randomized Burst
  randomizedBurst();

  delay(1000);  // Pause between patterns

    // Pattern 1: Long Burst
  longBurst();

  delay(1000);  // Pause between patterns

  // Pattern 2: Double Long Burst
  doubleLongBurst();

  delay(1000);  // Pause between patterns

  // Pattern 3: Quick Triple Burst (good)
  quickTripleBurst();

  delay(1000);  // Pause between patterns

  // Pattern 4: Short Pulsation
  shortPulsation();

  delay(1000);  // Pause between patterns

  // Pattern 5: Intense Pulsation
  intensePulsation();

  delay(1000);  // Pause between patterns

    // Pattern 1: Strong Pulsation
  strongPulsation();

  delay(1000);  // Pause between patterns

  // Pattern 2: Sharp Bursts
  sharpBursts();

  delay(1000);  // Pause between patterns

  // Pattern 3: Forceful Triple Burst
  forcefulTripleBurst();

  delay(1000);  // Pause between patterns

  // Pattern 4: Solid Thumps (very good)
  solidThumps();

  delay(1000);  // Pause between patterns

  // Pattern 5: Vigorous Alternation (good and firm)
  vigorousAlternation();

  delay(1000);  // Pause between patterns
}

}

void hapticFeedback() {
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(100);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(150);  // Pause between bursts
  }
}

void doubleBurst() {
  for (int i = 0; i < 2; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(100);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(150);  // Pause between bursts
  }
}

void alternatingBurst() {
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(100);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(150);  // Pause between bursts
  }
}

void quickPulsation() {
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(50);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(100);  // Pause between bursts
  }
}

void randomizedBurst() {
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, random(150, 255));  // Random intensity
    delay(random(50, 200));  // Random burst duration
    analogWrite(motorPin, 0);  // Turn off
    delay(random(100, 500));  // Random pause
  }
}

void longBurst() {
  analogWrite(motorPin, 255);  // Maximum intensity
  delay(500);  // Burst duration
  analogWrite(motorPin, 0);    // Turn off
  delay(500);  // Pause between bursts
}

void doubleLongBurst() {
  for (int i = 0; i < 2; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(500);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(500);  // Pause between bursts
  }
}

void quickTripleBurst() {
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(150);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(300);  // Pause between bursts
  }
}

void shortPulsation() {
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(50);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(100);  // Pause between bursts
  }
}

void intensePulsation() {
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(30);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(50);  // Pause between bursts
  }
}
void strongPulsation() {
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(100);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(150);  // Pause between bursts
  }
}

void sharpBursts() {
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(50);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(200);  // Pause between bursts
  }
}

void forcefulTripleBurst() {
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(150);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(250);  // Pause between bursts
  }
}

void solidThumps() {
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(200);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(300);  // Pause between bursts
  }
}

void vigorousAlternation() {
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(100);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(100);  // Pause between bursts
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(100);  // Burst duration
    analogWrite(motorPin, 0);    // Turn off
    delay(300);  // Pause between bursts
  }
}
