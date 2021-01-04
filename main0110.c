#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void sort(int* a, int L)//a为数组地址，L为数组长度。
{
	int i, j;
	int v;
	//排序主体
	for (i = 0; i < L - 1; i++)
		for (j = i + 1; j < L; j++)
		{
			if (a[i] > a[j])//如前面的比后面的大，则交换。
			{
				v = a[i];
				a[i] = a[j];
				a[j] = v;
			}
		}
}
int main()
{

	int i = 0;
	int n = 0;
	int m = 0;
	int arr[200] = { 0 };
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < m; i++)
		scanf("%d", &arr[n+i]);
	sort(arr, n+m);
	for (i = 0; i < n + m; i++)
		printf("%d ", arr[i]);
	return 0;
}