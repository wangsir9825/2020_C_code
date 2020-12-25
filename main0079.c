#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, i, j;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((i == 0) || (i == n - 1))
					printf("* ");
				else
				{
					if ((j == 0) || (j == n - 1))
						printf("* ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}