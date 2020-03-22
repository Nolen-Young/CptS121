#include "task4.h"

int main(void) {
	int num1 = 0,
		num2 = 0,
		num3 = 0,
		num4 = 0,
		num5 = 0,
		max = 0,
		min = 0;
	double avg = 0;


	FILE * infile;
	infile = fopen("data.dat", "r");

	num1 = read_int(infile);
	num2 = read_int(infile);
	num3 = read_int(infile);
	num4 = read_int(infile);
	num5 = read_int(infile);

	max = get_max(num1, num2, num3, num4, num5);
	min = get_min(num1, num2, num3, num4, num5);
	avg = get_avg(num1, num2, num3, num4, num5);

	printf("Average: %.2lf\nMax: %d\nMin: %d\n", avg, max, min);

	return 0;
}