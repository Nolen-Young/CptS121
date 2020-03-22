#include "task2.h"

int main(void) {
	char str1[200] = "Hello";
	char str2[200] = "abc";

	printf("%s\n", my_strcpy(str1, str2));
	printf("%s\n", my_strcat(str1, str2));
	printf("%d\n", my_strcmp(str1, str2));
}
