#include "lab11_task1.h"

int isPalindrom(char string[]) {
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
