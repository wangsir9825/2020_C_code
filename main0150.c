#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system realloc
int removeElement(int* nums, int numsSize, int val) {
	int i = 0;
	int j = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}
int main()
{
	int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int val = 2;
	int numsSize = sizeof(nums) / sizeof(int);
	int len = removeElement(nums, numsSize, val);
	for (int i = 0; i < len; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");//暂停一下
	return 0;
}