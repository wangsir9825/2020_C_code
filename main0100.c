#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int N = 0;
	int M = 0;
	int sum = 0;
	int i = 0;
	int j = 0;
	int num[10] = { 0 };
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &num[j]);
			if (num[j] > 0)
				sum += num[j];
		}
	}
	printf("%d\n", sum);
	return 0;
}