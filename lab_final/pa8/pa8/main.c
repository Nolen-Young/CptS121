#include "pa8.h"

int main(void) {
	// string concatonation
	char s1 [100] = "Computer";
	char s2 [100] = "Science";

	my_str_n_cat(s1, s2, 3);
	printf("%s\n", s1);

	// binary search
	int list[5] = { 1, 2, 3, 4, 5 },
		index = -1;
	index = binary_search(list, 3);
	printf("%d\n", index);

	// bubble sort
	char *strings[] = { "Hello", "this", "is", "programming", "assignment", "eight" };
	for (int i = 0; i < 6; i++) {
		printf("%s ", strings[i]);
	}
	printf("\n");
	bubble_sort(strings, 6);
	for (int i = 0; i < 6; i++) {
		printf("%s ", strings[i]);
	}
	printf("\n");

	// is palindrom
	char s3[] = "racecar";
	printf("%d\n", isPalindrom(s3));

	// sum prime
	printf("%d\n", sum_primes(10));

	// maximum occurences
	char word[] = "string";
	Occurrences *occ[100] = { '\0' };
	int n = 0;
	int *n_pointer = &n;
	char c = '\0';
	char *c_pointer = &c;
	maximum_occurrances(word, occ, n_pointer, c_pointer);
	printf("%d, %c\n", n, c);
	
	

	
	return 0;
}