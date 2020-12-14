#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d", &n);
	m = n;
	printf("奇数位：");
	while (n)//输出奇数位
	{
		printf("%d", n % 2);
		n = n >> 2;
	}
	printf("\n偶数位：");
	m = m / 2;
	while (m)//输出偶数位
	{
		printf("%d", m % 2);
		m = m >> 2;
	}
	return 0;
}