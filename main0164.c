#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int score = 0;
	int max = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &score);
		if (max < score)
			max = score;
	}
	printf("%d", max);

	return 0;
}