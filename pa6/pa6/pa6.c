#include "pa6.h"

void welcome_screen(void) {
	// prints a friendly welcome screen with rules
	printf("****Welcome to Battleship***\n\
1. This is a 2 player game.\n\
2. Player 1 is you and Player 2 is the computer.\n\
3. The game starts by each player placing their ships in different locations on their board.\n\
4. The players then alternate turns \"shooting\" at each others ships by blindly guessing the locations of your opponents ships.\n\
5. The aim of the game is to hit every tile that a ship covers to \"sink\" all their ships.\n\
6. The Aircraft Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.\n\
	These are represented by the symbols A, B, C, S, and D respectively.\n\
7. The first player to sink all of their opponents ships wins!\n\
Press any key to continue...");
}

void initialize_game_board(Cell board[10][10]) {
	//fills the game board with waves
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j].location.column = j;
			board[i][j].location.row = i;
			board[i][j].status = '~';
		}
	}
}

void print_player_board(Cell board[10][10]) {
	// this prints the players game board, where they can see all their ships
	printf("  1 2 3 4 5 6 7 8 9 10\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", i + 1);
		for (int j = 0; j < 10; j++) {
			printf("%c", board[i][j].status);
			printf(" ");
		}
		printf("\n");
	}
}

void print_computer_board(Cell board[10][10]) {
	// this prints the computers play board, which keeps the ships locations hidden
	printf("  1 2 3 4 5 6 7 8 9 10\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", i + 1);
		for (int j = 0; j < 10; j++) {
			if (board[i][j].status == 'H' || board[i][j].status == 'M' || board[i][j].status == '~') { //prints only the hits or the misses, no ships
				printf("%c", board[i][j].status);
			}
			else {
				printf("~");// where there are ships, waves are printed instad
			}
			printf(" ");
		}
		printf("\n");
	}
}

int check_ship_placement(int size, int row, int column, char orientation, Cell board[10][10]) {
	int flag = 0; // If the ship positioning is valid, then this number will math the size of the ship by the end of the function.
	int i = 0;

	if (orientation == 'h' || orientation == 'H') { // the orientation is horizontal
		for (i = 0; i < size; i++) {
			if (row > 9 || column + i > 9) // cuts program off early if the coordinate is out of bounds
				break;
			if (board[row][column + i].status == '~') // makes sure there are no other ships on this space
				flag++;
		}
	}
	else { // the orientation is verticle
		for (i = 0; i < size; i++) {
			if (row + i > 9 || column > 9) // cuts program off early if the coordinate is out of bounds
				break;
			if (board[row + i][column].status == '~') // makes sure there are no other ships on this space
				flag++;
		}

	}

	// returns 1 if all spaces of the ship are valid
	if (flag == size) {
		return 1;
	}
	else {
		return 0;
	}
	
}

