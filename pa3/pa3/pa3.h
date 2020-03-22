#ifndef PA3_H
#define PA3_H 

#include <stdio.h>
#include <math.h>

double read_double(FILE * infile);
int read_integer(FILE * infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_varience(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double varience);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);
double print_double(FILE * outfile, double number);

#endif