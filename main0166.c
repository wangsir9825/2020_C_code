#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
float max3(int a, int b, int c)
{
	return (float)((((a > b) ? a : b) > c) ? ((a > b) ? a : b) : c);//输出a、b、c中的最大值。
}
int main()
{
	int a, b, c;
	float m = 0.f;
	scanf("%d %d %d", &a, &b, &c);
	m = max3((a + b), b, c) / (max3(a, b + c, c) + max3(a, b, b + c));
	printf("%.2f", m);
	return 0;
}