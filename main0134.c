#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Step_wise(int arr[][5], int N, int num, int* i, int* j)//Step-wise线性搜索解法
{
	if (arr[0][0] > num || arr[N - 1][N - 1] < num)//如果num不再矩阵的范围内则无法找到num
	{
		return 0;
	}
	while (*i < N && *j >= 0)
	{
		if (arr[*i][*j] == num)
		{
			return 1;
		}
		else if (arr[*i][*j] < num)
		{
			(*i)++;
		}
		else if (arr[*i][*j] > num)
		{
			(*j)--;
		}
	}
	return 0;
}
int main()
{
	int arr[][5] = { {1,5,7,9,22},{4,6,10,15,23},{8,11,12,19,28},{14,16,18,21,50},{15,19,20,27,79} };//定义一个5*5的杨氏矩阵
	int N = sizeof(arr[0]) / sizeof(int);
	int num = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)//输出矩阵
	{
		for (j = 0; j < N; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("请输入你想查找的数:>");
	while (scanf("%d", &num) != EOF)
	{
		int a = 0, b = N - 1;
		int flag = Step_wise(arr, N, num, &a, &b);
		if (flag == 1)
		{
			printf("找到 %d 了,位置为:(%d, %d)\n", num, a+1, b+1);
		}
		else
		{
			printf("没找到\n");
		}
		printf("请输入你想查找的数:>");
	}
	return 0;
}