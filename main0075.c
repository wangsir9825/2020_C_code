#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n, i, j;
	int m = 0;
	while (scanf("%d", &n) != EOF)
	{
		m = 2 * n;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf(" ");
			for (j = 0; j <= i; j++)
				printf("*");
			m -= 2;
			printf("\n");
		}
		m = 0;
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j < m; j++)
				printf(" ");
			for (j = 0; j <= n - i; j++)
				printf("*");
			m += 2;
			printf("\n");
		}
	}
	return 0;
}