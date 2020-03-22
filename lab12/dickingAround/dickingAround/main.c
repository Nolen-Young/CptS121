#include <stdio.h>

int main(void) {
	char rand[] = "lkwhnerltgnasl;dxfnoihlmnasdfnlk;nasnfdmgnwiurhp;asldkfjbkjhavsdkjfhgjbasdjfjjasdkuijgf";

	for (int i = 1000; i < 10000; i++)
		printf("%d\n", *(rand + i));

	return 0;
}
