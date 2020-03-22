#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i = 0b111100;
	int c = 0b111;

	i = i ^ c;
	printf("%d\n", i);

	return 0;
}