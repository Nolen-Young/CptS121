#include "pa8.h"

void my_str_n_cat(char * dest, char * source, int n) {
	int i = 0;

	while (*dest) { // this finds the end of the source array
		dest++;
	}

	while (*dest++ = *source++) { // loops the whole source array or until n is reached
		;
		if (i++ >= n - 1) {
			break;
		}
	}
}

int binary_search(int n[], int target) {
	int left = 1,
		right = sizeof(n) - 1,
		found = 0,
		target_index = -1,
		mid = 0;

	while (found == 0 && left <= right) {
		mid = (right + left) / 2;
		if (target == n[mid]) {
			found = 1;
			target_index = n[mid];
		}
		else if (target < n[mid])
			right = mid - 1;
		else // target > mid
			left = mid + 1;
	}

	return target_index - 1;
}

void bubble_sort(char * strings[], int n) {
	int u = 0,
		c = 0,
		bucket = 0; // this should store the address of the switching strings

	u = n - 1;
	for (u; u > 0; u--) {
		c = 1;
		while (c < u) {
			if (strcmp(strings[c - 1], strings[c]) > 0) {
				bucket = strings[c - 1];
				strings[c - 1] = strings[c];
				strings[c] = bucket;
			}
			c++;
		}

	}
}

int isPalindrom(char string[]) {
	// I used my code from lab 11
	if (strlen(string) <= 1) {
		return 1;
	}
	else if (*string == *((string + strlen(string)) - 1)) {
		*((string + strlen(string)) - 1) = '\0';
		return isPalindrom(string + 1);
	}
	else {
		return 0;
	}
}

int sum_primes(unsigned int n) {
	if (n > 1) {
		n = is_prime(n) + sum_primes(n - 1);
		return n;
	}
	else
	{
		return 0;
	}
}

// this is part of my recursive solution to sum primes
int is_prime(int n) {
	int i = 0,
		r = 2; // what remains

	i = 2;
	r = n % 2;

	while (i != n && r != 0)  {
		r = n % i;
		i++;
	}
	if (i == n) {
		return n; // if its prime, return the number passed in
	}
	else {
		return 0; // the number is not prime
	}
}

void maximum_occurrances(char * string, Occurrences * structs, int * n, char * c) {
	int total_char = 0,
		highest = 0;
	char bucket = '\0',
		temp = '\0';

	while (string[total_char] != '\0') 
		total_char++;

	for (int i = 0; i < total_char; i++) {
		temp = string[i];
		for (int j = 0; j < total_char; j++) {
			if (temp == string[j]) {
				structs[i].num_occurrences++;
			}
		}
		structs[i].num_occurrences = ((double)structs[i].num_occurrences / (double)total_char);
		if (structs[i].num_occurrences > highest) {
			highest = structs[i].num_occurrences;
			bucket = temp;
		}
	}
	*n = highest;
	*c = bucket;
}
