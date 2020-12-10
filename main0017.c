#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	float n;
	scanf("%f", &n);
	printf("%d", ((int)n) % 10);
	return 0;
}