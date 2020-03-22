#include "task1.h"

int main(void) {
	double hours = 0,
		charge = 0.0,
		avg_hour = 0.0;

	printf("How many hours were used? ");
	scanf("%lf", &hours);
	charges(hours, &charge, &avg_hour);

	charge = round_double(charge);
	avg_hour = round_double(avg_hour);

	printf("Total charge: %.2lf\n", charge);
	printf("Average cost per hour: %.2lf\n", avg_hour);
}