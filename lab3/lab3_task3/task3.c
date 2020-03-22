#include "task3.h"

double get_exam(int num) {
	double score = 0;

	printf("Enter exam %d score: ", num);
	scanf("%lf", &score);

	return score;
}
double get_lab(int num) {
	double score = 0;

	printf("Enter lab %d score: ", num);
	scanf("%lf", &score);

	return score;
}
double get_project(int num) {
	double score = 0;

	printf("Enter project %d score: ", num);
	scanf("%lf", &score);

	return score;
}
double average_score(double score1, double score2) {
	double avg = 0;
	
	avg = (score1 + score2) / 2;

	return avg;
}

double weight_grade(double avg_exam, double avg_lab, double avg_project) {
	double weighted_grade = 0;

	avg_exam = avg_exam * EXAM_WEIGHT;
	avg_project = avg_project * PROJECT_WEIGHT;
	avg_lab = avg_lab * LAB_WEIGHT;

	weighted_grade = avg_exam + avg_lab + avg_project;

	return weighted_grade;
}
void display_grade(double grade) {
	printf("Score: %.2lf\n", grade);
}
