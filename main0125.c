#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	long long int a = 0, b = 0, c = 0;
	scanf("%d %d", &a, &b);
	c = (a > b) ? b : a;             //将a、b中较小的值赋给c
	while ((a % c != 0) || (b % c != 0))    //求最大公约数   
	{
		c--;
	}
	printf("%lld", a * b / c + c);
	return 0;
}