#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 10
int main()
{
	int num[N] = { 0 };
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}	
	for (i = 0; i < N; i++)
	{
		printf("%d ", num[N - 1 - i]);
	}
	return 0;
}