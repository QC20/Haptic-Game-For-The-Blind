/***********************

Created by Jonas Kjeldmand Jensen
November 2023

Haptic Game for the Blind

***********************/


#include <Adafruit_ILI9341.h>
#include <SPI.h>

// Pin connections for the display (adjust according to your wiring)
#define TFT_DC 12 // DC or RS pin (GPIO33 on ESP32)
#define TFT_CS 13 // CS or SS pin (GPIO15 on ESP32)
#define TFT_RST 4  // Reset pin (GPIO32 on ESP32, optional)
#define TFT_MOSI 23  // MOSI pin (GPIO13 on ESP32)
#define TFT_CLK  18  // CLK or SCK pin (GPIO14 on ESP32)

//For the stick pins
#define JS_X 34
#define JS_Y 35
#define JS_BOT 33

// For the vibration motor
#define vibr 27

// Verify by having the built-in LED blink as well
#define LED_BUILTIN 2
/***********************
lcd pin  1     2    3    4     5      6    7     8

e2sp    VIN  GND    15   12     33    23   18     3v3

************************************/

// macros for color (16 bit)
#define BLACK 0x0000  
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F
#define LIME 0x67E0



#define DIR_STOP 0
#define DIR_UP 1
#define DIR_DWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int xLast = 0;//store the previous value of x y
int yLast = 0;//only print out when changes..

// Set the initial player starting point
int x = 5; 
int y = 55;

// Wall coordinates
const int WALL_COORDS[][4] = {
  //  <->   up   <->   down
  //  0     0     0     0
  {0, 0, 90, 0},     // top
  {90, 0, 90, 90}, // right
  {0, 90, 90, 90}, // bottom
  {0, 0, 0, 90},     // left
  // Draw the walls of the maze
  //1st horizontal tube lines
  {0, 60, 30, 60}, // bottom first tube line
  {0, 50, 20, 50}, // top first tube line
  // 1st vertical tube lines
  {20, 50, 20, 25}, // bottom first tube line
  {30, 60, 30, 35}, // top first tube line
  // 2nd horizontal tube lines
  {45, 35, 30, 35}, // bottom 2nd tube line
  {55, 25, 20, 25}, // top 2nd tube line
  // 2nd vertical tube lines
  {55, 50, 55, 25}, // right 2nd tube line
  {45, 60, 45, 35}, // left 2nd tube line
  // 3nd horizontal tube lines
  {55, 50, 60, 50}, // right 2nd tube line
  {45, 60, 70, 60}, // right 2nd tube line
  // 3rd vertical tube lines
  {70, 60, 70, 25}, // right 2nd tube line
  {60, 50, 60, 15}, // right 2nd tube line
  // 4th horizontal tube lines
  {60, 15, 90, 15}, // right 2nd tube line
  {90, 25, 70, 25}, // right 2nd tube line
  };


// Create an instance of the ILI9341 display
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

//are we debugging?
bool Debugging = true;
bool mazeRed = false;

