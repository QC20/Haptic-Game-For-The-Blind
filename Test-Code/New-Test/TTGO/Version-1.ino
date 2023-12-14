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
int x = 5; 
int y = 25;

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

