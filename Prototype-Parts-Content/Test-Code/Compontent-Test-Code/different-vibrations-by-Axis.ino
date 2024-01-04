int joy_pins[2] = {A0, A1}; // pins being used for joystick
float bit_depth = pow(2.0, 10); // ADC conversion ratio
float Rx_offset = 0.0; // offset in x-dir
float Ry_offset = 0.0; // offset in y-dir

const int buzz_pin = 2; // corresponds to digital pin 2 on Arduino

void setup() {
  Serial.begin(9600);
  pinMode(joy_pins[0], INPUT); // VR_x pin
  pinMode(joy_pins[1], INPUT); // VR_y pin
  pinMode(buzz_pin, OUTPUT); // output for buzzer
  Serial.println("VRx,VRy");
  delay(100);
  Rx_offset = float(analogRead(joy_pins[0])) / bit_depth; // calc offset
  Ry_offset = float(analogRead(joy_pins[1])) / bit_depth; // calc offset
}

void loop() {
  float Rx = float(analogRead(joy_pins[0])) / bit_depth - Rx_offset; // instantaneous x-joystick
  float Ry = float(analogRead(joy_pins[1])) / bit_depth - Ry_offset; // instantaneous y-joystick
  Serial.print(Rx); Serial.print(","); // print for debugging (-0.5 to +0.5)
  Serial.println(Ry); // print for debugging (-0.5 to +0.5)
  delay(1);

  if (Rx < -0.1) {
    buzz_now(1, 100, 0); // (joystick left) buzz without delays
  } else if (Ry < -0.1) {
    buzz_now(1, 100, 0); // (joystick down) buzz without delays
  } else if (Rx > 0.1) {
    buzz_now(1, 600, 200); // (joystick right) long buzz 600ms on, 200 off
  } else if (Ry > 0.1) {
    buzz_now(1, 80, 150); // (joystick up) buzz with 'train' style rhythm
  }
}

void buzz_now(int buzz_count, int delay_1, int delay_2) { // buzz function
  for (int ii = 0; ii < buzz_count; ii++) { // loop
    digitalWrite(buzz_pin, HIGH); // set buzzer on
    delay(delay_1); // keep on for delay_1 [ms]
    digitalWrite(buzz_pin, LOW); // set buzz off
    delay(delay_2); // keep off for delay_2 [ms]
  }
}