void place_player_ships(Cell board[10][10]) {
	printf("Select the placement of your ships!\n\
First you will whether the ship should be placed horizontally or vertically.\n\
Then you will have to select either the leftmost cooardinate or the rightmost coordinate.\n\
If the ship is placed legally then you will have successfully placed you ship!\n\
Press any button to continue...");
	getch();
	char orientation = "";
	int row = 0,
		column = 0,
		i = 0;

	// placing the aircraft carrier
	while ("true") {
		system("cls");
		print_player_board(board);
		printf("\nPlace your Aircraft Carrier(size 5).\n");

		// get orentation of placement
		printf("Horizontal(H) or Verticle(V) orientation: ");
		scanf(" %c", &orientation);

		// get the coordinates of the placement
		printf("Enter coordinates(x y)~no perenthesis!: ");
		scanf("%d%d", &column, &row);
		column--;
		row--;

		// check and place ships if they are legal
		if (check_ship_placement(5, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 5; i++) 
					board[row][column + i].status = 'A';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 5; i++)
					board[row + i][column].status = 'A';
			}
			break;
		}
		else {
			printf("Invalid placement.\n");
			getch();
		}
	}

	// placing the battleship
	while ("true") {
		system("cls");
		print_player_board(board);
		printf("\nPlace your Battleship(size 4).\n");

		// get orentation of placement
		printf("Horizontal(H) or Verticle(V) orientation: ");
		scanf(" %c", &orientation);

		// get the coordinates of the placement
		printf("Coordinate(x y)~no parenthesis~: ");
		scanf("%d%d", &column, &row);
		column--;
		row--;

		// check and place ships if they are legal
		if (check_ship_placement(4, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 4; i++)
					board[row][column + i].status = 'B';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 4; i++)
					board[row + i][column].status = 'B';
			}
			break;
		}
		else {
			printf("Invalid placement.\n");
			getch();
		}
	}

	// placing the cruiser
	while ("true") {
		system("cls");
		print_player_board(board);
		printf("\nPlace your Cruiser(size 3).\n");

		// get orentation of placement
		printf("Horizontal(H) or Verticle(V) orientation: ");
		scanf(" %c", &orientation);

		// get the coordinates of the placement
		printf("Coordinate(x y)~no parenthesis~: ");
		scanf("%d%d", &column, &row);
		column--;
		row--;

		// check and place ships if they are legal
		if (check_ship_placement(3, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 3; i++)
					board[row][column + i].status = 'C';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 3; i++)
					board[row + i][column].status = 'C';
			}
			break;
		}
		else {
			printf("Invalid placement.\n");
			getch();
		}
	}

	// placing the Submarine
	while ("true") {
		system("cls");
		print_player_board(board);
		printf("\nPlace your Submarine(size 3).\n");

		// get orentation of placement
		printf("Horizontal(H) or Verticle(V) orientation: ");
		scanf(" %c", &orientation);

		// get the coordinates of the placement
		printf("Coordinate(x y)~no parenthesis~: ");
		scanf("%d%d", &column, &row);
		column--;
		row--;

		// check and place ships if they are legal
		if (check_ship_placement(3, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 3; i++)
					board[row][column + i].status = 'S';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 3; i++)
					board[row + i][column].status = 'S';
			}
			break;
		}
		else {
			printf("Invalid placement.\n");
			getch();
		}
	}

	// placing the destroyer
	while ("true") {
		system("cls");
		print_player_board(board);
		printf("\nPlace your Destroyer(size 2).\n");

		// get orentation of placement
		printf("Horizontal(H) or Verticle(V) orientation: ");
		scanf(" %c", &orientation);

		// get the coordinates of the placement
		printf("Coordinate(x y)~no parenthesis~: ");
		scanf("%d%d", &column, &row);
		column--;
		row--;

		// check and place ships if they are legal
		if (check_ship_placement(3, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 2; i++)
					board[row][column + i].status = 'D';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 2; i++)
					board[row + i][column].status = 'D';
			}
			break;
		}
		else {
			printf("Invalid placement.\n");
			getch();
		}
	}
}

void place_computer_ships(Cell board[10][10]) {
	int r = rand() % 10 - 1,
		column = 0,
		row = 0;
	char orientation = ' ';
	int i = 0;

	// These ship placements will place the ship randomly, if the placement is invalid
	// the function will try a different random placement until a legal placement is found
	
	//Aircraft carrier
	while ("true") {
		// determine the orientation
		r = rand() % 2 - 1;
		if (r == 0) { // the orientation is horizontal when r is 0
			orientation = 'H';
		}
		else { // orientation is verticle when r is 0;
			orientation = 'V';
		}

		row = rand() % 10;
		column = rand() % 10;

		// check and place ships if they are legal
		if (check_ship_placement(5, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 5; i++)
					board[row][column + i].status = 'A';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 5; i++)
					board[row + i][column].status = 'A';
			}
			break;
		}
	}

	// battleship
	while ("true") {
		// determine the orientation
		r = rand() % 2 - 1;
		if (r == 0) { // the orientation is horizontal when r is 0
			orientation = 'H';
		}
		else { // orientation is verticle when r is 0;
			orientation = 'V';
		}

		row = rand() % 10;
		column = rand() % 10;

		// check and place ships if they are legal
		if (check_ship_placement(4, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 4; i++)
					board[row][column + i].status = 'B';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 4; i++)
					board[row + i][column].status = 'B';
			}
			break;
		}
	}

	// cruiser
	while ("true") {
		// determine the orientation
		r = rand() % 2 - 1;
		if (r == 0) { // the orientation is horizontal when r is 0
			orientation = 'H';
		}
		else { // orientation is verticle when r is 0;
			orientation = 'V';
		}

		row = rand() % 10;
		column = rand() % 10;

		// check and place ships if they are legal
		if (check_ship_placement(3, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 3; i++)
					board[row][column + i].status = 'C';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 3; i++)
					board[row + i][column].status = 'C';
			}
			break;
		}
	}

	// Submarine
	while ("true") {
		// determine the orientation
		r = rand() % 2 - 1;
		if (r == 0) { // the orientation is horizontal when r is 0
			orientation = 'H';
		}
		else { // orientation is verticle when r is 0;
			orientation = 'V';
		}

		row = rand() % 10;
		column = rand() % 10;

		// check and place ships if they are legal
		if (check_ship_placement(3, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 3; i++)
					board[row][column + i].status = 'S';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 3; i++)
					board[row + i][column].status = 'S';
			}
			break;
		}
	}

	//Destroyer
	while ("true") {
		// determine the orientation
		r = rand() % 2 - 1;
		if (r == 0) { // the orientation is horizontal when r is 0
			orientation = 'H';
		}
		else { // orientation is verticle when r is 0;
			orientation = 'V';
		}

		row = rand() % 10;
		column = rand() % 10;

		// check and place ships if they are legal
		if (check_ship_placement(2, row, column, orientation, board) == 1) {
			if (orientation == 'H' || orientation == 'h') {
				for (i = 0; i < 2; i++)
					board[row][column + i].status = 'D';
			}
			else { // if the orientation is verticle
				for (i = 0; i < 2; i++)
					board[row + i][column].status = 'D';
			}
			break;
		}
	}
}

