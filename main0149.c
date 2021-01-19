#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system realloc
int removeDuplicates(int* nums, int numsSize) {

	int i = 0;
	int n = 0;
	if (numsSize == 0)
		return 0;
	for (i = 0; i < numsSize-1; i++) {
		if (nums[i] != nums[i + 1])//如果相邻两个元素不同就加1
		{
			n++;
			nums[n] = nums[i + 1];
		}
	}
	return n + 1;
}
int main()
{
	int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	int numsSize = sizeof(nums) / sizeof(int);
	int len = removeDuplicates(nums, numsSize);
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		printf("%d ", nums[i]);
	}
	system("pause");//暂停一下
	return 0;
}