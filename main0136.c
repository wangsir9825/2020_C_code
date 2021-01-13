#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	float a = 0.f, b = 0.f, c = 0.f;
	int flag = 0;
	printf("请输入两个正整数：>");
	while (a <= 0.f || b <= 0.f || (int)a != a || (int)b != b)
	{
		flag = scanf("%f %f", &a, &b);//scanf如果是从缓存中读取是两个数字，就会返回2
		if (flag != 2 || a <= 0.f || b <= 0.f || (int)a != a || (int)b != b)
		{
			printf("注意：需要输入两个“正整数”!!!>\n");
			printf("等待再次输入：>");
			rewind(stdin);//清理标准输入流的缓存
		}
		else
		{
			c = (a > b) ? b : a;             //将较小的值赋给c
			while ((int)a % (int)c != 0.f || (int)b % (int)c != 0.f)    //求最大公约数   
			{
				c--;
			}
			printf("最大公约数是：%d\n", (int)c);
		}
	}
	return 0;
}
