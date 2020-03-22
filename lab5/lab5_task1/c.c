#include "Header.h"

double read_double(FILE * infile) {
	double result = 0;
	fscanf(infile, "%lf", &result);
	return result;
}

double calculate_sum(double s1, double s2, double s3, double s4) {
	return s1 + s2 + s3 + s4;
}

