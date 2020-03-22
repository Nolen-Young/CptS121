#include "task2.h"

int main(void) {
	FILE *outfile = NULL;
	int year = 1984,
		trillion_year = 0;
	double money = 0;

	outfile = fopen("revenue.dat", "w");

	trillion_year = predict(1000000);
	
	for (int i = 0; i <= trillion_year + 1; i++) {
		money = revenue(i);
		fprintf(outfile, "%d $%.2lf\n", year + i, money);
	}

	fclose(outfile);
}