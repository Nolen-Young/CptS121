/*
Name: Nolen Young
Date: 1-24-17
Description: This program will prompt the user for a pair of
			 coordinates then compute various mathematical 
			 facts about the coordinate pairs
*/
//#include <stdio.h>
//
//int main(void) {
//	double x1 = 0;
//	double y1 = 0;
//	double x2 = 0;
//	double y2 = 0;
//	double slope = 0;
//	double avg_x = 0;
//	double avg_y = 0;
//	double slope_of_reciprocal = 0;
//	double reciprocal_y_intercept = 0;
//
//	printf("Enter the points for: (X1, Y1), (X2, Y2)\n");
//	printf("X1: ");
//	scanf(" %lf", &x1);
//	printf("Y1: ");
//	scanf(" %lf", &y1);
//	printf("X2: ");
//	scanf(" %lf", &x2);
//	printf("Y2: ");
//	scanf(" %lf", &y2);
//
//	slope = (y1 - y2) / (x1 - x2);
//	avg_x = (x1 + x2) / 2;
//	avg_y = (y1 + y2) / 2;
//	slope_of_reciprocal = -1 / slope;
//	reciprocal_y_intercept = avg_y - slope_of_reciprocal * avg_x;
//
//	printf("Original points: (%.2lf, %.2lf), (%.2lf, %.2lf)\n", x1, y1, x2, y2);
//	printf("Perpendicular Bisector: y = %.2lfx + %.2lf\n", slope_of_reciprocal, reciprocal_y_intercept);
//}