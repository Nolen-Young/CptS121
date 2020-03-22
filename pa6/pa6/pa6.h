#ifndef PA6_H
#define PA6_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

typedef struct coordinate {
	int row;
	int column;
} Coordinate;

typedef struct cell {
	char status; // can be the different letter representing the different ships or lack of ships. CAN ALSO DISPLAY H OR M IF A HIT OR A MISS IN THE AREA
	Coordinate location; // A struct defined above, which represents the position of the cell within the game board
} Cell;

void welcome_screen(void);
void initialize_game_board(Cell board[10][10]);
void print_player_board(Cell board[10][10]);
void print_computer_board(Cell board[10][10]);
int check_ship_placement(int size, int row, int column, char orientation, Cell board[10][10]); // returns 0 if not a legal placement and 1 if it is a legal placement
void place_player_ships(Cell board[10][10]);
void place_computer_ships(Cell board[10][10]);
int select_turn_order(); // returns 0 if the user is going first and 1 if the computer is going first
int check_shot(Cell board[10][10], int x, int y); // returns 1 for hit, and 0 for miss, and 2 for an invalid shot
void check_for_sinks(Cell board[10][10], int *aircraft, int *battleship, int *cruiser, int * submarine, int * destroyer);
int check_for_win(int aircraft, int battleship, int cruiser, int submarine, int destroyer, Cell board[10][10]); // returns 1 if the player whos turn is going has won the game, 0 if no win


#endif