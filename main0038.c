#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int n = 0;
	int i = 0;
	int m = 0;
	int m1 = 0;
	int j = 0;
	scanf("%d", &n);
	for (i = 0; i < 5; i++)
	{
		m = 0;
		for (j = 0; j <= i; j++)
			m += n * (int)pow(10, j);
		m1 += m;
	}
	printf("%d", m1);
	//printf("\n%d", 2 + 22 + 222 + 2222 + 22222);
	return 0;
}