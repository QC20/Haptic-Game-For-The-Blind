#include <Arduino.h>

const int joystickXPin = 34; // Joystick X-axis connected to GPIO 34
const int joystickYPin = 35; // Joystick Y-axis connected to GPIO 35
const int joystickButtonPin = 32; // Joystick button connected to GPIO 32

void setup() {
  Serial.begin(9600);
  pinMode(joystickButtonPin, INPUT);
  digitalWrite(joystickButtonPin, HIGH); // Enable the internal pull-up resistor
}

void loop() {
  int xPosition = analogRead(joystickXPin);
  int yPosition = analogRead(joystickYPin);
  bool buttonState = (digitalRead(joystickButtonPin) == LOW); // Read the button state

  // You may need to adjust the analogRead values to match your specific joystick's range.
  // The values typically range from 0 to 4095 for the ESP32's ADC.

  Serial.print("X Position: ");
  Serial.print(xPosition);
  Serial.print("\tY Position: ");
  Serial.print(yPosition);
  Serial.print("\tButton State: ");
  Serial.println(buttonState ? "Pressed" : "Released");

  delay(100); // Adjust the delay to control the update rate
}
