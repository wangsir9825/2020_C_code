#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void putstar(int n)
{
	int i = 0;
	int j = 0;
	int m = 0;
	for (i = 0; i < n; i++)
	{

		if (i < (n / 2) + 1)//菱形上半部分
		{
			m = (n / 2) + i;
			for (j = 0; j <= m; j++)//画行,m是每行的字符个数
			{
				if ((j >= ((n / 2) - i)) && (j <= ((n / 2) + i)))//画星星
					printf("*");
				else
					printf(" ");
			}
		}
		else//菱形下半部分
		{
			m--;
			for (j = 0; j <= m; j++)//画行
			{
				if ((j >= ((n / 2) - (n - i - 1))) && (j <= ((n / 2) + (n - i - 1))))
					printf("*");
				else
					printf(" ");//画星星
			}
		}	
		printf("\n");
	}
}
int main()
{
	int i = 0;
	putstar(13);
	return 0;
}