int select_turn_order() {
	int r = rand() % 2;
	return r;
}

int check_shot(Cell board[10][10], int y, int x) {
	if (board[x][y].status == '~') {
		board[x][y].status = 'M';
		return 0; // miss
	}
	else if (board[x][y].status == 'H' || board[x][y].status == 'M' || x > 10 || y > 10) {
		printf("Invalid shot.\n");
		return 2; // invalid shot
	}
	else { // the only statuses not accounted for are ships, so if the shot hit a ship
		board[x][y].status = 'H';
		return 1;
	}
}

void check_for_sinks(Cell board[10][10], int *aircraft, int *battleship, int *cruiser, int * submarine, int * destroyer) {
	int a = 0, b = 0, c = 0,
		s = 0, d = 0;

	// add up what is left of each of the ships
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j].status == 'A') {
				a++;
			}
			else if (board[i][j].status == 'B') {
				b++;
			}
			else if (board[i][j].status == 'C') {
				c++;
			}
			else if (board[i][j].status == 'S') {
				s++;
			}
			else if (board[i][j].status == 'D') {
				d++;
			}
		}
	}

	// determine if a ship has no place left on the board, if it has and hasnt sunk yet, record and display the sink
	if (a == 0 && *aircraft != 1) {
		printf("The Aircraft Carrier has sunk!\n");
		*aircraft = 1;
	}
	else if (b == 0 && *battleship != 1) {
		printf("The Battleship has sunk!\n");
		*battleship = 1;
	}
	else if (c == 0 && *cruiser != 1) {
		printf("The Cruiser has sunk!\n");
		*cruiser = 1;
	}
	else if (s == 0 && *submarine != 1) {
		printf("The Submarine has sunk!\n");
		*submarine = 1;
	}
	else if (d == 0 && *destroyer != 1) {
		printf("The Destroyer has sunk!\n");
		*destroyer = 1;
	}
}

int check_for_win(int aircraft, int battleship, int cruiser, int submarine, int destroyer, Cell board[10][10]) {
	int a_number = 0, b_number = 0, c_number = 0, s_number = 0, d_number = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j].status == 'A') 
				a_number++;
			else if (board[i][j].status == 'B') 
					b_number++;
			else if (board[i][j].status == 'C')
				c_number++;
			else if (board[i][j].status == 'S')
				s_number++;
			else if (board[i][j].status == 'D')
				d_number++;
		}
	}

	if (aircraft == 0 && a_number == 0) { // returns a number based off what sunk
		printf("The Aircraft Carrier has been sunk!\n");
		return 1;
	}
	else if (battleship == 0 && b_number == 0) {
		printf("The Battleship has been sunk!\n");
		return 2;
	}
	else if (cruiser == 0 && c_number == 0) {
		printf("The Cruiser has been sunk!\n");
		return 3;
	}
	else if (submarine == 0 && s_number == 0) {
		printf("The Submarine has been sunk!\n");
		return 4;
	}
	else if (destroyer == 0 && d_number == 0) {
		printf("The Destroyer has been sunk!\n");
		return 5;
	}
	else { // no ships were sunk
		return 0;
	}
}