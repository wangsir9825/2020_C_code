#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a, i, j, n, m, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a);
			if (i > j && a != 0)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}