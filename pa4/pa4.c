#include "pa4.h"

int roll_die(void)
{
	int die = 0;

	die = rand() % 6 + 1;

	return die;
}

int sum_dice(int die1, int die2)
{
	int sum = 0;

	sum = die1 + die2;

	return sum;
}

void print_game_rules(void){
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. \n\
After the dice have come to rest, the sum of the spots on the two upward faces is calculated. \n\
If the sum is 7 or 11 on the first throw, the player wins. \n\
If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins). \n\
If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\" \n\
To win, you must continue rolling the dice until you \"make your point.\" \n\
The player loses by rolling a 7 before making the point.\n\
Entering a negative wager at the starting wager of a round will quit the game.\n\n");
}

double get_bank_balance(void) {
	double bank = 0.0;

	printf("Enter starting bank: $");
	scanf("%lf", &bank);
	
	return bank;
}

double get_wager_amount(void) {
	double wager = 0.0;

	printf("Enter wager: $");
	scanf("%lf", &wager);

	return wager;
}

int check_wager_amount(double wager, double balance) {
	if (wager <= balance) {
		return 0;
	}
	else {
		return 1;
	}
}

int is_win_loss_or_point(int sum_dice) {
	if (sum_dice == 7 || sum_dice == 11) {
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
		return 0;
	}
	else {
		return -1;
	}
}

int is_point_loss_or_neither(int sum_dice, int point_value) {
	if (sum_dice == point_value) {
		return 1;
	}
	else if (sum_dice == 7) {
		return 0;
	}
	else {
		return -1;
	}
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	double new_bank_balance = 0.0;
	if (add_or_subtract == 1) {
		new_bank_balance = wager_amount + bank_balance;
	}
	else if (add_or_subtract == 0) {
		new_bank_balance = bank_balance - wager_amount;
	}
	return new_bank_balance;
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	if (number_rolls == 0) { // basically checks to see where the program is being executed
		if (initial_bank_balance > current_bank_balance) {
			printf("Keep playing to win back your money!\n");
		}
		else if (initial_bank_balance < current_bank_balance) {
			printf("You are up, maybe you should quit while your ahead.\n");
		}
	}
	else {
		if (number_rolls > 5) {
			printf("This is taking awhile...\n");
		}
		if (win_loss_neither == -1) {
			printf("Roll again.\n");
		}
	}
}
