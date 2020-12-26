#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
				printf("%d ", j + 1);
			printf("\n");
		}
	}
	return 0;
}