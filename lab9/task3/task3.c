#include "task3.h"

void bubble_sort(char * a[]) {
	char bucket = '\0';
	int len = strlen(a);

	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i; j++) {
			if (strcmp(a[j], a[j + 1]) > 0) {
				bucket = a[j];
				a[j] = a[j + 1];
				a[j + 1];
			}

		}
	}
}
