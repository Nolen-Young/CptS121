#include <stdio.h>

unsigned int packCharacters(int nums[]);

int main(void) {

	unsigned int a = 0b0;

	char nums[] = {'a', 'b', 'c', 'd'};
	a = packCharacters(nums);
	printf("%d\n", a);

	return 0;
}

unsigned int packCharacters(char characters[]) {
	unsigned int result = 0b0;

	for (int i = 0; i < 4; i++) {
		result <<= 8;
		result = result | (int)characters[i];
	}

	return result;
}
