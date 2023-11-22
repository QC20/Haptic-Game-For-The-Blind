// decreases from high to low vibration over time


int vibe = 23;
int amplitude = 0;

float x;

void setup(){
  pinMode(vibe, OUTPUT);
  analogWrite (vibe,0);

}

void loop(){
  analogWrite(vibe,255);
  delay(250);
  analogWrite(vibe,224);
  delay(250);
  analogWrite(vibe,192);
  delay(250);
  analogWrite(vibe,160);
  delay(250);
  analogWrite(vibe,128);
  delay(250);
  analogWrite(vibe,96);
  delay(250);
  analogWrite(vibe,64);
  delay(250);
  analogWrite(vibe,32);
  delay(250);
  analogWrite(vibe,0);
  delay(250);
  analogWrite(vibe,32);
  delay(250);
  analogWrite(vibe,64);
  delay(250);
  analogWrite(vibe,96);
  delay(250);
  analogWrite(vibe,128);
  delay(250); 
  analogWrite(vibe,160);
  delay(250);
  analogWrite(vibe,192);
  delay(250);
  analogWrite(vibe,224);
  delay(250); 
  analogWrite(vibe,255);
  delay(250);
}