void setup() {

  Serial.begin(9600);
  while (!Serial);
  pinMode(vibr, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  tft.begin();
 
  mazeWalls(RED);  // Draw the original red walls
  mazeWalls(YELLOW);  // Draw the additional yellow walls
}

// Function to read joystick input and determine direction
int readStick() {
  // Initialize the result to stop
  int result = DIR_STOP;
  // Read analog X and Y values from joystick
  xValue = analogRead(JS_X);
  yValue = analogRead(JS_Y);

  // Check X-axis for up or down
  if (xValue == 0) {
    // Down
    result = DIR_DWN;
  } else if (xValue > 2048) {
    // Up
    result = DIR_UP;
  }
  // If no up or down input, check Y-axis for left or right
  if (result == DIR_STOP) {
    if (yValue == 0) {
      // Left
      result = DIR_LEFT;
    } else if (yValue > 2048) {
      // Right
      result = DIR_RIGHT;
    }
  }
  // Return the detected direction
  return result;
}

// Function to draw a player at the specified coordinates with the given color
void drawPlayer(uint16_t color){
  // Draw pixels at the center and surrounding positions to create a simple player representation
  tft.drawPixel(x, y  , color); // Center pixel
  tft.drawPixel(x, y-1, color); // Pixel above center
  tft.drawPixel(x-1, y, color); // Pixel to the left of center
  tft.drawPixel(x, y+1, color); // Pixel below center
  tft.drawPixel(x+1, y, color); // Pixel to the right of center
}

void loop() {

  int buttons = readStick();
  drawPlayer(WHITE);
  delay(200);

if (mazeRed){
      mazeWalls(RED);
  }

  // Check if the user's next move will intersect with a wall
  bool canMove = buttons != DIR_STOP;
  int nextX = x, nextY = y;

  if (buttons == DIR_LEFT) {
    nextX -= 1;
    if (nextX < 0 || nextX > 127) { // out of bounds
      canMove = false;
    } else {
      // Check if the next move intersects with a wall
      if (wallCollision(nextX, nextY)) canMove = false;
    }
  } else if (buttons == DIR_UP) {
    nextY -= 1;
    if (nextY < 0 || nextY > 159) { // out of bounds
      canMove = false;
    } else {
      // Check if the next move intersects with a wall
      if (wallCollision(nextX, nextY)) canMove = false;
    }
  } else if (buttons == DIR_RIGHT) {
    nextX += 1;
    if (nextX < 0 || nextX > 127) { // out of bounds
      canMove = false;
    } else {
      // Check if the next move intersects with a wall
      if (wallCollision(nextX, nextY)) canMove = false;
    }
  } else if (buttons == DIR_DWN) {
    nextY += 1;
    if (nextY < 0 || nextY > 159) { // out of bounds
      canMove = false;
    } else {
      // Check if the next move intersects with a wall
      if (wallCollision(nextX, nextY)) canMove = false;
    }
  }

  // Move the user if allowed
  if (canMove) {
    //erase last pos..
    drawPlayer(BLACK);
    x = nextX;
    y = nextY;
  }
}

bool wallCollision(int nx, int ny) {
  bool result = false;

  // Check if the next move intersects with a wall
  for (int i = 0; i < sizeof(WALL_COORDS) / sizeof(WALL_COORDS[0]); i++) {
    int x1 = WALL_COORDS[i][0];
    int y1 = WALL_COORDS[i][1];
    int x2 = WALL_COORDS[i][2];
    int y2 = WALL_COORDS[i][3];

    if (x1 == x2 && x1 == nx && y1 <= ny && y2 >= ny ||
        y1 == y2 && y1 == ny && x1 <= nx && x2 >= nx) {
      result = true;

      //flash maze walls red when player collides with wall
      mazeWalls(BLUE);
      mazeRed = true;

      // motor vibrates when player collides with wall
      digitalWrite(vibr, 1);
      delay(150); 
      digitalWrite(vibr, 0);
      delay(150); 
      digitalWrite(vibr, 1);
      delay(150);
      digitalWrite(vibr, 0);

      // Built-in LED light
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(500);              

      break;
    }
  }
  return result;
}

void mazeWalls(uint16_t color) {
  // Draw the walls of the maze
  for (int i = 0; i < sizeof(WALL_COORDS) / sizeof(WALL_COORDS[0]); i++) {
    int x1 = WALL_COORDS[i][0];
    int y1 = WALL_COORDS[i][1];
    int x2 = WALL_COORDS[i][2];
    int y2 = WALL_COORDS[i][3];
    tft.drawLine(x1, y1, x2, y2, color);
  }

    // Draw the yellow walls
  for (int i = 0; i < sizeof(WALL_COORDS) / sizeof(WALL_COORDS[0]); i++) {
    int x1 = WALL_COORDS[i][0];
    int y1 = WALL_COORDS[i][1];
    int x2 = WALL_COORDS[i][2];
    int y2 = WALL_COORDS[i][3];
    tft.drawLine(x1, y1, x2, y2, YELLOW);
  }
}