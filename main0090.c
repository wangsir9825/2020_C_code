#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d",(a + b - c) * d);
	return 0;
}