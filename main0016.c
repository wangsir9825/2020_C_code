#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	printf("%d", (a + b) % 100);
	return 0;
}