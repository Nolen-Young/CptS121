#include "pa7.h"

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], int hand_suits[], int hand_faces[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = 1; card <= 5; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card )
				{
					hand_suits[card - 1] = row;
					hand_faces[card - 1] = column;
				}
			}
		}
	}
}

void display_hand(const char *wFace[], const char *wSuit[], int hand_suits[], int hand_faces[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d. %5s of %-8s%c", i + 1, wFace[hand_faces[i]], wSuit[hand_suits[i]], i % 2 == 1 ? '\n' : '\t');
	}
}


int pair(char *wFace[], int hand_faces[]) {
	int j = 0;
	for (int i = 0; i < 4; i++) { // only have to compare first 4 cards of hand
		for (int j = i + 1; j < 5; j++) {
			if (hand_faces[i] == hand_faces[j]) {
				printf("\n\nPair of %s\n", wFace[hand_faces[i]]);
				return 14 + hand_faces[i]; // if there was a pair
			}
		}
	}
	return 0; // if there wasn't a pair
}

int two_pair(const char *wFace[], int hand_faces[]) {
	int j = 0,
		flag = -1;
	for (int i = 0; i < 4; i++) { // only have to compare first 4 cards of hand
		for (int j = i + 1; j < 5; j++) {
			if (flag != -1 && hand_faces[i] == hand_faces[j]) {
				printf("\nTwo pairs of %s and %s\n", wFace[hand_faces[flag]], wFace[hand_faces[i]]);
				return 2; // if there was two pairs
			}
			else if (hand_faces[i] == hand_faces[j]) {
				flag == 28 + hand_faces[i];
			}
		}
	}
	return 0; // if there wasn't a pair
}

int three_of_a_kind(const char *wFace[], int hand_faces[]) {
	int j = 0,
		flag1 = -1,
		flag2 = -1;
	for (int i = 0; i < 4; i++) { // only have to compare first 4 cards of hand
		for (int j = i + 1; j < 5; j++) {
			if (flag1 != -1 && flag2 != -1 && hand_faces[i] == hand_faces[j]) {
				printf("\nThree of a kind of %s\n", wFace[hand_faces[i]]);
				return 42 + hand_faces[i]; // if there was two pairs
			}
			else if (flag1 != -1 && hand_faces[i] == hand_faces[j]) {
				flag2 = hand_faces[i];
			}
			else if (hand_faces[i] == hand_faces[j]) {
				flag1 = hand_faces[i];
			}
		}
	}
	return 0; // if there wasn't a pair
}

int four_of_a_kind(const char *wFace[], int hand_faces[]) {
	int j = 0,
		flag1 = -1,
		flag2 = -1,
		flag3 = -1;
	for (int i = 0; i < 4; i++) { // only have to compare first 4 cards of hand
		for (int j = i + 1; j < 5; j++) {
			if (flag1 != -1 && flag2 != -1 && flag3 != -1 && hand_faces[i] == hand_faces[j]) {
				printf("\nFour of a kind of %s\n", wFace[hand_faces[i]]);
				return 56 + hand_faces[i];; // if there wasfour of a kind
			}
			else if (flag1 != -1 && flag2 != -1 && hand_faces[i] == hand_faces[j]) {
				flag3 = hand_faces[i];
			}
			else if (flag1 != -1 && hand_faces[i] == hand_faces[j]) {
				flag2 = hand_faces[i];
			}
			else if (hand_faces[i] == hand_faces[j]) {
				flag1 = hand_faces[i];
			}
		}
	}
	return 0; // if there wasn't a pair
}

int flush(const char * wSuit[], int hand_suits[]) {
	int flag = 0;
	flag = hand_suits[0];
	for (int i = 1; i < 5; i++) { // only have to compare first 4 cards of hand
		if (flag != hand_suits[i]) {
			return 0;
		}
	}
	printf("A flush of %s", wSuit[hand_suits[flag]]);
	return 70; // if there wasn't a pair
}

int straight(const char * wFace[], int hand_faces[]) {
	int flag = 0;
	int i = 0;
	qsort(hand_faces, 5, sizeof(int), cmpfunc); // sorts the function into ascending order 
	for (i = 0; i < 4; i++) {
		if (hand_faces[i] != hand_faces[i + 1]) {
			return 0;
		}
	}
	return 84 + hand_faces[i + 1];
}

int cmpfunc(const void * a, const void * b) // this is the comparison function for qsort
{
	return (*(int*)a - *(int*)b);
}

int check_hand(const char *wFace[], const char *wSuit[], int hand_suits[], int hand_faces[]) {
	int flag = 0;

	if (flag == 0) {
		flag = straight(wFace, hand_faces); // test for straight
	}
	if (flag == 0) {
		flag = flush(wSuit, hand_suits); // test for flush
	}
	if (flag == 0) {
		flag = four_of_a_kind(wFace, hand_faces); // test for four of a kind
	}
	if (flag == 0) {
		flag = three_of_a_kind(wFace, hand_faces); // test for three of a kind
	}
	if (flag == 0) {
		flag = two_pair(wFace, hand_faces); // test for two pair
	}
	if (flag == 0) {
		flag = pair(wFace, hand_faces); // test for pair
	}
	if (flag == 0) {
		qsort(hand_faces, 5, sizeof(int), cmpfunc);
		flag = hand_faces[4];
	}

	return flag;
}