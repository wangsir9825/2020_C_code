#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#define pi 3.1415926
int main()
{
	double r, v;
	scanf("%lf", &r);
	v = 4.0 / 3.0 * pi * pow(r, 3);//4/3结果为int型得1，需要4.0/3.0
	printf("%.3lf", v);
	return 0;
}