#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr1[100][100] = { 0 };
	int arr2[100][100] = { 0 };
	int m = 0, n = 0;
	int i = 0, j = 0;
	int count = 0;//表示有多少个相同的
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++) //输入第一个矩阵
		for (j = 0; j < n; j++)
			scanf("%d", &arr1[i][j]);//一个一个输入
	for (i = 0; i < m; i++)//输入第二个矩阵
		for (j = 0; j < n; j++)
			scanf("%d", &arr2[i][j]);//一个一个输入
	for (i = 0; i < m; i++)//判断有多少个相同的数字
		for (j = 0; j < n; j++)
			if (arr1[i][j] == arr2[i][j])
				count++;
	printf("%0.2f\n", (float)(count*100) / (float)(m * n));
	return 0;
}