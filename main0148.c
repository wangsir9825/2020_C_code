#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system realloc
#include <assert.h>//包括的函数有：assert
//冒泡排序
void BubbleSort(int* pst, int size)
{
	for (int i = 0; i < size - 1; ++i) //控制趟数
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (pst[j] > pst[j + 1])
			{
				//交换数据
				int tmp = pst[j];
				pst[j] = pst[j + 1];
				pst[j + 1] = tmp;
			}
		}
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	assert(nums1 && nums2);
	int i = 0;
	for (i = 0; i < n; i++) {
		nums1[m + i] = nums2[i];
	}
	BubbleSort(nums1, nums1Size);
}
int main()
{
	int arr1[] = {1, 2, 3, 0, 0, 0};
	int arr2[] = {2, 5, 6};
	int m = 3;
	int n = 3;
	int i = 0;
	int* nums1 = arr1;
	int* nums2 = arr2;
	int nums1Size = sizeof(arr1) / sizeof(int);
	int nums2Size = sizeof(arr2) / sizeof(int);

	merge(nums1, nums1Size, m, nums2, nums2Size, n);
	for (i = 0; i < nums1Size; i++)//向顺序表中写入数据
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
	system("pause");//暂停一下
	return 0;
}