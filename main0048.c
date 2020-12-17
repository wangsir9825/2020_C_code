#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void BubbleSort(int arr[], int len)
{
	int i, j;
	int tem;
	for (i = len - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
			}
		}
	}
}
int main()
{
	int n = 0;
	int i = 0;
	int arr[40] = { 0 };
	int len = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}