#ifndef PA8_H
#define PA8_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

void my_str_n_cat(char *dest, char *source, int n);
int binary_search(int n[], int target); // I know this is supposed to be boolean, but I represent the same thing with 1 for true 0 for false
void bubble_sort(char *strings[], int n);
int isPalindrom(char string[]);
int sum_primes(unsigned int n);
int is_prime(int n);
void maximum_occurrances(char *string, Occurrences *structs, int *n, char *c);

#endif