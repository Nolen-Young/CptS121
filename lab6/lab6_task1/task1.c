#include "task1.h"

int determine_prime(int num)
{
	for (int i = 2; i < num / 2; i++) { // loops for all numbers less than half the num
		if (num % i == 0) return 0; // if the number is divisible by i, return the prime number
	}

	return num; // returns 0 if the number is not prime
}

int add_digits(int num) {
	int r = 0,
		sum = 0;

	while (num != 0) {
		r = num % 10;
		sum = sum + r;
		num = num / 10;
	}

	return sum;
}
