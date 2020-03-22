#include <stdio.h>

int power2(int number, int pow);

int main(void) {
	int a = 0b100;
	a = a << 1;
	printf("%d\n", a);

	printf("%d\n", power2(5, 3));

	return 0;
}

int power2(int number, int pow) {
	int two = 0b10;
	number = number * (two << pow);
	return number;
}