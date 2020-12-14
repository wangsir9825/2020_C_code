#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	scanf("%x %o", &a, &b);
	printf("%d", a + b);
	return 0;
}