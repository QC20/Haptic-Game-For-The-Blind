/***********************
*
* Code to show how to program the vibration motor for continous and descreet
* varying intensity in the vibration pattern
*
* shows how the two input methods work in conjunction
*
***********************/

const int motorPin = 23;  // Pin connected to the vibration motor

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Vary the intensity from 0 to 255
  for (int intensity = 0; intensity <= 255; intensity++) {
    analogWrite(motorPin, intensity);
    delay(10);  // Adjust delay to control the speed of intensity change
  }

    // Turn off vibration for a brief period
  analogWrite(motorPin, 0); // set a value between 0-255
  delay(2000);  // Adjust delay to control the off duration

    // Vary the intensity from 255 to 0
  for (int intensity = 255; intensity >= 0; intensity--) {
    analogWrite(motorPin, intensity);
    delay(10);  // Adjust delay to control the speed of intensity change
  }

  // Turn off vibration for a brief period
  analogWrite(motorPin, 255); // set a value between 0-255
  delay(1000);  // Adjust delay to control the off duration

  // Turn off vibration for a longer period
  analogWrite(motorPin, 100); // set a value between 0-255
  delay(5000);  // Adjust delay to control the off duration

    // Turn off vibration for a brief period
  analogWrite(motorPin, 200); // set a value between 0-255
  delay(3000);  // Adjust delay to control the off duration
}
