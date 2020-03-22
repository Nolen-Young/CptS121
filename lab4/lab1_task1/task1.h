#include <stdio.h>

double get_weight(void);
double get_height(void);
int get_age(void);
int get_gender(void);
int get_activity_level(void);
double calculate_bmr(double weight, double height, int age, int gender);
double calculate_caloric_intake(double bmr, int activity_level);