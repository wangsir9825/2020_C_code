#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n;
	int m = 1;
	int sum = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 1; i <= n; ++i)
	{
		m *= i;
		sum += m;
	}
	printf("%d", sum);
	return 0;
}