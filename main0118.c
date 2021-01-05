#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	int i = 0;
	int j = 0;
	int h = 0;
	int k = 0;
	char t = '0';
	int a = 0, b = 0;
	int arr[12][12] = { 0 };
	int arr2[12][12] = { 0 };
	int temp = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d", &k);
	for (h = 0; h < k; h++)
	{
		getchar();
		scanf("%c %d %d", &t, &a, &b);
		int min = a < b ? a : b;
		int max = a > b ? a : b;
		if (t == 'r')
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (i == min-1)
					{
						arr2[min - 1][j] = arr[max - 1][j];
					}
					else if (i == max-1)
					{
						arr2[max - 1][j] = arr[min - 1][j];
					}
					else
					{
						arr2[i][j] = arr[i][j];
					}
				}
			}
		}
		if (t == 'c')
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (i == min - 1)
					{
						arr2[j][min - 1] = arr[j][max - 1];
					}
					else if (i == max - 1)
					{
						arr2[j][max - 1] = arr[j][min - 1];
					}
					else
					{
						arr2[j][i] = arr[j][i];
					}		
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				arr[i][j] = arr2[i][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}