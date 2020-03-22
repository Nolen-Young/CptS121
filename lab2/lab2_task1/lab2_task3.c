/*
Name: Nolen Young
Date: 1-24-17
Description: This program takes in user input on the various polls
			 involeved in bcs rankings and computes their rank
*/
#include <stdio.h>

int main(void) {
	double harris_poll = 0;
	double coaches_poll = 0;
	double computer_ranking = 0;
	double bcs_rank = 0;

	printf("Enter the results of the Harris Poll: ");
	scanf(" %lf", &harris_poll);
	printf("Etner the results of the Coaches Poll: ");
	scanf(" %lf", &coaches_poll);
	printf("Enter the results of the Computer Ranking: ");
	scanf(" %lf", &computer_ranking);

	harris_poll = harris_poll / 2850;
	coaches_poll = coaches_poll / 1475;
	bcs_rank = (harris_poll + coaches_poll + computer_ranking) / 3;
	printf("BCS Score: %.4lf\n", bcs_rank);
}