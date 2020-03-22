#include <stdio.h>
#include <math.h>

#define G 32.17

double get_theta(void);
double get_distance(void);
double get_velocity(void);
double calculate_time(double theta, double distance, double velocity);
double calculate_height(double theta, double velocity, double time);
void display_results(double time, double height);