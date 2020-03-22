/*******************************************************************************************
* Programmer: Nolen Young                                                                  *
* Class: CptS 121, Spring  2017; Lab Section 13                                            *
* Programming Assignment: Lab1Task2, part A                                                *
* Date: January 17, 2017                                                                   *
* Description: Takes in various user inputted numbers and alters them in various ways	   *
*******************************************************************************************/
#include<stdio.h>

int main(void) {
	int number1_int;
	int number2_int;
	float number1_float;
	float number2_float;

	printf("Input an integer: ");
	scanf("%d", &number1_int);
	printf("\nInput another integer: ");
	scanf("%d", &number2_int);
	printf("\nInput a float: ");
	scanf("%f", &number1_float);
	printf("\nInput another float: ");
	scanf("%f", &number2_float);
		
	printf("\n%d + %d = %d", (number1_int, number2_int, number1_int + number2_int));
	printf("\n%.2f - %.2f = %.2f", (number2_float, number1_float, number2_float - number1_float));
	printf("\n%d * %d = %d", (number1_int, number1_int, number1_int * number1_int));

}