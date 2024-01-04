''' READ THIS FIRST /// READ THIS FIRST /// READ THIS FIRST '''
''' The script is not completely working as I would like it to. '''
''' It is able to generate maps. However, they don't exactly '''
''' behave the way I'd like them to.'''

import random
from tqdm import tqdm

def generate_random_point(width, height):
    """Generates a random point within the specified width and height."""
    return random.randint(0, width - 1), random.randint(0, height - 1)

def do_walls_intersect(wall1, wall2):
    """Check if two walls intersect."""
    return not (wall1[0] >= wall2[2] or wall1[2] <= wall2[0] or
                wall1[1] >= wall2[3] or wall1[3] <= wall2[1])

def does_wall_overlap(wall_coords, new_wall):
    """Check if the new wall overlaps with any existing walls."""
    for wall in wall_coords:
        if do_walls_intersect(wall, new_wall):
            return True  # Overlapping
    return False  # Not overlapping

def generate_random_map(width, height, num_walls=20, start_x=100, start_y=85):
    """
    Generates a random maze-like map with walls that a player can navigate through.

    Parameters:
    - width (int): The width of the map.
    - height (int): The height of the map.
    - num_walls (int): The number of walls in the map. Default is 20.
    - start_x (int): The initial x-coordinate of the player. Default is 100.
    - start_y (int): The initial y-coordinate of the player. Default is 85.

    Returns:
    - str: A formatted string containing wall coordinates for the generated map.
    """

    # Initialize the list to store wall coordinates
    wall_coords = [
        [0, 0, width, 0],   # top
        [width, 0, width, height],   # right
        [0, height, width, height],   # bottom
        [0, 0, 0, height]    # left
    ]

    # Draw the walls of the maze
    with tqdm(total=num_walls, desc="Generating Walls") as pbar:
        for _ in range(num_walls):
            end_x, end_y = generate_random_point(width, height)
            new_wall = [start_x, start_y, end_x, end_y]

            # Check for intersection with existing walls
            while does_wall_overlap(wall_coords, new_wall):
                end_x, end_y = generate_random_point(width, height)
                new_wall = [start_x, start_y, end_x, end_y]

            wall_coords.append(new_wall)
            start_x, start_y = end_x, end_y
            pbar.update(1)

    # Connect the last point to the starting point to form a closed loop
    wall_coords.append([start_x, start_y, wall_coords[0][0], wall_coords[0][1]])

    # Convert the wall coordinates to the specified format
    formatted_coords = ",\n".join("{" + ", ".join(map(str, coord)) + "}" for coord in wall_coords)

    return formatted_coords

# Example usage with dimensions similar to your provided map, 20 walls, and customized player start position
width = 110
height = 90
random_map = generate_random_map(width, height, num_walls=20, start_x=80, start_y=60)

# Print the generated map
print("// Set the initial player starting point")
print("int x = 80;")
print("int y = 60;\n")
print("// Wall coordinates making up the map")
print("const int WALL_COORDS[][4] = {")
print(random_map)
print("};")
