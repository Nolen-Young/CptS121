/*******************************************************************************************
* Programmer: Nolen Young                                                                  *
* Class: CptS 121, Spring  2017; Lab Section 13                                            *
* Programming Assignment: pa2                                                              *
* Date: Febuary 18, 2017                                                                   *
* Description: This program takes user input on which formula the user would like to solve *
*			   and then runs a function to solve the formula for the user				   *
*******************************************************************************************/

#include "pa2.h"

int main(void) {
	double mass = 0, //variable declaration for every function.
		acceleration = 0,
		radius = 0,
		height = 0,
		u = 0,
		v = 0,
		theta = 0,
		r1 = 0,
		r2 = 0,
		vin = 0,
		x1 = 0,
		x2 = 0,
		y1 = 0,
		y2 = 0,
		x = 0,
		z = 0;
	char character = 'a';
	int selection = 0,
		a = 0;

	while (true) { //essentially the program will run until the user tells it to stop
		print_menu();
		scanf("%d", &selection);
		if (selection == 1) { //this if/else block determines which function to run based on user input
			printf("\nEnter the mass: ");
			scanf("%lf", &mass);
			printf("Enter the accellaration: ");
			scanf("%lf", &acceleration);

			printf("Force: %.2lf\n\n", newtons_law(mass, acceleration));
		}
		else if (selection == 2) {
			printf("\nEnter the radius: ");
			scanf("%lf", &radius);
			printf("Enter the height: ");
			scanf("%lf", &height);

			printf("Volume: %.2lf\n\n", volume_of_cylinder(radius, height));
		}
		else if (selection == 3) {
			printf("\nEnter the character: ");
			scanf(" %c", &character);

			printf("Encoded Character: %c\n\n", character_encoding(character));
		}
		else if (selection == 4) {
			printf("\nEnter u: ");
			scanf("%lf", &u);
			printf("Enter v: ");
			scanf("%lf", &v);

			printf("%.2lf\n\n", gauss_lens_formula(u, v));
		}
		else if (selection == 5) {
			printf("Enter theta (in radians): ");
			scanf("%lf", &theta);

			printf("Tangent: %.2lf\n\n", tangent(theta));
		}
		else if (selection == 6) {
			printf("\nEnter R1: ");
			scanf("%f", &r1);
			printf("Enter R2: ");
			scanf("%f", &r2);
			printf("Enter vin: ");
			scanf("%f", &vin);

			printf("%.2lf\n\n", resistance_divider(r1, r2, vin));
		}
		else if (selection == 7) {
			printf("\nEnter point 1. (ex: (1, 2) would be entered as 1 2): ");
			scanf("%lf %lf", &x1, &y1);
			printf("Enter point 2. (ex: (1, 2) would be entered as 1 2): ");
			scanf("%lf %lf", &x2, &y2);

			printf("%.2lf\n\n", distance_between_points(x1, y1, x2, y2));
		}
		else if (selection == 8) {
			printf("\nEnter a: ");
			scanf(" %d", &a);
			printf("Enter x: ");
			scanf(" %lf", &x);
			printf("Enter z: ");
			scanf(" %lf", &z);

			printf("%.2lf\n\n", general_equation(a, x, z));
		}
		else if (selection == 9) {
			break;
		}
		else {
			printf("Error: invalid input\n");
		}
	}
	return 0;
}