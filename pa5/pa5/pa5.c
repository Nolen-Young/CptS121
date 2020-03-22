#include "pa5.h"

void print_rules(void) {
	printf("Welcome to Yahtzee!\n\
The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n\
A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. \n\
The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. \n\
If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. \n\
Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. \n\
If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. \n\
The lower section contains a number of poker like combinations. Their combinations and points are listed below:\n\
3 Of A Kind - Sum of all values on the dice\n\
4 Of A Kind - Sum of all values on the dice\n\
Full House - 25 points\n\
Small Straight - 30 points\n\
Large Straight - 35 points\n\
Yahtzee (5 of a kind) - 50 points\n\
Chance (Any combination of dice) - Sum of all values on the dice\n\n");
}

int menu(void) {
	int selection = 0;
	while ("true") {
		printf("1. Print game rules\n\
2. Play Game\n\
3. Exit\n\
>");
		scanf("%d", &selection);
		system("cls");
		if (selection == 1 || selection == 2 || selection == 3) {
			break;
		}
		else {
			printf("Invalid input\n");
		}
	}
	return selection;
}

int roll_die(void) {
	return (rand() % 6) + 1;
}

int roll_dice(int * die1, int * die2, int * die3, int * die4, int * die5) {
	*die1 = roll_die();
	*die2 = roll_die();
	*die3 = roll_die();
	*die4 = roll_die();
	*die5 = roll_die();
}

void print_dice(int die1, int die2, int die3, int die4, int die5) {
	printf("Die 1: %d\n\
Die 2: %d\n\
Die 3: %d\n\
Die 4: %d\n\
Die 5: %d\n", die1, die2, die3, die4, die5);
}

void print_scoreboard(int upper[], int lower[]) {
	printf("\nUpper scoreboard:\n\
1. 1's: %d\n\
2. 2's: %d\n\
3. 3's: %d\n\
4. 4's: %d\n\
5. 5's: %d\n\
6. 6's: %d\n\
Lower scoreboard:\n\
7. Three of a kind: %d\n\
8. Four of a kind: %d\n\
9. Full house: %d\n\
10. Small straight: %d\n\
11. Large strage: %d\n\
12. Yahtzee: %d\n\
13. Chance: %d\n\n", upper[0], upper[1], upper[2], upper[3], upper[4], upper[5],
lower[0], lower[1], lower[2], lower[3], lower[4], lower[5], lower[6]);
}

int score_upper(int die1, int die2, int die3, int die4, int die5, int num) {
	int total = 0; 
	if (die1 == num) {
		total += num;
	}
	if (die2 == num) {
		total += num;
	}
	if (die3 == num) {
		total += num;
	}
	if (die4 == num) {
		total += num;
	}
	if (die5 == num) {
		total += num;
	}
	return total;
}

int three_of_a_kind(int die1, int die2, int die3, int die4, int die5, int num) {
	int temp = 0;
	if (die1 == num) {
		temp++;
	}
	if (die2 == num) {
		temp++;
	}
	if (die3 == num) {
		temp++;
	}
	if (die4 == num) {
		temp++;
	}
	if (die5 == num) {
		temp++;
	}
	if (temp == 3) {
		return die1 + die2 + die3 + die4 + die5;
	}
}

int four_of_a_kind(int die1, int die2, int die3, int die4, int die5, int num) {
	int temp = 0;
	if (die1 == num) {
		temp++;
	}
	if (die2 == num) {
		temp++;
	}
	if (die3 == num) {
		temp++;
	}
	if (die4 == num) {
		temp++;
	}
	if (die5 == num) {
		temp++;
	}
	if (temp == 3) {
		return die1 + die2 + die3 + die4 + die5;
	}
}

