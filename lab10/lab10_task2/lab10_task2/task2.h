#include <stdio.h>

typedef struct coordinate
{
	int row;
	in column;
} Coordinate;

typedef struct cell
{
	int occupied; // 1 if an X or O is in this cell; 0 otherwise
	char symbol; // X for one player, O for the other player
	Coordinate location; // A struct defined above, which represents the position of the cell within the game board
} Cell;

