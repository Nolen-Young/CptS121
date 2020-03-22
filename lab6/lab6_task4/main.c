#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int r = 0,
		guess = 0;

	srand((unsigned int)time(NULL));
	r = (rand() % 200 + 1) - 100;

	do {
		printf("Enter guess: ");
		scanf("%d", &guess);
		if (guess > r) {
			printf("Too high!\n");
		}
		if (guess < r) {
			printf("Too low!\n");
		}
	} while (guess != r);

	printf("You was right\n");

	return 0;
}