/***************************************************************************
* ESP32 Haptic Joystick 
* -- using vibration motor + joystick + ESP32 D1 Mini
*
* 
*  by Josh Hrisko | Maker Portal LLC (c) 2021
* 
* 
***************************************************************************/

int joy_pins[4] = {35,34,14}; // pins being used for joystick
float bit_depth = pow(2.0,12); // ADC conversion ratio
float Rx_offset = 0.0; // offset in x-dir
float Ry_offset = 0.0; // offset in y-dir

const int buzz_pin = 21;  // corresponds to GPIO2 on ESP32

void setup(){ 
  Serial.begin(9600);
  pinMode(joy_pins[0],INPUT); // VR_x pin
  pinMode(joy_pins[1],INPUT); // VR_y pin
  pinMode(joy_pins[2],INPUT_PULLUP); // SW pin
  pinMode(buzz_pin,OUTPUT); // output for buzzer
  Serial.println("VRx,VRy,SW");
  delay(100);
  Rx_offset = float(analogRead(joy_pins[0]))/bit_depth; // calc offset
  Ry_offset = float(analogRead(joy_pins[1]))/bit_depth; // calc offset
}

void loop(){
  float Rx = float(analogRead(joy_pins[0]))/bit_depth-Rx_offset; // instantaneous x-joystick
  float Ry = float(analogRead(joy_pins[1]))/bit_depth-Ry_offset; // instantaneous y-joystick
  int   SW = digitalRead(joy_pins[2]); // instantaneous z-joystick (press down)
  Serial.print(Rx); Serial.print(","); // print for debugging (-0.45 to +0.55)
  Serial.print(Ry); Serial.print(","); // print for debugging (-0.45 to +0.55)
  Serial.println(SW); // print press (0-1)
  delay(1);

  if (Rx<-0.1){
    buzz_now(1,100,0,0); // (joystick left) buzz without delays
  } else if (Ry<-0.1){ 
    buzz_now(2,100,100,0); // (joystick down) buzz on/off equally for 100ms 
  } else if (Rx>0.1){
    buzz_now(1,600,200,0); // (joystick right) long buzz 600ms on, 200 off 
  } else if (Ry>0.1){
    buzz_now(3,80,80,150); // (joystick up) buzz with 'train' style rhythm
  } else if (SW==0){
    buzz_now(2,150,150,300); // (joystick press) heartbeat rhythm (dual buzz, with delay)
  }
}

void buzz_now(int buzz_count,int delay_1,int delay_2,int final_delay){ // buzz function
  for (int ii=0;ii<buzz_count;ii++){ // loop 
    digitalWrite(buzz_pin,HIGH); // set buzzer on
    delay(delay_1); // keep on for delay_1 [ms]
    digitalWrite(buzz_pin,LOW); // set buzz off
    delay(delay_2); // keep off for delay_2 [ms]
  }
  delay(final_delay); // final delay before restarting or moving on
}