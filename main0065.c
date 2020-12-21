#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0, j = 0;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
				printf("* ");
			printf("\n");
		}
	}
	return 0;
}