#include "task1.h"

int main(void) {
	FILE * infile;
	infile = fopen("nums.txt", "r");
	int sum = 0,
		temp = 0;

	while (!feof(infile)){
		fscanf(infile, "%d", &temp);
		sum = sum + determine_prime(temp);
	} 

	printf("Sum of primes: %d\n", sum);
	printf("Sum of digits: %d\n", add_digits(sum));

	return 0;
}