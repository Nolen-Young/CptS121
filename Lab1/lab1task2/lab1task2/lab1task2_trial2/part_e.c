/*******************************************************************************************
* Programmer: Nolen Young                                                                  *
* Class: CptS 121, Spring  2017; Lab Section 13                                            *
* Programming Assignment: Lab1Task2, part C                                              *
* Date: January 17, 2017                                                                   *
* Description: Takes in various user inputted numbers and alters them in various ways	   *
*******************************************************************************************/
#include<stdio.h>

int main(void) {
	float r = 0.0;
	float pi = 3.14159265358979323846;
	printf("Enter radius: ");
	scanf("%f", &r);
	printf("%.4f\n", 2 * pi * r);
}