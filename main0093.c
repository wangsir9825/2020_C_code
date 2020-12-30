#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int count = 0;
	int n = 0;
	for (i = 1; i <= 2019; i++)
	{
		n = i;
		while (n != 0)
		{
			if (n % 10 == 9)//如果n中个位是9，就判定这个数是包含数字9的数
			{
				count++;
				break;//跳出while循环
			}
			n /= 10;
		}
	}
	printf("%d\n", count);
	return 0;
}