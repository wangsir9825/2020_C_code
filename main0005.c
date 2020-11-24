#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int num[10];
	int max = 0;
	printf("请输入10个整数，并以空格隔开：>\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d",&num[i]);
		if (max < num[i])
		{
			max = num[i];
		}
	}
	printf("最大值为：%d", max);
	return 0;
}