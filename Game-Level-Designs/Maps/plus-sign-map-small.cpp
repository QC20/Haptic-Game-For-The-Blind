/*
* Jonas Kjeldmand Jensen
* Created November 2023
* For the 'Haptic Game for the Blind' Project
*
* Map is shaped like a big plus sign.
* For user testing, we want to test whether users are able to 
* discern what shape they are navigating through.
*
* Map has 5 movement points between player and walls.
* It takes approx. 2-3 seconds for the player to move between walls
* and half if the player is in the middle
*
* This is considered to be average distance 
* Howver, not a tight fit either
*/


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
