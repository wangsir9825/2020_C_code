#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n, m;
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d%d", &n, &m);
	printf("%d", arr[n - 1][m - 1]);
	return 0;
}