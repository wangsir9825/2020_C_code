#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int arr[10][10] = { 0 };
	int x = 0, y = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if ((j < i) && (arr[i][j] != 0))
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}