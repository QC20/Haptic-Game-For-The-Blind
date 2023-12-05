#include <ctime>
#include <iostream>

using namespace std;

struct coordinates {
	int height;
	int width;
};

enum movement {
	RIGHT, LEFT, UP, DOWN
};

int random(int lower_limit, int upper_limit) {
	return rand() % (upper_limit - lower_limit + 1) + lower_limit;
}

void add_coordinates(coordinates current_path, coordinates *&path_array, int &current_size) {

	coordinates *new_path_array = new coordinates[current_size + 1];

	for (int i = 0; i < current_size; i++) {
		new_path_array[i] = path_array[i];
	}
	new_path_array[current_size] = current_path;

	current_size++;
	delete[] path_array;
	path_array = new_path_array;
}

void remove_coordinates(int index, coordinates *&path_array, int &current_size) {
	coordinates *new_path_array = new coordinates[current_size - 1];

	for (int i = 0; i < current_size; i++) {
		if (i == index - 1)
			continue;
		else if (i > index - 1)
			new_path_array[i - 1] = path_array[i];
		else
			new_path_array[i] = path_array[i];
	}

	current_size--;
	delete[] path_array;
	path_array = new_path_array;
}

bool check_movement(movement move, coordinates current_position, char **&maze, int max_height, int max_width) {
	if (move == UP) {
		if (current_position.height - 1 < 0)
			return false;
		else {
			if (!(current_position.height - 1 < 0 || current_position.width - 1 < 0))
				if (maze[current_position.height - 1][current_position.width - 1] == ' ')
					return false;
			if (!(current_position.height - 1 < 0 || current_position.width + 1 <= max_width))
				if (maze[current_position.height - 1][current_position.width + 1] == ' ')
					return false;
			if (!(current_position.height - 2 < 0))
				if (maze[current_position.height - 2][current_position.width] == ' ')
					return false;
		}
		return true;
	}
	else if (move == DOWN) {
		if (current_position.height + 1 >= max_height)
			return false;
		else {
			if (!(current_position.height + 1 >= max_height || current_position.width - 1 < 0))
				if (maze[current_position.height + 1][current_position.width - 1] == ' ')
					return false;

			if (!(current_position.height + 1 >= max_height || current_position.width + 1 >= max_width))
				if (maze[current_position.height + 1][current_position.width + 1] == ' ')
					return false;

			if (!(current_position.height + 2 >= max_height))
				if (maze[current_position.height + 2][current_position.width] == ' ')
					return false;
		}
		return true;
	}
	else if (move == RIGHT) {
		if (current_position.width + 1 >= max_width)
			return false;
		else {
			if (!(current_position.width + 2 >= max_width))
				if (maze[current_position.height][current_position.width + 2] == ' ')
					return false;
			if (!(current_position.height + 1 >= max_height || current_position.width + 1 >= max_width))
				if (maze[current_position.height + 1][current_position.width + 1] == ' ')
					return false;
			if (!(current_position.height - 1 < 0 || current_position.width + 1 >= max_width))
				if (maze[current_position.height - 1][current_position.width + 1] == ' ')
					return false;
		}
		return true;
	}

	else if (move == LEFT) {
		if (current_position.width - 1 < 0)
			return false;
		else {
			if (!(current_position.width - 2 < 0))
				if (maze[current_position.height][current_position.width - 2] == ' ')
					return false;
			if (!(current_position.height + 1 >= max_height || current_position.width - 1 < 0))
				if (maze[current_position.height + 1][current_position.width - 1] == ' ')
					return false;
			if (!(current_position.height - 1 < 0 || current_position.width - 1 < 0))
				if (maze[current_position.height - 1][current_position.width - 1] == ' ')
					return false;
		}
		return true;
	}
	else
		return false;
}

bool check_if_possible(coordinates current_position, char **&maze, int height, int width) {
	return check_movement(UP, current_position, maze, height, width) ||
		   check_movement(DOWN, current_position, maze, height, width) ||
		   check_movement(RIGHT, current_position, maze, height, width) ||
		   check_movement(LEFT, current_position, maze, height, width);
}

void generate_next_path(coordinates &current_position, char **&maze, int max_height, int max_width) {
	int possible_move = 0;
	movement possibilities[4];

	if (check_movement(UP, current_position, maze, max_height, max_width)) {
		possibilities[possible_move] = UP;
		possible_move++;
	}
	if (check_movement(DOWN, current_position, maze, max_height, max_width)) {
		possibilities[possible_move] = DOWN;
		possible_move++;
	}
	if (check_movement(RIGHT, current_position, maze, max_height, max_width)) {
		possibilities[possible_move] = RIGHT;
		possible_move++;
	}
	if (check_movement(LEFT, current_position, maze, max_height, max_width)) {
		possibilities[possible_move] = LEFT;
		possible_move++;
	}

	int chosen;
	do
		chosen = rand() % possible_move + 1; 
	    // 0 to possibilities, neglect 0 because it's unfairly unlikely
	while (chosen == 0);

	if (possibilities[chosen-1] == UP) {
		current_position.height--;
	}
	else if (possibilities[chosen-1] == DOWN) {
		current_position.height++;
	}
	else if (possibilities[chosen-1] == RIGHT) {
		current_position.width++;
	}
	else 
		current_position.width--;
}

void fill_maze(char **&maze, int height, int width) {
	for (int i = 0; i < height; i++) {
		maze[i] = new char[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			maze[i][j] = 'x';
		}
	}
	maze[0][0] = ' ';
	maze[height - 1][width - 1] = ' ';
}

void display_maze(char **&maze, int height, int width) {
	for (int i = -1; i <= height; i++) {
		for (int j = -1; j <= width; j++) {
			if (i == -1 || j == -1 || i == height || j == width) {
				cout << '0';
			}
			else
				cout << maze[i][j];
		}
		cout << '\n';
	}
}

void generate_maze(int height, int width) {

	int covered_path_size = 0;
	coordinates *covered_path = new coordinates[0];

	char **p_p_maze = new char*[height];
	fill_maze(p_p_maze, height, width);

	coordinates current_position;
	current_position.height = 0;
	current_position.width = 0;
	add_coordinates(current_position, covered_path, covered_path_size);

	generate_next_path(current_position, p_p_maze, height, width);
	//cout << current_position.height << ' ' << current_position.width;


	//temporary while loop to test logic
		while (check_if_possible(current_position, p_p_maze, height, width)){
			p_p_maze[current_position.height][current_position.width] = ' ';
			generate_next_path(current_position, p_p_maze, height, width);
			p_p_maze[current_position.height][current_position.width] = ' ';
		}
	

	display_maze(p_p_maze, height, width);

}

int main() {
	srand((unsigned)time(NULL));
	generate_maze(20, 40);
	system("pause");
}