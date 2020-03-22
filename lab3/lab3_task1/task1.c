#include "task1.h"

double get_height(void) {
	double height_in_feet = 0;

	printf("Enter height in feet: ");
	scanf("%lf", &height_in_feet);

	return height_in_feet;
}

double get_weight(void) {
	double weight = 0;

	printf("Enter weight in pounds: ");
	scanf("%lf", &weight);

	return weight;
}

double convert_feet_to_inches(double height_in_feet) {
	double height_in_inches = 0;
	
	height_in_inches = height_in_feet * 12;

	return height_in_inches;
}
double calculate_bmi(double weight_in_pounds, double height_in_feet) {
	double height_in_inches = 0;
	double bmi = 0;

	height_in_inches = convert_feet_to_inches(height_in_feet);
	bmi = (weight_in_pounds / (height_in_inches * height_in_inches)) * 703;

	return bmi;
}
void display_bmi(double bmi) {
	printf("BMI: %.2lf\n", bmi);
}