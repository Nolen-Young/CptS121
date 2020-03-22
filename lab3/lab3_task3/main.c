#include "task3.h"

int main(void) {
	double exam1 = 0, exam2 = 0, 
		lab1 = 0, lab2 = 0, project1 = 0, 
		project2 = 0, avg_exam, 
		avg_lab = 0, avg_project = 0, 
		grade = 0;

	exam1 = get_exam(1);
	exam2 = get_exam(2);

	lab1 = get_lab(1);
	lab2 = get_lab(2);

	project1 = get_project(1);
	project2 = get_project(2);

	avg_exam = average_score(exam1, exam2);
	avg_lab = average_score(lab1, lab2);
	avg_project = average_score(project1, project2);

	grade = weight_grade(avg_exam, avg_lab, avg_project);
	display_grade(grade);

	return 0;
}