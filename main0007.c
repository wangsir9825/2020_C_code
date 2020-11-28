#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num_left = 0;//左下标
	int num_righ=sizeof(num)/sizeof(num[0])-1;//右下标
	int num_mid;
	int a;
	printf("请输入你要查找的数字(范围1-10):>");
	scanf("%d", &a);
	while (num_left <= num_righ)
	{
		num_mid = (num_left + num_righ) / 2;
		if (num[num_mid] == a)//中值判断
		{
			break;
		}
		else if (num[num_mid] < a)//当中值位于a的左边，改变左下标
		{
			num_left = num_mid + 1;
		}
		else if (num[num_mid] > a)//当中值位于a的右边，改变右下标
		{
			num_righ = num_mid -1;
		}

	}
	if (num_left <= num_righ)
	{
		printf("找到了，该数字所在的下标为：%d", num_mid);
	}
	else
	{
		printf("找不到");
	}
	return 0;
}