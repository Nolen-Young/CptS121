#include <stdio.h>

int sum(char num, int sum);

int main(void) {
	int num1 = 759,
		num2 = 2384;

	printf ("%d\n", calculate_sum(num1, 0));
	printf("%d\n", calculate_sum(num2, 0));



	return 0;
}

int calculate_sum(int num, int sum) {
	if (num == 0) return sum;
	else {
		sum += num % 10;
		num = num / (int) 10;
		return calculate_sum(num, sum);
	}
}