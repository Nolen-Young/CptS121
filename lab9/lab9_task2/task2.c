#include "task2.h"

char * my_strcpy(char * destination, const char * source) {
	for (int i = 0; i != '\0'; i++) {
		destination[i] = source[i];
	}
	return destination;
}

char * my_strcat(char * destination, const char * source) {
	const int sizeSource = my_strlen(source);
	const int sizeDest = my_strlen(destination);

	for (int i = 0; i < sizeSource; i++) {
		destination[i + sizeDest] = source[i];
	}
	return destination;
}

int my_strcmp(const char * s1, const char * s2) {
	char *p1 = (char *)s1;
	char *p2 = (char *)s2;

	while (*p1 != '\0') {
		if (*p2 == '\0') return  1;
		if (*p2 > *p1)   return -1;
		if (*p1 > *p2)   return  1;

		p1++;
		p2++;
	}

	if (*p2 != '\0') return -1;

	return 0;
}

int my_strlen(const char * s) {
	int i = 0;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
