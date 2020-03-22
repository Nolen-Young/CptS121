#include "task3.h"

int main(void) {
	int n1 = 0,
		n2 = 1,
		result = 0,
		selection = 0;

	printf("Enter positive integer: ");
	scanf("%d", &selection);

	if (selection == 1) {
		result = 0;
	}
	else if (selection == 2) {
		result = 1;
	}
	else {
		for (int i = 2; i < selection; i++) {
			result = n1 + n2;
			n1 = n2;
			n2 = result;
		}
	}
	printf("%d\n", result);
}