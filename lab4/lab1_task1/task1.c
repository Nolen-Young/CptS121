#include "task1.h"

double get_weight(void) {
	double weight = 0;
	printf("Enter weight in pounds: ");
	scanf("%lf", &weight);
	return weight;
}

double get_height(void) {
	double height = 0;
	printf("Enter height in inches: ");
	scanf("%lf", &height);
	return height;
}

int get_age(void) {
	int age = 0;
	printf("Enter your age: ");
	scanf("%d", &age);
	return age;
}

int get_gender(void) {
	int gender = 0;
	printf("Enter gender(0 for male and 1 for female): ");
	scanf("%d", &gender);
	return gender;
}

int get_activity_level(void) {
	int activity_level = 0;
	printf("Enter your activity level on a scale from 1-5, 1 being sedentary and 5 being extra active: ");
	scanf("%d", &activity_level);
	return activity_level;
}

double calculate_bmr(double weight, double height, int age, int gender) {
	double bmr = 0;
	if (gender == 0) {
		bmr = 66 + (6.23 + weight) + (12.7 * height) - (6.8 * age);
	} 
	else {
		bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	}
	return bmr;
}

double calculate_caloric_intake(double bmr, int activity_level) {
	double caloric_intake = 0;
	if (activity_level == 1) {
		caloric_intake = bmr * 1.2;
	}
	else if (activity_level == 2) {
		caloric_intake = bmr * 1.375;
	}
	else if (activity_level == 3) {
		caloric_intake = bmr * 1.55;
	}
	else if (activity_level == 4) {
		caloric_intake = bmr * 1.725;
	}
	else if (activity_level == 5) {
		caloric_intake = bmr * 1.9;
	}
	return caloric_intake;
}
