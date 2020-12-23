#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int i = 0, j = 0;
	int arr1[100] = { 0,1,0 };
	int arr2[100] = { 0,1,0 };
	printf("请输入你想要的杨辉三角数字行数:>");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			arr2[j] = arr1[j];
			if (arr1[j] != 0)
				printf("%d ", arr1[j]);
		}
		printf("\n");
		for (j = 1; j <= n; j++)
		{
			arr1[j] = arr2[j - 1] + arr2[j];
		}	
	}
	return 0;
}