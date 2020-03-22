#include "task1.h"

void charges(double hours, double * charge_ptr, double * avg_hour_ptr) {
	double charge = 7.99,
		avg_hour = 0.0,
		temp_hours = 0.0;

	if (hours < 10.0) {
		avg_hour = charge / hours;
	}
	else {
		temp_hours = hours - 10;
		charge = charge + (1.99 * ceil(temp_hours));
		avg_hour = charge / hours;
	}
	*charge_ptr = charge;
	*avg_hour_ptr = avg_hour;

}

double round_double(double val) {
	return roundf(val * 100) / 100;
}
