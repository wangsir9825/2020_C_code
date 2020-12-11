#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	float w, h;
	float BMI = 0;
	scanf("%f %f", &w, &h);
	h /= 100;//单位转换：厘米转米
	BMI = w / (h * h);
	printf("%.2f", BMI);
	return 0;
}