/*
* Jonas Kjeldmand Jensen
* Created November 2023
* For the 'Haptic Game for the Blind' Project
*
* small and easy winding snake map
* This map is useful for testing as it is very simple
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