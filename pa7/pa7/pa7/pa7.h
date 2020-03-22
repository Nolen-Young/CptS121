#ifndef PA7_H
#define PA7_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], int hand_suits[], int hand_faces[]);
void display_hand(const char *wFace[], const char *wSuit[], int hand_suits[], int hand_faces[]);
int pair(const char *wFace[], int hand_faces[]);
int two_pair(const char *wFace[], int hand_faces[]);
int three_of_a_kind(const char *wFace[], int hand_faces[]);
int four_of_a_kind(const char *wFace[], int hand_faces[]);
int flush(const char *wSuit[], int hand_suits[]);
int straight(const char *wFace[], int hand_faces[]);
int cmpfunc(const void * a, const void * b);
int check_hand(const char *wFace[], const char *wSuit[], int hand_suits[], int hand_faces[]);


#endif