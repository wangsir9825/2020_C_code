// 循环实现
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int money = 0;
	scanf("%d", &money);
	int money1 = money;
	int PZGS = money;//瓶子个数
	while (money > 1)
	{
		PZGS += money / 2;
		if (money % 2)
			money++;
		money /= 2;
	}
	printf("%d 元可以买 %d 瓶汽水", money1, PZGS);
	return 0;
}
//递归实现：
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int water(int mon,int flag)
{
	if (flag == 1)
	{
		return(mon + water((mon+1) / 2, (mon + 1) % 2));
	}
	else if (mon % 2)
	{
		if (mon == 1)
		{
			return 1;
		}
		return(mon + water(mon / 2,1));
	}
	else
	{
		return(mon + water(mon / 2, mon % 2));
	}	
}
int main()
{
	int money = 0;
	scanf("%d", &money);
	printf("%d", water(money, money % 2));
	return 0;
}﻿




