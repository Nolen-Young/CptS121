#include "task3.h"

int all_star(void) {
	char selection = 'n';
	printf("All star game appearance(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 25000;
	}
	else {
		return 0;
	}
}

int mvp(void) {
	char selection = 'n';
	printf("Regular season MVP(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 75000;
	}
	else {
		return 0;
	}
}

int ws_mvp(void) {
	char selection = 'n';
	printf("World Series MVP(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 100000;
	}
	else {
		return 0;
	}
}

int gold_glove(void) {
	char selection = 'n';
	printf("Won Gold Glove award(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 50000;
	}
	else {
		return 0;
	}
}

int silver_slugger(void) {
	char selection = 'n';
	printf("Won Silver Slugger award(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 35000;
	}
	else {
		return 0;
	}
}

int home_run_champ(void) {
	char selection = 'n';
	printf("Home run champion(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 25000;
	}
	else {
		return 0;
	}
}

int batting_avg_champ(void) {
	char selection = 'n';
	printf("Batting average champ(y or n): ");
	scanf(" %c", &selection);
	if (selection == 'y') {
		return 25000;
	}
	else {
		return 0;
	}
}
