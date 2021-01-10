#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void BubbleSort(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,5,9,8,7,3,2,4,6,0 };
	int sz = sizeof(arr) / sizeof(int);
	BubbleSort(arr, sz);
	print(arr, sz);
	return 0;
}