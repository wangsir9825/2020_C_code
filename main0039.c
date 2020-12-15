#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
void SXH_PD(int num)
{
	int n = 1;
	int j = 0;
	int num1 = num;
	int num2 = 0;
	while (num1)//计算数字的位数
	{
		num1 /= 10;
		n++;
	}
	num1 = num;
	for (j = 0; j < n; j++)
	{
		num2 += (int)pow((num1 % 10), n);
		num1 /= 10;
	}
	if (num == num2)
		printf("%d ", num);
}
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 0; i <= 100000; i++)
	{
		SXH_PD(i);
	}
	return 0;
}