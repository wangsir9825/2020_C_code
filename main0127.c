#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 1, b = 2;
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 1)
		{
			printf("%d", a);
		}
		else
		{
			while (--n)//当n=2时，只进行一次循环
			{
				a ^= b;
				b ^= a;
				a ^= b;//将b的值赋给a
				b += a;
			}
			printf("%d", a);
		}

	}
	return 0;
}