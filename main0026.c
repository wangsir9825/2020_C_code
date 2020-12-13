#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n=0, h=0, m=0;
	scanf("%d%d%d", &n, &h, &m);
	if ((m % h) == 0)
		n = n - (m / h);
	else
		n = n - (m / h) - 1;
	printf("%d", n);
	return 0;
}