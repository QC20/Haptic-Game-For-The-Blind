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

def adjust_endpoints(previous_wall, new_wall):
    """
    Adjust the endpoints of the new wall so that it connects with the
    previous wall without crossing it.
    """
    new_start_x, new_start_y = previous_wall[2], previous_wall[3]
    new_end_x, new_end_y = new_wall[2], new_wall[3]

    # Adjust the new wall's endpoint to avoid crossing the previous wall
    while do_walls_intersect(previous_wall, [new_start_x, new_start_y, new_end_x, new_end_y]):
        new_end_x, new_end_y = generate_random_point(width, height)

    return new_start_x, new_start_y, new_end_x, new_end_y

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
            # Randomly select a direction (horizontal or vertical)
            direction = random.choice(['horizontal', 'vertical'])

            # Determine the length of the wall
            length = random.randint(5, 15)

            # Generate new wall coordinates based on the selected direction and length
            if direction == 'horizontal':
                end_x = start_x + length
                end_y = start_y
            else:
                end_x = start_x
                end_y = start_y + length

            new_wall = [start_x, start_y, end_x, end_y]

            # Check for intersection with existing walls
            while does_wall_overlap(wall_coords, new_wall):
                # If intersection, generate a new random point and adjust endpoints
                end_x, end_y = generate_random_point(width, height)
                new_wall = adjust_endpoints(wall_coords[-2], [start_x, start_y, end_x, end_y])

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
