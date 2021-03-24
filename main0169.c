#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a, b, c, d;
	float Total_grd;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	Total_grd = a * 0.2f + b * 0.1f + c * 0.2f + d * 0.5f;
	printf("%.1f", Total_grd);
	return 0;
}