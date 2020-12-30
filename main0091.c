#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int M = 0;
	while (scanf("%d", &M) != EOF)
	{
		if (M % 5 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}