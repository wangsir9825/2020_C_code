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
		m = n;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < m; i++)
			{
				if (i < n-j-1)
					printf(" ");
				else
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
			}
			m++;
			flag = 1;
			printf(" \n");
		}
	}
	return 0;
}