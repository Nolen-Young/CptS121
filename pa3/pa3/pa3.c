#include "pa3.h"

// precondition: file must already be open
double read_double(FILE * infile) {
	double num = 0.0;
	
	fscanf(infile, "%lf", &num);

	return num;
}

// precondition: file must already be open
int read_integer(FILE * infile) {
	int num = 0;

	fscanf(infile, "%d", &num);

	return num;
}

// precondition: must have the numbers read into variables
double calculate_sum(double number1, double number2, double number3, double number4, double number5) {
	return number1 + number2 + number3 + number4 + number5;
}

// precondition: must have calculated the sum of the numbers and know how many numbers there are
double calculate_mean(double sum, int number) {
	return sum / number;
}

// precondition: Must have the mean already calculated
double calculate_deviation(double number, double mean) {
	return number - mean;
}

// precondition: must have all the deviations already calculated
double calculate_varience(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	return (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2) / number);
}
 
// precondition: must have calculated varience
double calculate_standard_deviation(double varience) {
	return sqrt(varience);
}

// precondition: must have read in all 5 data points
double find_max(double number1, double number2, double number3, double number4, double number5) {
	double max = number1;

	if (max < number2) {
		max = number2;
	}
	if (max < number3) {
		max = number3;
	}
	if (max < number4) {
		max = number4;
	}
	if (max < number5) {
		max = number5;
	}

	return max;
}

// precondition: must have read in all 5 data points
double find_min(double number1, double number2, double number3, double number4, double number5) {
	double min = number1;

	if (min > number2) {
		min = number2;
	}
	if (min > number3) {
		min = number3;
	}
	if (min > number4) {
		min = number4;
	}
	if (min > number5) {
		min = number5;
	}

	return min;
}

// precondition: must have finished calculations and be ready to be printed to a file
double print_double(FILE * outfile, double number) {
	fprintf(outfile, "%.2lf\n", number);
}
