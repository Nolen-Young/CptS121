#ifndef PA4_HELP_H
#define PA4_HELP_H

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>
#include <conio.h>

int roll_die(void);
int sum_dice(int die1, int die2);
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);


#endif