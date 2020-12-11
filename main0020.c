#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	printf("%.2f %.2f", a + b + c, (a + b + c) / 3);
	return 0;
}