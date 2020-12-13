#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int score[5] = { 0 };
	int i = 5;
	while (i)
	{
		scanf("%d", &score[--i]);
	}
	printf("%.1f", (float)(score[0] + score[1] + score[2] + score[3] + score[4]) / 5.0);
	
	return 0;
}