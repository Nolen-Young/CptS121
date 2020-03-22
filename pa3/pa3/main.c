/*
Programmer: Nolen Young
Class: CPTS 121
Date: 2-10-17
Description: This program reads in data from input.dat about classes and gpa and completes a few statistical calculations
			 of the data and then saves the calculated information to out_file.dat

*/

#include "pa3.h"

int main(void) {
	// declare variables and open files
	double gpa1 = 0,
		gpa2 = 0,
		gpa3 = 0,
		gpa4 = 0,
		gpa5 = 0,
		gpa_sum = 0,
		gpa_mean = 0,
		gpa1_deviation = 0,
		gpa2_deviation = 0,
		gpa3_deviation = 0,
		gpa4_deviation = 0,
		gpa5_deviation = 0;
	double age1 = 0,
		age2 = 0,
		age3 = 0,
		age4 = 0,
		age5 = 0,
		age_sum = 0,
		age_mean = 0,
		class_mean = 0; // had to put class_mean with the ages to make it a double
	int class1 = 0,
		class2 = 0,
		class3 = 0,
		class4 = 0,
		class5 = 0,
		class_sum = 0;
	int id1 = 0,
		id2 = 0,
		id3 = 0,
		id4 = 0,
		id5 = 0;
	double variance = 0,
		standard_deviation = 0,
		min = 0,
		max = 0;
	FILE * infile = NULL;
	FILE * outfile = NULL;

	outfile = fopen("out_file.dat", "w+");
	infile = fopen("input.dat", "r");

	// read in all of the data;
	id1 = read_integer(infile);
	gpa1 = read_double(infile);
	class1 = read_integer(infile);
	age1 = read_double(infile);

	id2 = read_integer(infile);
	gpa2 = read_double(infile);
	class2 = read_integer(infile);
	age2 = read_double(infile);

	id3 = read_integer(infile);
	gpa3 = read_double(infile);
	class3 = read_integer(infile);
	age3 = read_double(infile);

	id4 = read_integer(infile);
	gpa4 = read_double(infile);
	class4 = read_integer(infile);
	age4 = read_double(infile);

	id5 = read_integer(infile);
	gpa5 = read_double(infile);
	class5 = read_integer(infile);
	age5 = read_double(infile);

	// calculate the mean then write it to the outfile
	gpa_sum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	class_sum = calculate_sum(class1, class2, class3, class4, class5);
	age_sum = calculate_sum(age1, age2, age3, age4, age5);

	gpa_mean = calculate_mean(gpa_sum, 5.0);
	class_mean = calculate_mean(class_sum, 5.0);
	age_mean = calculate_mean(age_sum, 5.0);

	print_double(outfile, gpa_mean);
	print_double(outfile, class_mean);
	print_double(outfile, age_mean);

	fprintf(outfile, "\n"); // makes a seperation between the two chunks of data

	// calculate the standard deviation of the mean
	gpa1_deviation = calculate_deviation(gpa1, gpa_mean);
	gpa2_deviation = calculate_deviation(gpa2, gpa_mean);
	gpa3_deviation = calculate_deviation(gpa3, gpa_mean);
	gpa4_deviation = calculate_deviation(gpa4, gpa_mean);
	gpa5_deviation = calculate_deviation(gpa5, gpa_mean);

	variance = calculate_varience(gpa1_deviation, gpa2_deviation, gpa3_deviation, gpa4_deviation, gpa5_deviation, 5.0);
	standard_deviation = calculate_standard_deviation(variance);

	print_double(outfile, standard_deviation);

	// determine the minimum gpa
	min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	print_double(outfile, min);

	// determine the max gpa
	max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	print_double(outfile, max);

	return 0;
}