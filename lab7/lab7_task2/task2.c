#include "task2.h"

double revenue(int t) {
	return (203.265 * pow(1.071, t)) * 1000000;
}

int predict(double r) {
	double t = 0;
	t = log(r / 203.265) / log(1.071);
	return (int)t;
}
