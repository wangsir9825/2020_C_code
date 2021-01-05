#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int arr[32][32] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}