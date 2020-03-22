/*
Nolen Young
3-13-17
PA5
This program is extremely poorly made and very rushed
The purpose of this program is to play games of yahtzee between two players
*/



#include "pa5.h"

int main(void) {
	int menu_selection = 0, score_selection = 0,
		die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0, // this should have been an array but im dumb
		rounds = 0,
		reroll = 0,
		turn_rolls = 0,
		round_number = 1,
		player_turn = 1,
		number_to_score = 0,
		high = 0, low = 0,
		player1_score = 0, player2_score = 0,
		player1_upper[6] = { 0 }, player1_lower[7] = { 0 },
		player2_upper[6] = { 0 }, player2_lower[7] = { 0 };
		char roll_selection = " ";

	srand((unsigned int)time(NULL));
			
	while ("true") {
		menu_selection = menu();
		if (menu_selection == 1) { // print instructions
			print_rules();
		}
		else if (menu_selection == 2) {// play the game
			while ("true") {
				printf("Player %d's turn\n", player_turn);


				printf("Press any key to roll...\n"); // THE MOST POWERFUL DICE ROLLING ENGINE
				getch(); // waits for player to roll
				roll_dice(&die1, &die2, &die3, &die4, &die5);
				turn_rolls++;
				print_dice(die1, die2, die3, die4, die5);

				if (turn_rolls < 3) {
					printf("Would you like to score this roll (y/n)? ");
					scanf(" %c", &roll_selection);

					if (roll_selection == (char)'y' || roll_selection == (char)'Y') {
						break;
					}
					else {
						for (int i = 0; i < 3; i++) {
							printf("Which die would you like to reroll(0 to score roll)? ");
							scanf("%d", &reroll);
							if (reroll == 1) {
								die1 = roll_die();
							}
							else if (reroll == 2) {
								die2 = roll_die();
							}
							else if (reroll == 3) {
								die3 = roll_die();
							}
							else if (reroll == 4) {
								die4 = roll_die();
							}
							else if (reroll == 5) {
								die5 = roll_die();
							}
							else {
								break;
							}
						}
					}
				}
				else {
					break;
				}


				if (player_turn == 1) {
					print_scoreboard(player1_upper, player1_lower);
				}
				else { // player 2's turn
					print_scoreboard(player2_upper, player2_lower);
				}

				//scoring logic block//////////////////////////////////////////////////////////////////////
				while ("true") {
					printf("Which would you like to score? ");
					scanf("%d", &score_selection);
					if (score_selection <= 6) { // upper scoreboard
						score_selection = score_selection - 1;
						if (score_selection == 0 && (player1_upper[0] == 0 || player2_upper[0] == 0)) { // this checks if this scoring slot has been picked and if the player has not scored that box yet
							if (player_turn == 1) {
								player1_upper[0] = score_upper(die1, die2, die3, die4, die5, 1);
							}
							else { // player 2
								player2_upper[0] = score_upper(die1, die2, die3, die4, die5, 1);
							}
							break;
						}
						else if (score_selection == 1 && (player1_upper[1] == 0 || player2_upper[1] == 0)) {
							if (player_turn == 1) {
								player1_upper[1] = score_upper(die1, die2, die3, die4, die5, 2);
							}
							else { // player 2
								player2_upper[1] = score_upper(die1, die2, die3, die4, die5, 2);
							}
							break;
						}
						else if (score_selection == 2 && (player1_upper[2] == 0 || player2_upper[2] == 0)) {
							if (player_turn == 1) {
								player1_upper[2] = score_upper(die1, die2, die3, die4, die5, 3);
							}
							else { // player 2
								player2_upper[2] = score_upper(die1, die2, die3, die4, die5, 3);
							}
							break;
						}
						else if (score_selection == 3 && (player1_upper[3] == 0 || player2_upper[3] == 0)) {
							if (player_turn == 1) {
								player1_upper[3] = score_upper(die1, die2, die3, die4, die5, 4);
							}
							else { // player 2
								player2_upper[3] = score_upper(die1, die2, die3, die4, die5, 4);
							}
							break;
						}
						else if (score_selection == 4 && (player1_upper[4] == 0 || player2_upper[4] == 0)) {
							if (player_turn == 1) {
								player1_upper[4] = score_upper(die1, die2, die3, die4, die5, 5);
							}
							else { // player 2
								player2_upper[4] = score_upper(die1, die2, die3, die4, die5, 5);
							}
							break;
						}
						else if (score_selection == 5 && (player1_upper[5] == 0 || player2_upper[5] == 0)) {
							if (player_turn == 1) {
								player1_upper[5] = score_upper(die1, die2, die3, die4, die5, 4);
							}
							else { // player 2
								player2_upper[5] = score_upper(die1, die2, die3, die4, die5, 4);
							}
							break;
						}
						else {
							printf("Invalid selection\n");
						}
					}
					else { // lower scoreboard
						score_selection = score_selection - 7;
						if (score_selection == 0 && (player1_lower[0] == 0 || player2_lower[0] == 0)) {
							printf("which number would you like to score? ");
							scanf("%d", &number_to_score);
							if (player_turn == 1) {
								player1_lower[0] = three_of_a_kind(die1, die2, die3, die4, die5, number_to_score);
							}
							else { // player 2
								player2_lower[0] = three_of_a_kind(die1, die2, die3, die4, die5, number_to_score);
							}
							break;
						}
						else if (score_selection == 1 && (player1_lower[1] == 0 || player2_lower[1] == 0)) {
							printf("which number would you like to score? ");
							scanf("%d", &number_to_score);
							if (player_turn == 1) {
								player1_lower[1] = four_of_a_kind(die1, die2, die3, die4, die5, number_to_score);
							}
							else { // player 2
								player2_lower[1] = four_of_a_kind(die1, die2, die3, die4, die5, number_to_score);
							}
							break;
						}
						else if (score_selection == 2 && (player1_lower[2] == 0 || player2_lower[2] == 0)) {
							printf("What is the high number? ");
							scanf("%d", &high);
							printf("What is the low number? ");
							scanf("%d", &low);
							if (player_turn == 1) {
								player1_lower[2] = full_house(die1, die2, die3, die4, die5, high, low);
							}
							else { // player 2
								player2_lower[2] = full_house(die1, die2, die3, die4, die5, high, low);
							}
							break;
						}
						else if (score_selection == 3 && (player1_lower[3] == 0 || player2_lower[3] == 0)) {
							printf("What is the starting number? ");
							scanf("%d", &number_to_score);
							if (player_turn == 1) {
								player1_lower[3] = lower_straight(die1, die2, die3, die4, die5, number_to_score);
							}
							else { // player 2
								player2_lower[3] = lower_straight(die1, die2, die3, die4, die5, number_to_score);
							}
							break;
						}
						else if (score_selection == 4 && (player1_lower[4] == 0 || player2_lower[4] == 0)) {
							printf("What is the starting number? ");
							scanf("%d", &number_to_score);
							if (player_turn == 1) {
								player1_lower[4] = upper_straight(die1, die2, die3, die4, die5, number_to_score);
							}
							else { // player 2
								player2_lower[4] = upper_straight(die1, die2, die3, die4, die5, number_to_score);
							}
							break;
						}
						else if (score_selection == 5 && (player1_lower[5] == 0 || player2_lower[5] == 0)) {
							if (player_turn == 1) {
								player1_lower[5] = yahtzee(die1, die2, die3, die4, die5);
							}
							else { // player 2
								player2_lower[5] = yahtzee(die1, die2, die3, die4, die5);
							}
							break;
						}
						else if (score_selection == 6 && (player1_lower[6] == 0 || player2_lower[6] == 0)) {
							if (player_turn == 1) {
								player1_lower[6] = chance(die1, die2, die3, die4, die5);
							}
							else { // player 2
								player2_lower[6] = chance(die1, die2, die3, die4, die5);
							}
							break;
						}
						else {
							printf("Invalid selection\n");
						}
					}
				}

				if (player_turn == 1) { // switches who's turn it is
					player_turn = 2;
				}
				else { // player_turn = 2
					rounds++;
					player_turn = 1;
				}
				turn_rolls = 0;
				system("cls");
				if (rounds == 14) {
					player1_score = calculate_score(player1_upper, player1_lower);
					player2_score = calculate_score( player2_upper, player2_lower );
					if (player1_score > player2_score) {
						printf("Player 1 wins!\n");
					}
					else {
						printf("Player 2 wins!\n");
					}
					break;
				}
			}
		}
		else if (menu_selection == 3) { // exit the game
			printf("Thanks for playing!\n");
			break;
		}
	}
}