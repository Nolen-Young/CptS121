// Nolen Young
// 2-24-17
// Desciption: This program plays through a game of craps for as long as the player wants
//			   or until the player runs out of money and can no longer betfjop

#include "pa4.h"

int main(void)
{
	int die1 = 0, die2 = 0, sum = 0,
		win_loss_or_point = 0, point = 0,
		number_rolls = 0;
	double initial_bank_balance = 0.0, wager = 0.0,
		current_bank_balance = 0.0;

	srand((unsigned int)time(NULL));

	print_game_rules();
	initial_bank_balance = get_bank_balance();
	current_bank_balance = initial_bank_balance;

	while ('true') { //this loop will run until a break is reached
		number_rolls = 0;
		chatter_messages(number_rolls, win_loss_or_point, initial_bank_balance, current_bank_balance);
		wager = get_wager_amount();
		if (wager < 0) {
			printf("Thanks for playing!\n");
			printf("Bank balance: $%.2lf\n", current_bank_balance);
			break;
		}
		else if (check_wager_amount(wager, current_bank_balance) == 0) { // makes sure the wager is valid before continueing the game
			printf("Press enter to roll the first die.\n");
			getch(); // this waits until the user presses a button to continue the program
			die1 = roll_die();
			printf("%d\n", die1);
			printf("Press enter to roll the second die.\n");
			getch();
			die2 = roll_die();
			printf("%d\n", die2);
			sum = sum_dice(die1, die2);
			printf("Total roll: %d\n", sum);
			
			win_loss_or_point = is_win_loss_or_point(sum);
			if (win_loss_or_point == 1) {
				printf("Winner!");
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 1);
			}
			else if (win_loss_or_point == 0) {
				printf("Sorry, you lost!\n");
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 0);
			}
			else { // if there is a "point"
				point = sum;
				printf("Point! Your point is %d.\n\n", point);

				while ("true") {
					number_rolls++;
					printf("Press enter to roll the first die.\n");
					getch(); // this waits until the user presses a button to continue the program
					die1 = roll_die();
					printf("%d\n", die1);
					printf("Press enter to roll the second die.\n");
					getch();
					die2 = roll_die();
					printf("%d\n", die2);
					sum = sum_dice(die1, die2);
					printf("Total roll: %d\n", sum);
					

					if (is_point_loss_or_neither(sum, point) == 1) {
						printf("Point! Winner!\n");
						current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 1);
						break;
					}
					else if (is_point_loss_or_neither(sum, point) == 0) {
						printf("7! Loser!\n");
						current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 0);
						break;
					}
					chatter_messages(number_rolls, win_loss_or_point, initial_bank_balance, current_bank_balance);
					printf("\n");
					
				}
			}
		}
		else { // check_wager returned 1
			printf("Illegal wager!\n");
		}
		
		printf("Bank balance: $%.2lf\n\n", current_bank_balance);
	}

	return 0;
}