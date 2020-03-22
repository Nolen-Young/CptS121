#include "task3.h"

int main(void) {
	int bonus = 0;

	bonus += all_star();
	bonus += mvp();
	bonus += ws_mvp();
	bonus += gold_glove();
	bonus += silver_slugger();
	bonus += home_run_champ();
	bonus += batting_avg_champ();

	printf("Bonus: $%d\n", bonus);

	return 0;
}