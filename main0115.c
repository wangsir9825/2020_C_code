#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, m;
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	int arr2[10][10] = { 0 };
	int x = 0, y = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr2[i][j]);
			if (arr[i][j] != arr2[i][j])//找矩阵中最大数的方法，只记录其位置，不用改变其值
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
	return 0;
}