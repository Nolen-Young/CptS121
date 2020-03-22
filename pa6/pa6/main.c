#include "pa6.h"

int main(void) {
	//sets the game boards up
	Cell player_board[10][10];
	Cell computer_board[10][10];
	initialize_game_board(player_board);
	initialize_game_board(computer_board);
	srand(time(NULL));
	int r = rand() % 10,
		turn_selector = 0,
		shot_column = 0,
		shot_row = 0,
		hit_or_miss_flag = 2,// this is a 0 if there was a miss or a 1 if there was a hit
		player_aircraft = 0, computer_aircraft = 0, // these will be set to 1 once this ship sinks ----put in function?----
		player_battleship = 0, computer_battleship = 0,
		player_cruiser = 0, computer_cruiser = 0,
		player_submarine = 0, computer_submarine = 0,
		player_destroyer = 0, computer_destroyer = 0,
		win_check = 0;
	FILE *infile;
	infile = fopen("battleship.log", "w");

	// Welcome screen and instructions
	welcome_screen(); 
	getch();
	system("cls");

	// ship placement algorithms
	place_player_ships(player_board);
	system("cls");
	place_computer_ships(computer_board);
	printf("Computer is placing ships...\n");
	Sleep(3000);
	
	
	printf("Selecting who goes first...\n");
	turn_selector = select_turn_order();
	Sleep(3000);

	if (turn_selector == 0) {
		printf("You go first!\n");
	}
	else {
		printf("The computer goes first!\n");
	}
	printf("Press any key to continue...\n");
	getch();

	// ***the main game loop***
	while ("true") {
		system("cls");
		// prints out the two gameboards the player can see
		printf("Computer's board: \n");
		print_player_board(computer_board);
		printf("\nYour board: \n");
		print_player_board(player_board);

		// gets the move of the player who is going
		if (turn_selector == 0) { // its the players turn
			while (hit_or_miss_flag == 2) {
				printf("Enter your shot(x y)~no perenthesis~: ");
				scanf("%d%d", &shot_column, &shot_row);
				shot_column--;
				shot_row--;
				
				hit_or_miss_flag = check_shot(computer_board, shot_column, shot_row);
			} 

			printf("Shooting...\n");
			Sleep(3000);
		}
		else { // its the computer's turn
			printf("The computer is choosing where to shoot...\n");
			Sleep(2000);
			while (hit_or_miss_flag == 2) {
				shot_column = rand() % 10; // randomly 
				shot_row = rand() % 10;

				hit_or_miss_flag = check_shot(player_board, shot_column, shot_row);
			} 
			printf("The computer shoots at (%d, %d).\n", shot_column + 1 , shot_row + 1);
			Sleep(1000);
		}
		

		// display a hit or miss to the player
		if (hit_or_miss_flag == 1) { // hit
			printf("It's a hit!\n");

		}
		else if (hit_or_miss_flag == 0) { // miss
			printf("It missed.\n");
		}

		if (turn_selector == 0) {
			fprintf(infile, "The player shot at (%d, %d) and it was a %d(1 is a hit, 0 is a miss)\n", shot_column, shot_row, hit_or_miss_flag);
		} 
		else { 
			fprintf(infile, "The computer shot at (%d, %d) and it was a %d(1 is a hit, 0 is a miss)\n", shot_column, shot_row, hit_or_miss_flag);
		}
		hit_or_miss_flag = 2;

		// check for sunken ships
		if (turn_selector == 0) { // player's turn
			check_for_sinks(player_board, &player_aircraft, &player_battleship, &player_cruiser, &player_submarine, &player_destroyer);
		}
		else { // computer's turn
			check_for_sinks(computer_board, &computer_aircraft, &computer_battleship, &computer_cruiser, &computer_submarine, &computer_destroyer);
		}

		//check for a win
		if (turn_selector == 0) { // players turn
			win_check = check_for_win(computer_aircraft, computer_battleship, computer_cruiser, computer_submarine, computer_destroyer, computer_board);
			if (win_check == 1) {// sets the sunk flag if there was a sunk ship
				computer_aircraft = 1;
				fprintf(infile, "The computer Aircraft carrier was sunk\n");
			}
			else if (win_check == 2) {
				computer_battleship = 1;
				fprintf(infile, "The computer Battleship was sunk\n");
			}
			else if (win_check == 3) {
				computer_cruiser = 1;
				fprintf(infile, "The computer Cruiser was sunk\n");
			}
			else if (win_check == 4) {
				computer_submarine = 1;
				fprintf(infile, "The computer Submarine carrier was sunk\n");
			}
			else if (win_check == 5) {
				computer_destroyer = 1;
				fprintf(infile, "The computer Destroyer carrier was sunk\n");
			}

			//check for win
			if (computer_aircraft == 1 && computer_battleship == 1 && computer_cruiser == 1 && computer_submarine == 1 && computer_destroyer == 1) {
				printf("You win!\n");
				fprintf(infile, "The player won\n");
				break;
			}
		}
		else { // computers turn
			win_check = check_for_win(player_aircraft, player_battleship, player_cruiser, player_submarine, player_destroyer, player_board);
			if (win_check == 1) {// sets the sunk flag if there was a sunk ship
				player_aircraft = 1;
				fprintf(infile, "The Player Aircraft carrier was sunk\n");
			}
			else if (win_check == 2) {
				player_battleship = 1;
				fprintf(infile, "The player Battleship was sunk\n");
			}
			else if (win_check == 3) {
				player_cruiser = 1;
				fprintf(infile, "The player Cruiser was sunk\n");
			}
			else if (win_check == 4) {
				player_submarine = 1;
				fprintf(infile, "The player Submarine was sunk\n");
			}
			else if (win_check == 5) {
				player_destroyer = 1;
				fprintf(infile, "The player Destroyer was sunk\n");
			}

			// check for win
			if (player_aircraft == 1 && player_battleship == 1 && player_cruiser == 1 && player_submarine == 1 && player_destroyer == 1) {
				printf("The computer wins!\n");
				fprintf(infile, "The computer won\n");
				break;
			}
		}

		win_check = 0;

		//switch turns
		if (turn_selector == 0) 
			turn_selector = 1;
		else 
			turn_selector = 0;

		printf("Press enter to switch turns...");
		getch();
	}
}