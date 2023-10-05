// Include required libraries
#include <Arduino.h>

// Define the pins for joystick connections
const int joystickXPin = A0;
const int joystickYPin = A1;
const int joystickButtonPin = 2;

// Variables to store joystick readings
int joystickXValue = 0;
int joystickYValue = 0;
int joystickButtonState = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set joystick button pin as an input with internal pull-up resistor
  pinMode(joystickButtonPin, INPUT_PULLUP);
}

void loop() {
  // Read joystick X and Y axis values
  joystickXValue = analogRead(joystickXPin);
  joystickYValue = analogRead(joystickYPin);

  // Read joystick button state
  joystickButtonState = digitalRead(joystickButtonPin);

  // Print joystick readings
  Serial.print("X-axis: ");
  Serial.print(joystickXValue);
  Serial.print("\tY-axis: ");
  Serial.print(joystickYValue);
  Serial.print("\tButton: ");
  Serial.println(joystickButtonState);

  // Add some delay to prevent continuous readings
  delay(100);
}