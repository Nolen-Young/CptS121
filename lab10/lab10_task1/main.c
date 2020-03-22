#include "lab10.h"
#include "main.h"

int main(void) {
	char article[5][10] = { "the", "a", "one", "some", "any" };
	char noun[5][10] = { "boy", "girl", "dog", "town", "car" };
	char verb[5][10] = { "drove", "jumped", "ran", "walked", "skipped" };
	char preposition[5][10] = { "to", "from", "over", "under", "on" };
	srand(time(NULL));   
	int r = rand() % 5;
	
	for (int i = 0; i < 20; i++) {
		r = rand() % 5;
		printf("%s", article[r]);
		printf(" ");
		r = rand() % 5;
		printf("%s", noun[r]);
		printf(" ");
		r = rand() % 5;
		printf("%s", verb[r]);
		printf(" ");
		r = rand() % 5;
		printf("%s", preposition[r]);
		printf(" ");
		r = rand() % 5;
		printf("%s", article[r]);
		printf(" ");
		r = rand() % 5;
		printf("%s", noun[r]);
		printf("!");
		printf("\n");
	}

}