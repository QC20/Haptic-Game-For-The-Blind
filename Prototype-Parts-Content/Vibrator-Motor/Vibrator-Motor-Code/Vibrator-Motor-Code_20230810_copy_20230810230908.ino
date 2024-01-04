/*
    Vibration Motor Control - Created by Jonas Kjeldmand Jensen
    Date: August 10, 2023
*/

int motorPin = 3; // Pin 3 is connected to the motor transistor

void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  digitalWrite(motorPin, HIGH); // Turn on the vibration motor
  delay(1000);  // Keep it on for one second
  digitalWrite(motorPin, LOW);  // Turn off the vibration motor
  delay(1000); // Wait for 50 seconds before the next cycle
}
