#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	int flag = 1;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0, j = 0;
		m = 2 * n + 1;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < m; i++)
			{
				if (flag == 1)
				{
					printf("*");
					flag = 0;
				}
				else
				{
					printf(" ");
					flag = 1;
				}
			}
			for (i = 0; i < j; i++)
				printf(" ");
			m -= 2;
			flag = 1;
			printf(" \n");
		}



		m = 1;
		for (j = 0; j < n + 1; j++)
		{
			for (i = 0; i < m; i++)
			{

				if (flag == 1)
				{
					printf("*");
					flag = 0;
				}
				else
				{
					printf(" ");
					flag = 1;
				}
			}
			for (i = 0; i < n - j; i++)
				printf(" ");
			m += 2;
			flag = 1;
			printf(" \n");
		}

	}
	return 0;
}