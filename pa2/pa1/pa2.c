#include "pa2.h"

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

double newtons_law(double mass, double accelleration) {
	double result = 0;
	result = mass * accelleration;
	return result;
}

double volume_of_cylinder(double radius, double height) {
	double result = 0;
	result =  (PI * (radius * radius) * height);
	return result;
}

char character_encoding(char character) {
	char result = 'A';
	result = (character - 'a') + 'A';
	return result;
}

double gauss_lens_formula(double u, double v) {
	double result = 0;

	result = (u * v) / (u + v);

	return result;
}

double tangent(double theta) {
	double result = 0;

	result = sin(theta) / cos(theta);

	return result;
}

double resistance_divider(double r1, double r2, double vin) {
	double result = 0;

	result = r2 / (r2 + r1) * vin;

	return result;
}

double distance_between_points(double x1, double y1, double x2, double y2) {
	double result = 0;

	result = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

	return result;
}

double general_equation(int a, double x, double z) {
	double result = 0;

	result = a / ((a % 2) - (63.0 / -17.0) + x * z);

	return result;
}