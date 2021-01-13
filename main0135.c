#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b;
	int flag = 0;
	while (1)
	{
		flag = scanf("%d %d", &a, &b);
		fflush(stdin);
		if (flag == 2)
		{
			printf("输入的是数字%d和%d\n", a, b);
			return 0;
		}
		else
		{
			printf("输入的不是数字\n");//visual studio 2019无法使用fflush(stdin)函数消除缓冲区，可以使用rewind(stdin)函数替换，效果相同。
			rewind(stdin);
		}
	}
	return 0;
}