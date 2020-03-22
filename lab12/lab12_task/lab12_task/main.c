#include <stdio.h>

void tower(int num, int topeg, int frompeg, int otherpeg, int sum);

int main(void) {
	int sum = 0;
	tower(9, 1, 2, 3, &sum);
	printf("%d\n", sum);
}

void tower(int num, int topeg, int frompeg, int otherpeg, int *sum)
{
	(*sum)++;
	if (num == 1)	{
		printf("Move disk 1 from peg %d to peg %d\n", frompeg, topeg);
		return;
	}
	tower(num - 1, frompeg, otherpeg, topeg, sum);
	printf("Move disk %d from peg %d to peg %d\n", num, frompeg, topeg);
	tower(num - 1, otherpeg, topeg, frompeg, sum);
}
