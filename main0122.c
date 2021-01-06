#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	unsigned long long int sum = 0;
	int i = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}
	printf("%lld", sum);
	return 0;
}