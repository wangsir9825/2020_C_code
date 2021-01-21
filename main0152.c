#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	int mid = (left + right) / 2;
	while (left <= right)//这里的等于号千万不能少
	{
		mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] <= target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}			
	}
	return left;
}
int main()
{
	int nums[] = {2,3,4,5,6,7};
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 5;
	while (scanf("%d", &target) != EOF)
	{
		int ret = searchInsert(nums, numsSize, target);
		printf("%d\n", ret);
	}

	return 0;
}