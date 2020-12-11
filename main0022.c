#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c;
	float circumference = 0;//周长
	float p;
	float area = 0;//面积
	scanf("%f %f %f", &a, &b, &c);
	circumference = a + b + c;
	p = circumference / 2;// （海伦公式）
	area = sqrt(p*(p - a)*(p - b)*(p - c));
	printf("circumference=%.2f area=%.2f", circumference, area);
	return 0;
}