#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, m;
	int i = 0;
	int j = 0;
	int arr[11][11] = { 0 };
	int x = 0, y = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[x][y] < arr[i][j])//找矩阵中最大数的方法，只记录其位置，不用改变其值
			{
				x = i;
				y = j;
			}
		}
	}
	printf("%d %d", x + 1, y + 1);
	return 0;
}