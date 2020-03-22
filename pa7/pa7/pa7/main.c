#include "pa7.h"

int main(void)
{
	int flag_player = 0,
		flag_dealer = 0,
		menu_selection = 0,
		temp = 0;

	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	
	

	//These arrays keep track of the hands
	int player_hand_suits[5] = { 0 },
		player_hand_faces[5] = { 0 },
		dealer_hand_suits[5] = { 0 },
		dealer_hand_faces[5] = { 0 };



	while ("true") {
		/* initalize deck array */
		int deck[4][13] = { 0 };
		int	deck2[4][13] = { 0 };
		srand((unsigned)time(NULL)); /* seed random-number generator */
		shuffle(deck);
		shuffle(deck2);

		system("cls");
		menu_selection = 0;

		// need two decks because otherwise the deal function produces two identical hands for some reason. I didnt write that function
		deal(deck, face, suit, player_hand_suits, player_hand_faces);
		deal(deck2, face, suit, dealer_hand_suits, dealer_hand_faces);

		

		// checking the players hand
		

		for (int i = 0; i < 3; i ++) {
			system("cls");
			display_hand(face, suit, player_hand_suits, player_hand_faces);
			flag_player = check_hand(face, suit, player_hand_suits, player_hand_faces);
			printf("\nWhich card would you like to change(0 to keep hand)? ");
			scanf("%d", &menu_selection);
			if (menu_selection <= 0) {
				break;
			}
			player_hand_suits[menu_selection - 1] = rand() % 4;
			player_hand_faces[menu_selection - 1] = rand() % 13;
		}

		printf("Press any key to reveal hands...\n");
		getch();
		printf("\n\n");
		
		// dealer AI to figure out what to discard.
		for (int i = 0; i < 3; i++) {
			flag_dealer = check_hand(face, suit, dealer_hand_suits, dealer_hand_faces);
			if (flag_dealer <= 14) {
				for (int j = 0; j < 3; j++) {
					temp = rand() % 5;
					player_hand_suits[temp] = rand() % 4;
					player_hand_faces[temp] = rand() % 13;
				}
			}
			else if (flag_dealer < 28) {
				for (int j = 0; j < 2; j++) {
					temp = rand() % 5;
					player_hand_suits[temp] = rand() % 4;
					player_hand_faces[temp] = rand() % 13;
				}
			}
			else if (flag_dealer < 42) {
				for (int j = 0; j < 1; j++) {
					temp = rand() % 5;
					player_hand_suits[temp] = rand() % 4;
					player_hand_faces[temp] = rand() % 13;
				}
			}
			else {
				break;
			}

		}

		display_hand(face, suit, dealer_hand_suits, dealer_hand_faces);


		if (flag_player > flag_dealer) {
			printf("\nYou win!\n");
		}
		else if (flag_player < flag_dealer) {
			printf("\nYou lost!\n");
		}
		else {
			printf("\nIt's a tie\n");
		}

		printf("\n1. Continue Playing\n\
2. Quit\n\
>");
		scanf("%d", &menu_selection);
		if (menu_selection == 2) {
			break;
		}
	}
	return 0;
}