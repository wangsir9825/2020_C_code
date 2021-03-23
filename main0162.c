#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int score;
	scanf("%d", &score);
	if (score > 100)
		printf("F\n");
	else if (score >= 90)
		printf("A\n");
	else if(score >= 80)
		printf("B\n");
	else if(score >= 70)
		printf("C\n");
	else if (score >= 60)
		printf("D\n");
	else if (score >= 0)
		printf("E\n");
	else
		printf("F\n");

	return 0;
}