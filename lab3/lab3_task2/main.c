#include "task2.h"

int main(void) {
	double theta = 0;
	double distance = 0;
	double velocity = 0;
	double time = 0;
	double height = 0;

	theta = get_theta();
	distance = get_distance();
	velocity = get_velocity();
	time = calculate_time(theta, distance, velocity);
	height = calculate_height(theta, velocity, time);
	
	display_results(time, height);

	return 0;
}
	