int full_house(int die1, int die2, int die3, int die4, int die5, int high, int low) {
	int high_count = 0,
		low_count = 0;
	// check for highs
	if (die1 == high) {
		high_count++;
	}
	if (die1 == high) {
		high_count++;
	}
	if (die1 == high) {
		high_count++;
	}
	if (die1 == high) {
		high_count++;
	}
	if (die1 == high) {
		high_count++;
	}

	//check for lows
	if (die1 == low) {
		low_count++;
	}
	if (die1 == low) {
		low_count++;
	}
	if (die1 == low) {
		low_count++;
	}
	if (die1 == low) {
		low_count++;
	}
	if (die1 == low) {
		low_count++;
	}

	if (high_count == 3 && low_count == 2) {
		return 25;
	}
	else {
		return 0;
	}
}

int lower_straight(int die1, int die2, int die3, int die4, int die5, int num) {
	int check1 = 0,
		check2 = 0,
		check3 = 0;

	// check for next number
	if (die1 == num + 1) {
		check1 = 1;
	}
	else if (die2 == num + 1) {
		check1 = 1;
	}
	else if (die3 == num + 1) {
		check1 = 1;
	}
	else if (die4 == num + 1) {
		check1 = 1;
	}
	else if (die5 == num + 1) {
		check1 = 1;
	}

	// check for next number
	if (die1 == num + 2) {
		check2 = 1;
	}
	else if (die2 == num + 2) {
		check2 = 1;
	}
	else if (die3 == num + 2) {
		check2 = 1;
	}
	else if (die4 == num + 2) {
		check2 = 1;
	}
	else if (die5 == num + 2) {
		check2 = 1;
	}

	if (die1 == num + 3) {
		check3 = 1;
	}
	else if (die2 == num + 3) {
		check3 = 1;
	}
	else if (die3 == num + 3) {
		check3 = 1;
	}
	else if (die4 == num + 3) {
		check3 = 1;
	}
	else if (die5 == num + 3) {
		check3 = 1;
	}



	if (check1 + check2 + check3 == 3) {
		return 30;
	}
	else {
		return 0;
	}
}

int upper_straight(int die1, int die2, int die3, int die4, int die5, int num) {
	int check1 = 0,
		check2 = 0,
		check3 = 0,
		check4 = 0;

	// check for next number
	if (die1 == num + 1) {
		check1 = 1;
	}
	else if (die2 == num + 1) {
		check1 = 1;
	}
	else if (die3 == num + 1) {
		check1 = 1;
	}
	else if (die4 == num + 1) {
		check1 = 1;
	}
	else if (die5 == num + 1) {
		check1 = 1;
	}

	// check for next number
	if (die1 == num + 2) {
		check2 = 1;
	}
	else if (die2 == num + 2) {
		check2 = 1;
	}
	else if (die3 == num + 2) {
		check2 = 1;
	}
	else if (die4 == num + 2) {
		check2 = 1;
	}
	else if (die5 == num + 2) {
		check2 = 1;
	}

	if (die1 == num + 3) {
		check3 = 1;
	}
	else if (die2 == num + 3) {
		check3 = 1;
	}
	else if (die3 == num + 3) {
		check3 = 1;
	}
	else if (die4 == num + 3) {
		check3 = 1;
	}
	else if (die5 == num + 3) {
		check3 = 1;
	}

	if (die1 == num + 4) {
		check4 = 1;
	}
	else if (die2 == num + 4) {
		check4 = 1;
	}
	else if (die3 == num + 4) {
		check4 = 1;
	}
	else if (die4 == num + 4) {
		check4 = 1;
	}
	else if (die5 == num + 4) {
		check4 = 1;
	}



	if (check1 + check2 + check3 + check4 == 4) {
		return 40;
	}
	else {
		return 0;
	}
}

int yahtzee(int die1, int die2, int die3, int die4, int die5) {
	if (die1 == die2 && die2 == die3 && die3 == die4 && die4 == die5) {
		return 50;
	}
	else {
		return 0;
	}
}

int chance(int die1, int die2, int die3, int die4, int die5) {
	return die1 + die2 + die3 + die4 + die5;
}

int calculate_score(int upper[], int lower[]) {
	int total = 0;
	for (int i = 0; i < 6; i++) {
		total += upper[i];
	}
	if (total >= 63) {
		total += 35;
	}
	for (int j = 0; j < 7; j++) {
		total += lower[j];
	}
	return total;
}

