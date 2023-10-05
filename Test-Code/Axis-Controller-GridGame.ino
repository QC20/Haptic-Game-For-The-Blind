#include <Joystick.h>  // Include the library for the joystick

Joystick joystick(A0, A1);  // Create a joystick object with analog pins A0 and A1

const int numRows = 5;  // Number of rows in the map
const int numCols = 7;  // Number of columns in the map

// Define the map using a 2D array
int map[numRows][numCols] = {
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 1, 1, 1, 1},
  {0, 1, 0, 0, 0, 0, 1},
  {0, 1, 1, 1, 1, 1, 1}
};

int playerRow = 0;  // Initial player row position
int playerCol = 0;  // Initial player column position

void setup() {
  // Initialize your setup here
  Serial.begin(115200);  // Initialize serial communication
}

void loop() {
  // Read joystick inputs
  int xInput = joystick.getX();
  int yInput = joystick.getY();
  
  // Update player position based on joystick inputs
  if (xInput > 800) {  // Move right
    playerCol = min(playerCol + 1, numCols - 1);
  }
  if (xInput < 200) {  // Move left
    playerCol = max(playerCol - 1, 0);
  }
  if (yInput > 800) {  // Move down
    playerRow = min(playerRow + 1, numRows - 1);
  }
  if (yInput < 200) {  // Move up
    playerRow = max(playerRow - 1, 0);
  }
  
  // Display updated map with player position
  displayMap();
  
  delay(100);  // Add a small delay to prevent rapid updates
}

void displayMap() {
  // Print the map layout with player position
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (i == playerRow && j == playerCol) {
        Serial.print("P ");  // Print player symbol
      } else {
        Serial.print(map[i][j]);
        Serial.print(" ");
      }
    }
    Serial.println();
  }
}