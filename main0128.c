#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n, i = 0, k, a[100001] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		a[k] = k; // 把相同的数存进相同的数组元素中,去重
	}
	for (i = 0; i <= n; i++)//这个解法很巧妙，没有用排序算法和去重，而是利用了数组自然增序的特点进行去重排序。
	{
		if (a[i])
			printf("%d ", a[i]);
	}
	return 0;
}