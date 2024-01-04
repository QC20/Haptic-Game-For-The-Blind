import random

def generate_random_map(width, height):
    """
    Generates a random maze-like map with walls that a player can navigate through.

    Parameters:
    - width (int): The width of the map.
    - height (int): The height of the map.

    Returns:
    - str: A formatted string containing wall coordinates for the generated map.
    """

    # Set the initial player starting point
    x = 100
    y = 85

    # Initialize the list to store wall coordinates
    wall_coords = [
        [0, 0, width, 0],   # top
        [width, 0, width, height],   # right
        [0, height, width, height],   # bottom
        [0, 0, 0, height]    # left
    ]

    # Draw the walls of the maze
    for _ in range(20):  # Adjust the number of walls as needed
        x_end = random.randint(0, width - 1)
        y_end = random.randint(0, height - 1)
        wall_coords.append([x, y, x_end, y_end])
        x = x_end
        y = y_end

    # Connect the last point to the starting point to form a closed loop
    wall_coords.append([x, y, 100, 85])

    # Convert the wall coordinates to the specified format
    formatted_coords = ",\n".join("{" + ", ".join(map(str, coord)) + "}" for coord in wall_coords)

    return formatted_coords

# Example usage with dimensions similar to your provided map
width = 110
height = 90
random_map = generate_random_map(width, height)

# Print the generated map
print("// Set the initial player starting point")
print("int x = 100;")
print("int y = 85;\n")
print("// Wall coordinates making up the map")
print("const int WALL_COORDS[][4] = {")
print(random_map)
print("};")
