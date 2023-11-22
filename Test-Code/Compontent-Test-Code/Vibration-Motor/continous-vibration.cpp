/***********************
*
* Code to show how to program the vibration motor for continous
* varying intensity in the vibration pattern
*
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

  // Vary the intensity from 255 to 0
  for (int intensity = 255; intensity >= 0; intensity--) {
    analogWrite(motorPin, intensity);
    delay(10);  // Adjust delay to control the speed of intensity change

    
  }
}
