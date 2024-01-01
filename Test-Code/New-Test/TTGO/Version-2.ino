  /**************************************************************************
    TTGO T-Display ST7789 OLED based on Adafruit example
    https://github.com/adafruit/Adafruit-ST7735-Library/blob/master/examples/graphicstest/graphicstest.ino
  **************************************************************************/
  #include <SPI.h>
  #include <Adafruit_GFX.h>    // Core graphics library
  #include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
  #include "pitches.h"

  // pinouts from https://github.com/Xinyuan-LilyGO/TTGO-T-Display
  #define TFT_MOSI 19
  #define TFT_SCLK 18
  #define TFT_CS 5
  #define TFT_DC 16
  #define TFT_RST 23
  #define TFT_BL 4



  //For the stick pins
  #define JS_X 32 // Grey wire
  #define JS_Y 33  // Green wire
  #define JS_BOT 39 // Yellow wire

  // For the vibration motor pin
  #define motorPin 22 // Purple wire

  // Verify by having the built-in LED blink as well
  #define LED_BUILTIN 2

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

  // Constants representing movement directions for a game or application
  #define DIR_STOP 0   // No movement
  #define DIR_UP 1     // Upward movement
  #define DIR_DOWN 2   // Downward movement
  #define DIR_LEFT 3   // Leftward movement
  #define DIR_RIGHT 4  // Rightward movement

  // Variables for joystick input tracking
  int xValue = 0;   // To store the value of the X-axis
  int yValue = 0;   // To store the value of the Y-axis
  int xLast = 0;    // Store the previous value of X
  int yLast = 0;    // Store the previous value of Y, only print out when changes occur

  // Set the initial player starting point
  int x = 75; 
  int y = 225;

  // Wall coordinates making up the map
  const int WALL_COORDS[][4] = {
    //  <->   up   <->   down
    //  0     0     0     0
    //  <->   up   <->   down
    //  0     0     0     0
    {10, 10, 100, 10}, // top
    {10, 10, 10, 230}, // Left
    {10, 230, 100, 230}, // bottom
    {100, 10, 100, 230}, // left
    // Draw the walls of the maze
    {70, 230, 70, 220},
    {80, 230, 80, 190},
    {81, 230, 81, 190},
    {80, 210, 60, 210},
    {70, 220, 20, 220},
    {50, 220, 50, 200},
    {50, 200, 70, 200},
    {80, 190, 40, 190},
    {40, 190, 40, 210},
    {40, 210, 30, 210},
    {20, 220, 20, 170},
    {30, 210, 30, 180},
    {20, 170, 50, 170},
    {30, 180, 60, 180},
    {60, 180, 60, 160},
    {60, 160, 40, 120},
    {50, 170, 50, 160},
    {50, 160, 30, 110},
    {40, 120, 50, 120},
    {30, 110, 50, 110},
    {50, 120,90, 90},
    {50, 110, 80, 90},
    {90, 90, 60, 60},
    {80, 90, 60, 80},
    {60, 80, 20, 110},
    {80, 40, 30, 90},
    {20, 90, 60, 50},
    {80, 40, 30, 50},
    {60, 50, 20, 60},
    {20, 60, 20, 40},
    {20, 40, 70, 30},
    {80, 40, 80, 10},
    {70, 30, 70, 20},
    {60, 10, 60, 20},
    {60, 20, 40, 30},
    {40, 30, 20, 30},
    {20, 30, 20, 20},
    {30, 10, 30, 20},
    {30, 20, 40, 20},
    {40, 20, 40, 10},
    {50, 10, 50, 20},
    {50, 20, 60, 20},
    {20, 110, 20, 80},
    {20, 40, 10, 40},
    };

// constructor for data object named tft 
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


  //are we debugging?
bool Debugging = true;
bool mazeRed = false;


  void setup(void) {
    Serial.begin(9600);
    pinMode(TFT_BL, OUTPUT);      // TTGO T-Display enable Backlight pin 4
    digitalWrite(TFT_BL, HIGH);   // T-Display turn on Backlight
    tft.init(135, 240);           // Initialize ST7789 240x135
    pinMode(motorPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

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
    result = DIR_DOWN;
  } else if (xValue > 2048) {
    // Up
    result = DIR_UP;
  }
  // If no up or down input, check Y-axis for left or right
  if (result == DIR_STOP) {
    if (yValue == 0) {
      // Left
      result = DIR_RIGHT;
    } else if (yValue > 2048) {
      // Right
      result = DIR_LEFT;
    }
  }
  // Return the detected direction
  return result;
}

// Function to draw a player at the specified coordinates with the given color
void drawPlayer(uint16_t color) {
  // Draw pixels at the center and surrounding positions to create a simple player representation
  tft.drawPixel(x, y  , color); // Center pixel
  tft.drawPixel(x, y-1, color); // Pixel above center
  tft.drawPixel(x-1, y, color); // Pixel to the left of center
  tft.drawPixel(x, y+1, color); // Pixel below center
  tft.drawPixel(x+1, y, color)  ; // Pixel to the right of center
}


void loop() {
  // Read joystick input to determine buttons pressed
  int buttons = readStick();

  // Draw the player on the screen with a white color
  drawPlayer(WHITE);
  delay(200); // Introduce a delay to control the speed of the loop (adjust as needed)

  // If the variable 'mazeRed' is true, draw maze walls in red
  if (mazeRed) {
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
  } else if (buttons == DIR_DOWN) {
    nextY += 1;
    if (nextY < 0 || nextY > 159) { // out of bounds
      canMove = false;
    } else {
      // Check if the next move intersects with a wall
      if (wallCollision(nextX, nextY)) canMove = false;
    }
  }

  // If the user can move, update the player's position
  if (canMove) {
    // Erase the last position by drawing the player in black
    drawPlayer(BLACK);
    // Update the player's position to the new coordinates
    x = nextX;
    y = nextY;
  }
}

// Function to check if the next move intersects with a wall
bool wallCollision(int nx, int ny) {
  bool result = false;

  // Iterate through each wall in WALL_COORDS
  for (int i = 0; i < sizeof(WALL_COORDS) / sizeof(WALL_COORDS[0]); i++) {
    // Extract coordinates of the current wall
    int x1 = WALL_COORDS[i][0];
    int y1 = WALL_COORDS[i][1];
    int x2 = WALL_COORDS[i][2];
    int y2 = WALL_COORDS[i][3];

    // Check if the next move intersects with the current wall
    if (x1 == x2 && x1 == nx && y1 <= ny && y2 >= ny ||
        y1 == y2 && y1 == ny && x1 <= nx && x2 >= nx) {
      // Set result to true if there is a collision
      result = true;

      //flash maze walls BLUE when player collides with wall
      mazeWalls(BLUE);
      mazeRed = true;

      // motor motorPinates when player collides with wall
      digitalWrite(motorPin, 1);
      delay(150); 
      digitalWrite(motorPin, 0);
      delay(150); 
      digitalWrite(motorPin, 1);
      delay(150);
      digitalWrite(motorPin, 0);

      // Built-in LED light
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);              

      // Break out of the loop since we found a collision
      break;
    }
  }
  // Return the final result (true if there is a collision, false otherwise)
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
