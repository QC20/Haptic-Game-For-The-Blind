#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Arduino.h>      // this is needed for FT6206
#include <Adafruit_FT6206.h>


#define TFT_DC 12
#define TFT_CS 13

#define BLACK 0x0000  // macros for color (16 bit)
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

//stick pins
#define JS_X 34
#define JS_Y 35

#define DIR_STOP 0
#define DIR_UP 1
#define DIR_DWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int xLast = 0;//store the previous value of x y
int yLast = 0;//only print out when changes..

int x = 16;
int y = 73;

// Wall coordinates
const int WALL_COORDS[][4] = {
  //  <->   up   <->   down
  //  0     0     0     0
  {0, 0, 127, 0},     // top
  {127, 0, 127, 159}, // right
  {0, 159, 127, 159}, // bottom
  {0, 0, 0, 159},     // left
  // Draw the walls of the maze
  //Horizontal
  {9, 24, 121, 24},
  {23, 38, 65, 38},
  {65, 52, 107, 52},
  {9, 66, 37, 66},
  {51, 66, 93, 66},
  {23, 80, 65, 80},
  {93, 80, 107, 80},
  {9, 108, 37, 108},
  {9, 108, 37, 108},
  {37, 94, 51, 94},
  {65, 108, 79, 108},
  {93, 108, 107, 108},
  {23, 122, 65, 122},
  {79, 122, 93, 122},
  {9, 136, 121, 136},
  //Vertical
  {9, 24, 9, 66},
  {93, 24, 93, 38},
  {121, 24, 121, 122},
  {23, 38, 23, 52},
  {51, 38, 51, 66},
  {79, 38, 79, 52},
  {107, 38, 107, 94},
  {37, 52, 37, 66},
  {23, 66, 23, 94},
  {79, 66, 79, 122},
  {9, 80, 9, 136},
  {65, 80, 65, 108},
  {93, 80, 93, 108},
  {37, 94, 37, 108},
  {51, 94, 51, 122},
  {107, 108, 107, 136}
};



Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_FT6206 ts = Adafruit_FT6206();//touch

//are we debugging?
bool Debugging = true;
bool mazeRed = false;



void setup() {

  Serial.begin(115200);
  while (!Serial);
  tft.begin();
 

  mazeWalls(YELLOW);


}

int readStick() {

  int result = DIR_STOP;

  // read analog X and Y analog values
  xValue = analogRead(JS_X);
  yValue = analogRead(JS_Y);

  if (xValue == 0)
  {
    //down
    result = DIR_DWN;

  } else if (xValue > 2048)
  {
    //up
    result = DIR_UP;

  }
  if (result == DIR_STOP) {
    if (yValue == 0)
    {
      //right
      result = DIR_RIGHT;
    } else if (yValue > 2048)
    {
      //left
      result = DIR_LEFT;
    }
  }

  return result;

}

void drawPlayer(uint16_t color){
  tft.drawPixel(x, y  , color);
  tft.drawPixel(x, y-1, color);
  tft.drawPixel(x-1, y, color);
  tft.drawPixel(x, y+1, color);
  tft.drawPixel(x+1, y, color);
}

void loop() {

  int buttons = readStick();
  drawPlayer(WHITE);
  delay(200);

if (mazeRed){
      mazeWalls(YELLOW);
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
      //flash maze walls red..
      mazeWalls(RED);
      mazeRed = true;
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
}

