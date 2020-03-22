#include "task1.h"

int main(void) {
	double weight_in_pounds = 0;
	double height_in_feet = 0;
	double bmi = 0;

	height_in_feet = get_height();
	weight_in_pounds = get_weight();
	bmi = calculate_bmi(weight_in_pounds, height_in_feet);
	display_bmi(bmi);

	return 0;
}