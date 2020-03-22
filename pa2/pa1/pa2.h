#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846264338327950288419716939937510582

typedef enum { false, true } bool;//this allows me to use boolean values which I use in the main function while loop

//does a set of printf statements to print out a simple menu
int print_menu(void);

//does the equation: mass * accelleration
double newtons_law(double mass, double accelleration);

//does the equation: PI * (radius * radius) * height
double volume_of_cylinder(double radius, double height);

//takes a character then shifts the ascii value down by 'a' and then up by 'A'
char character_encoding(char character);

//does the equation: (u * v) / (u + v)
double gauss_lens_formula(double u, double v);

//does the equation: sin(theta) / cos(theta)
double tangent(double theta);

//does the equation: r2 / (r2 + r1) * vin
double resistance_divider(double r1, double r2, double vin);

//does the equation: sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)))
double distance_between_points(double x1, double y1, double x2, double y2);

//does the equation: a / ((a % 2) - (63.0 / -17.0) + x * z)
double general_equation(double a, double x, double z);