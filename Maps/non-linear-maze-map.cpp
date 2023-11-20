/*
* Jonas Kjeldmand Jensen
* Created November 2023
* For the 'Haptic Game for the Blind' Project
*
* This map is a non-linear maze where the user 
* has to figure out how to get to the end.
*
* This design might not work for non-screen devices,
* as there is no way for the user to learn from the trial-and-error
* nature of the game with no visual feedback. 
*
* Map has 5 movement points between player and walls.
* It takes approx. 2-3 seconds for the player to move between walls
* and half if the player is in the middle
*
* This is considered to be average distance 
* Howver, not a tight fit either
*/


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