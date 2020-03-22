#include "task3.h"

int main(void) {
	char array_strings[10][50];
	strcpy(array_strings[0], "a string");
	strcpy(array_strings[1], "cat");
	strcpy(array_strings[2], "programming");
	strcpy(array_strings[3], "computers");
	strcpy(array_strings[4], "dogs");
	strcpy(array_strings[5], "cpts");
	strcpy(array_strings[6], "121");
	strcpy(array_strings[7], "nolen");
	strcpy(array_strings[8], "young");
	strcpy(array_strings[9], "betas");

	for (int i = 0; i < 10; i++) {
		printf("%s\n", array_strings[i]);
	}
	printf("\n\n");

	bubble_sort(&array_strings);

	for (int i = 0; i < 10; i++) {
		printf("%s\n", array_strings[i]);
	}



	return 0;
}