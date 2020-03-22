#ifndef PA4_HELP_H
#define PA4_HELP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void print_rules(void);
int menu(void);
int roll_die(void);
int roll_dice(int *die1, int *die2, int *die3, int *die4, int *die5);
void print_dice(int die1, int die2, int die3, int die4, int die5);
void print_scoreboard(int upper[], int lower[]);
int score_upper(int die1, int die2, int die3, int die4, int die5, int num);
int three_of_a_kind(int die1, int die2, int die3, int die4, int die5, int num);
int four_of_a_kind(int die1, int die2, int die3, int die4, int die5, int num);
int full_house(int die1, int die2, int die3, int die4, int die5, int high, int low);
int lower_straight(int die1, int die2, int die3, int die4, int die5, int num);
int upper_dtraight(int die1, int die2, int die3, int die4, int die5, int num);
int yahtzee(int die1, int die2, int die3, int die4, int die5);
int chance(int die1, int die2, int die3, int die4, int die5);
int calculate_score(int upper[], int lower[]);


#endif