#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int score;
	int max = 0;
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		scanf("%d", &score);
		if (max < score)
		{
			max = score;
		}
	}
	printf("%d", max);
	return 0;
}