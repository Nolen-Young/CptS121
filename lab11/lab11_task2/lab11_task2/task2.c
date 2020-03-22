#include "task2.h"

int maze_solver(int x, int y, char maze[8][8]) {
	if (x == 7 && y == 7) {
		return 1;
	}
	else if (maze[x][y] == 'X') {
		return 0;
	}
	else {

	}
}
