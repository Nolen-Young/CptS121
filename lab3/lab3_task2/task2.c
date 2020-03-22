#include "task2.h"

double get_theta(void) {
	double theta = 0;

	printf("Enter theta in radians: ");
	scanf("%lf", &theta);

	return theta;

}

double get_distance(void) {
	double distance = 0;

	printf("Enter distance in feet: ");
	scanf("%lf", &distance);

	return distance;
}

double get_velocity(void) {
	double velocity = 0;

	printf("Enter velocity in feet per second: ");
	scanf("%lf", &velocity);

	return velocity;
}
double calculate_time(double theta, double distance, double velocity) {
	double time = 0;

	time = distance / (velocity * cos(theta));

	return time;
}

double calculate_height(double theta, double velocity, double time) {
	double height = 0;

	height = velocity * sin(theta) * time - ((G * (time * time)) / 2);

	return height;
}

void display_results(double time, double height) {
	printf("It will take %.2lf seconds.\n", time);
	printf("The impact will be at %.2lf feet.\n", height);
}