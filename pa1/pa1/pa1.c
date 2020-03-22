/*******************************************************************************************
* Programmer: Nolen Young                                                                  *
* Class: CptS 121, Spring  2017; Lab Section 13                                            *
* Programming Assignment: pa1                                                              *
* Date: January 18, 2017                                                                   *
* Description: This program takes user input on which formula the user would like to solve *
*******************************************************************************************/
#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846264338327950288419716939937510582

typedef enum {false, true} bool;

//Declare and define my functions for each equation
/*I have recently learned that we are supposed to declare and define the functions separetely.
  I learned about this after I wrote this code so I am not going to change it as it still works,
  but I will not code my functions like this in the future. */
int print_menu(void) {
	printf("1. Newtons Second Law of Motion\n");
	printf("2. Volume of a Cylinder\n");
	printf("3. Character Encoding\n");
	printf("4. Gauss Lens Formula\n");
	printf("5. Tangent\n");
	printf("6. Resistive Divider\n");
	printf("7. Distance Between Two Points\n");
	printf("8. General Equation\n");
	printf("9. Quit\n");
	printf(">");

	return 0;
}

int newtons_law(void) {
	float mass = 0.0;
	float acceleration = 0.0;

	printf("\nEnter the mass: ");
	scanf("%f", &mass);
	printf("Enter the accellaration: ");
	scanf("%f", &acceleration);

	printf("%2.2f * %2.2f = %2.2f\n\n", mass, acceleration, mass * acceleration);

	return 0;
}

int volume_of_cylinder(void) {
	float radius = 0.0;
	float height = 0.0;
	
	printf("\nEnter the radius: ");
	scanf("%f", &radius);
	printf("Enter the height: ");
	scanf("%f", &height);

	printf("Pi * %.2f^2 * %.2f = %.4f\n\n", radius, height, PI * (radius * radius) * height);

	return 0;
}

int character_encoding(void) {
	char character = "a";

	printf("\nEnter the character: ");
	scanf(" %c", &character);
	printf("Encoded character: %c\n\n", (character - 'a') + 'A');

	return 0;
}

int gauss_lens_formula(void) {
	double u = 0;
	double v = 0;

	printf("\nEnter u: ");
	scanf("%lf", &u);
	printf("Enter v: ");
	scanf("%lf", &v);

	printf("(%.2lf * %.2lf) / (%.2lf + %.2lf) = %.4lf\n\n", u, v, u, v, (u * v) / (u + v));

	return 0;
}

int tangent(void) {
	double theta = 0;

	printf("Enter theta (in radians): ");
	scanf("%lf", &theta);

	printf("sin(%.2lf) / cos(%.2lf) = %.4lf\n\n", theta, theta, sin(theta) / cos(theta));

	return 0;
}

int resistance_divider(void) {
	float r1 = 0;
	float r2 = 0;
	float vin = 0;

	printf("\nEnter R1: ");
	scanf("%f", &r1);
	printf("Enter R2: ");
	scanf("%f", &r2);
	printf("Enter vin: ");
	scanf("%f", &vin);

	printf("%.2f / (%.2f + %.2f) * %.2f = %.2f\n\n", r2, r1, r2, vin, r2 / (r2 + r1) * vin);

	return 0;
}

int distance_between_points(void) {
	double distance = 0;
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;

	printf("\nEnter point 1. (ex: (1, 2) would be entered as 1 2): ");
	scanf("%lf %lf", &x1, &y1);
	printf("Enter point 2. (ex: (1, 2) would be entered as 1 2): ");
	scanf("%lf %lf", &x2, &y2);

	printf("sqrt((%.2lf - %.2lf)^2 + (%.2lf - %.2lf)^2) = %.4lf\n\n", x1, x2, y1, y2, sqrt(((x1 - x2) * (x1 - x2)) + ((y1- y2) * (y1 - y2))));

	return 0;
}

int general_equation(void) {
	int a = 1;
	double x = 1.0;
	double z = 1.0;

	printf("\nEnter a: ");
	scanf(" %d", &a);
	printf("Enter x: ");
	scanf(" %lf", &x);
	printf("Enter z: ");
	scanf(" %lf", &z);

	printf("%d / (%d \% 2) - (63 / -17) + %.2lf * %.2lf = %.2lf\n\n", a, a, x, z,  a / ((a % 2) - (63.0 / -17.0) + x * z));

	return 0;
}

int main(void) {
	int selection = 0; 
	while (true) { // essentially the program will run until the user tells it to stop
		print_menu();
		scanf("%d", &selection);
		if (selection == 1) { // this if/else block determines which function to run based on user input
			newtons_law();
		} 
		else if (selection == 2) {
			volume_of_cylinder();
		}
		else if (selection == 3) {
			character_encoding();
		}
		else if (selection == 4) {
			gauss_lens_formula();
		}
		else if (selection == 5) {
			tangent();
		}
		else if (selection == 6) {
			resistance_divider();
		}
		else if (selection == 7) {
			distance_between_points();
		}
		else if (selection == 8) {
			general_equation();
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