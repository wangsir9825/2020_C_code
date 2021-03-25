#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Prime_Num(int num)
{
	int i = 0;
	for (i = 2; i < num / 2; ++i)
	{
		if (num % i == 0)
			return 1;
	}
	return 0;
}
int main()
{
	int num = 0;
	int i = 0;
	for (i = 100; i < 1000; ++i)
	{
		if (Prime_Num(i) == 0)
			++num;
	}
	printf("%d", num);
	return 0;
}