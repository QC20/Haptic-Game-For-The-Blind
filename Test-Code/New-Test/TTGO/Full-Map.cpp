  // Set the initial player starting point
  int x = 75; 
  int y = 220;

  // Wall coordinates making up the map
  const int WALL_COORDS[][4] = {
    //  <->   up   <->   down
    //  0     0     0     0
    {10, 10, 113, 10}, // top
    {10, 10, 10, 230}, // Left
    {10, 230, 130, 230}, // bottom
    {10, 10, 10, 230}, // left
    // Draw the walls of the maze
    {70, 230, 70, 220},
    {80, 230, 80, 210},

    };
