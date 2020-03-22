#include "task2.h"

int main(void) {
	int num = 0,
		result = 1; // must make 1 so the result isnt 1

	printf("Enter positive integer: ");
	scanf("%d", &num);

	for (int i = num; i > 0; i--) {
		result = result * i;
	}

	printf("!%d = %d\n", num, result);

	return 0;
}