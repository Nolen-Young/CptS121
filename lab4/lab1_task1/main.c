#include "task1.h"

int main(void) {
	double weight = 0,
		height = 0,
		age = 0,
		bmr = 0,
		caloric_intake = 0;
	int gender = 0,
		activity_level = 0;

	weight = get_weight();
	height = get_height();
	age = get_age();
	gender = get_gender();
	activity_level = get_activity_level();

	bmr = calculate_bmr(weight, height, age, gender);
	caloric_intake = calculate_caloric_intake(bmr, activity_level);
	printf("Caloric intake: %.2lf\n", caloric_intake);

	return 0;
}