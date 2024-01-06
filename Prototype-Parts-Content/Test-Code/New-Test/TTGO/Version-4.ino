  /**************************************************************************
    TTGO T-Display ST7789 OLED based on Adafruit example
    https://github.com/adafruit/Adafruit-ST7735-Library/blob/master/examples/graphicstest/graphicstest.ino
  **************************************************************************/
  #include <Adafruit_GFX.h>    // Core graphics library
  #include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
  #include <SPI.h>
  #include "pitches.h"

  // pinouts from https://github.com/Xinyuan-LilyGO/TTGO-T-Display
  #define TFT_MOSI 19
  #define TFT_SCLK 18
  #define TFT_CS 5
  #define TFT_DC 16
  #define TFT_RST 23
  #define TFT_BL 4

  //For the stick pins
  #define JS_X 32
  #define JS_Y 33
  #define JS_BOT 39

  // For the vibration motor pin
  #define motorPin 22

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
  int x = 100; 
  int y = 85;

  // Wall coordinates making up the map
  const int WALL_COORDS[][4] = {
    //  <->   up   <->   down
    //  0     0     0     0
    {0, 0, 110, 0}, // top
    {110, 0, 110, 90}, // right
    {0, 90, 90, 90}, // bottom
    {0, 0, 0, 90}, // left
    // Draw the walls of the maze
    //1st horizontal tube lines
    {0, 20, 110, 20},
    {0, 30, 30, 30},
    {10, 30, 10, 70},
    {10, 70, 30, 70},
    {30, 70, 30, 90},
    {30, 90, 90, 90},
    {90, 90, 90, 30},
    {90, 30, 50, 30},
    {50, 30, 50, 70},
    {110, 20, 110, 90},
    {110, 90, 100, 90},
    {70, 50, 30, 50},
    {70, 90, 70, 70},
    {70, 70, 90, 70},
    {40, 20, 40, 40},
    {40, 40, 20, 40},
    {20, 40, 20, 60},
    {20, 60, 40, 60},
    {40, 60, 40, 80},
    {40, 80, 60, 80},
    {60, 80, 60, 60},
    {60, 60, 80, 60},
    {80, 60, 80, 40},
    {80, 40, 60, 40},
    {100, 20, 100, 30},
    {100, 30, 110, 30},
    {90, 40, 100, 40},
    {100, 50, 110, 50},
    {90, 60, 100, 60},
    {100, 70, 110, 70},
    {90, 80, 100, 80},
    };


  // constructor for data object named tft 
  Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

  //are we debugging?
  bool Debugging = true;
  bool mazeRed = false;

  void setup(void) {
    Serial.begin(9600);
    pinMode(TFT_BL, OUTPUT);      // TTGO T-Display enable Backlight pin 4
    pinMode(motorPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(TFT_BL, HIGH);   // T-Display turn on Backlight
    tft.init(135, 240);           // Initialize ST7789 240x135
    Serial.println(F("Initialized"));

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

      // Pattern: Quick and Harsh Error Notification
      musicalErrorNotification();

      delay(250);  // Pause between patterns

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

void musicalErrorNotification() {
  // Define musical notes
  int melody[] = {NOTE_A5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_F5};
  int noteDurations[] = {4, 8, 8, 4, 4, 8, 8, 2};

  // Play the melody
  for (int i = 0; i < 8; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(motorPin, melody[i], noteDuration);
    delay(noteDuration * 1.3);  // Add a slight pause between notes
    noTone(motorPin);  // Turn off the vibration motor
  }
}

