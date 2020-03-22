#include "task1.h"

int main(void) {
	char str[] = "CptS 121 is cool!";
	printf("%s\n", str);
	string_reverse(&str);
	printf("%s\n", str);
}