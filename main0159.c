#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	float sum = a + b + c;
	printf("%.2f %.2f", sum, sum / 3.f);
	return 0;
}