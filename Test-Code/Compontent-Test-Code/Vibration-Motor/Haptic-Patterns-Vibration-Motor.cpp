/***********************
*
* Script for Vibration Motor and LED Patterns
*
* This script generates (23) various vibration motor patterns accompanied by visual feedback on the built-in LED.
* The flexibility of this script allows easy experimentation with different components like LEDs or other actuators.
*
* Instructions:
* 1. Connect the vibration motor to the specified pin (motorPin) and an LED to the built-in LED pin.
* 2. Explore and modify the predefined patterns or create your own by adjusting the intensity, duration, and pauses.
* 3. Use this script as a starting point for implementing diverse haptic and visual feedback in your projects.
*
* Note: Make sure to review and adapt the code to meet your specific hardware requirements and preferences.
*
***********************/

const int motorPin = 23;  // Pin connected to the vibration motor
const int LED_BUILTIN = 2;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Pattern 1: Short pulses with increasing intensity
  for (int intensity = 0; intensity <= 255; intensity += 25) {
    analogWrite(motorPin, intensity);
    delay(50);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 2: Long pulse followed by short pulses
  analogWrite(motorPin, 150);  // Medium intensity for a longer duration
  delay(500);
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity for short pulses
    delay(100);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 3: Alternating pulses
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 200);  // Medium-high intensity
    delay(200);
    analogWrite(motorPin, 0);    // Turn off
    delay(200);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 4: Random intensity pulses
  for (int i = 0; i < 10; i++) {
    int randomIntensity = random(0, 256);
    analogWrite(motorPin, randomIntensity);
    delay(200);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 5: Slow fade in and out (good)
  for (int intensity = 0; intensity <= 255; intensity += 5) {
    analogWrite(motorPin, intensity);
    delay(50);
  }
  for (int intensity = 255; intensity >= 0; intensity -= 5) {
    analogWrite(motorPin, intensity);
    delay(50);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 6: Short pulses with increasing intensity
  for (int intensity = 0; intensity <= 255; intensity += 25) {
    analogWrite(motorPin, intensity);
    delay(50);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 7: Long pulse followed by short pulses
  analogWrite(motorPin, 150);  // Medium intensity for a longer duration
  delay(500);
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity for short pulses
    delay(100);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 8: Alternating pulses
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, 200);  // Medium-high intensity
    delay(200);
    analogWrite(motorPin, 0);    // Turn off
    delay(200);
  }

  delay(100);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 9: Slow ramp-up and quick ramp-down
  for (int intensity = 0; intensity <= 255; intensity += 10) {
    analogWrite(motorPin, intensity);
    delay(100);
  }
  for (int intensity = 255; intensity >= 0; intensity -= 30) {
    analogWrite(motorPin, intensity);
    delay(50);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 10: Random intensity changes
  for (int i = 150; i < 255; i++) {
    int intensity = random(256);
    analogWrite(motorPin, intensity);
    delay(200);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 11: Pulsating waves
  for (int i = 100; i < 255; i++) {
    for (int intensity = 0; intensity <= 255; intensity += 20) {
      analogWrite(motorPin, intensity);
      delay(30);
    }
    for (int intensity = 255; intensity >= 100; intensity -= 20) {
      analogWrite(motorPin, intensity);
      delay(30);
    }
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 12: Double pulse
  for (int i = 0; i < 255; i++) {
    analogWrite(motorPin, 230);  // Medium-high intensity
    delay(100);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
  // Pattern 13: Heartbeat-like pattern
  for (int i = 0; i < 240; i++) {
    analogWrite(motorPin, 200);  // Medium-high intensity
    delay(150);
    analogWrite(motorPin, 0);    // Turn off
    delay(300);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
  // Pattern 14: Quick bursts
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(50);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 15: Random pulses
  for (int i = 0; i < 10; i++) {
    analogWrite(motorPin, random(255));  // Random intensity
    delay(random(100, 500));  // Random duration
    analogWrite(motorPin, 0);    // Turn off
    delay(random(100, 500));  // Random pause
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 16: Wave pattern
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, i * 50);  // Increasing intensity in steps
    delay(150);
  }
  for (int i = 4; i >= 0; i--) {
    analogWrite(motorPin, i * 50);  // Decreasing intensity in steps
    delay(150);
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 17: Morse code "SOS"
  for (int i = 0; i < 3; i++) {
    // S
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(300);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(300);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(300);
    analogWrite(motorPin, 0);    // Turn off
    delay(500);  // Pause between letters
    // O
    analogWrite(motorPin, 255);  // Maximum intensity
    delay(500);
    analogWrite(motorPin, 0);    // Turn off
    delay(500);  // Pause between letters
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

    // Pattern 18: Short pulses with decreasing intensity
  for (int intensity = 255; intensity >= 0; intensity -= 25) {
    analogWrite(motorPin, intensity);
    delay(50);
  }
  analogWrite(motorPin, 0);  // Turn off

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
  // Pattern 19: Triple pulse with random intensity
  for (int i = 0; i < 3; i++) {
    analogWrite(motorPin, random(50, 200));  // Random intensity
    delay(100);
    analogWrite(motorPin, 0);    // Turn off
    delay(100);
  }

    delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
  // Pattern 20: Randomized burst pattern
  for (int i = 0; i < 5; i++) {
    analogWrite(motorPin, random(150, 255));  // Random intensity
    delay(random(50, 200));  // Random duration
    analogWrite(motorPin, 0);  // Turn off
    delay(random(100, 500));  // Random pause
  }
  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 21: Pulsating waves
  for (int i = 0; i < 5; i++) {
    for (int intensity = 0; intensity <= 255; intensity += 20) {
      analogWrite(motorPin, intensity);
      delay(20);
    }
    for (int intensity = 255; intensity >= 0; intensity -= 20) {
      analogWrite(motorPin, intensity);
      delay(20);
    }
  }

  delay(1000);  // Pause between patterns

  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // Pattern 22: Gradual build-up and release
  for (int intensity = 0; intensity <= 255; intensity += 10) {
    analogWrite(motorPin, intensity);
    delay(30);
  }
  for (int intensity = 255; intensity >= 0; intensity -= 10) {
    analogWrite(motorPin, intensity);
    delay(30);
  }

  delay(1000);  // Pause between patterns
  
  // On-board LED blink for visual feedback between patterns
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
    // Pattern 23: Double burst with random intensity
  for (int i = 0; i < 2; i++) {
    analogWrite(motorPin, random(150, 255));  // Random intensity
    delay(100);
    analogWrite(motorPin, 0);  // Turn off
    delay(150);
  }

  delay(1000);  // Pause between patterns

}

  
