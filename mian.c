#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//函数功能：给定两个正整数，求这两个整数的最大公约数
int main()
{
	float a = 0, b = 0, c = 0;
	printf("请输入两个正整数：>");
	while (a <= 0 || b <= 0 || (int)a != a || (int)b != b)
	{
		scanf("%f %f", &a, &b);
		//printf("a = %d,b = %d", (int)a, (int)b);
		if (a <= 0 || b <= 0 || (int)a != a || (int)b != b)
		{  
			printf("注意：需要输入两个“正整数”!!!>\n");
			printf("等待输入：>");
		}
		else
		{
			 c = (a > b) ? b : a;             //将较小的值赋给c
			 while((int)a % (int)c != 0 || (int)b % (int)c != 0)    //求最大公约数   
			 {
				c--;                       
			 }
			 printf("最大公约数是：%d\n", (int)c);
		}
	}
	return 0;
}