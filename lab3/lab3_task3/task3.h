#include <stdio.h>

#define EXAM_WEIGHT .6
#define LAB_WEIGHT .1
#define PROJECT_WEIGHT .3

double get_exam(int num);
double get_lab(int num);
double get_project(int num);
double average_score(double score1, double score2);
double weight_grade(double avg_exam, double avg_lab, double avg_project);
void display_grade(double grade);
