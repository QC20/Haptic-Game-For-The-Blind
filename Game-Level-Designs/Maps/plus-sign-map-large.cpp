/*
* Jonas Kjeldmand Jensen
* Created November 2023
* For the 'Haptic Game for the Blind' Project
*
* Map is shaped like a big plus sign
* Map has 10 movement points between player and walls.
*
* It takes approx. 4-5 seconds for the player to move between walls
* This is considered to be a lot of space
*
*/


// Set the initial player starting point
int x = 5; 
int y = 10;

// Wall coordinates
const int WALL_COORDS[][4] = {
  //  <->   up   <->   down
  //  0     0     0     0
  {0, 0, 140, 0},     // top
  {140, 0, 140, 140}, // right
  {0, 140, 140, 140}, // bottom
  {0, 0, 0, 140},     // left
  // Draw the walls of the maze
  {0, 0, 140, 0},
  {0, 0, 140, 0},
  {0, 20, 20, 20},
  {0, 20, 0, 100},
  {40, 0, 40, 40},
  {10, 40, 40, 40},
  {0, 60, 100, 60},
  {60, 20, 60, 100},
  {0, 100, 20, 100},
  {20, 100, 20, 140},
  {80, 0, 80, 30},
  {100, 20, 140, 20},
  {140, 20, 140, 100},
  {140, 100, 100, 100},
  {100, 100, 100, 140},
  {100, 140, 20, 140},
  {10, 80, 40, 80},
  {40, 80, 40, 120},
  {40, 120, 80, 120},
  {80, 120, 80, 80},
  {80, 80, 120, 80},
  {120, 80, 120, 40},
  {120, 40, 80, 40},
  };