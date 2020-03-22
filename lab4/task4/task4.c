#include "task4.h"

int read_int(FILE * infile) {
	int num = 0;
	fscanf(infile, "%d", &num);
	return num;
}

int get_max(int num1, int num2, int num3, int num4, int num5) {
	int max = num1;
	if (max < num2) {
		max = num2;
	}
	if (max < num3) {
		max = num3;
	}
	if (max < num4) {
		max = num4;
	}
	if (max < num5) {
		max = num5;
	}
	return max;
}

int get_min(int num1, int num2, int num3, int num4, int num5) {
	int min = num1;
	if (min > num2) {
		min = num2;
	}
	if (min > num3) {
		min = num3;
	}
	if (min > num4) {
		min = num4;
	}
	if (min > num5) {
		min = num5;
	}
	return min;
}

int get_avg(int num1, int num2, int num3, int num4, int num5) {
	double avg = 0;
	avg = (num1 + num2 + num3 + num4 + num5) / 5.0;
	return avg;
}
