#include "task1.h"	

void string_reverse( char *str[]) {
	int i = 0;
	int j = 0;
	char bucket = 's';
	for (i = 0; str[i] != '\0'; i++);

	for (j = 0; j <= i / 2; j++) {
		bucket = str[j];
		str[j] = str[i - j];
		str[i - j] = bucket;
	}
}
