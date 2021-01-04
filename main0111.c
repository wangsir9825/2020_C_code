#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 5
int main()
{
	int i = 0;
	int j = 0;
	float grade[N][N] = { 0.f };
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%f", &grade[i][j]);
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%.1f ", grade[i][j]);
			if (j == N - 1)
				printf("%.1f\n", grade[i][0] + grade[i][1] + grade[i][2] + grade[i][3] + grade[i][4]);
		}
	}
	return 0;
}