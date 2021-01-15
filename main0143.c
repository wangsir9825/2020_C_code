#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void* my_memmove(void* des, const void* src, size_t num)
{
	void* ret = des;
	assert(des && src);
	int i = 0;
	if (des <= src)//从前往后复制
	{
		while (num--)
		{
			*(char*)des = *(char*)src;
			((char*)des)++;
			((char*)src)++;
		}
	}
	else//从后往前复制
	{
		while (num--)
		{				
			*(((char*)des)+num) = *(((char*)src)+num);
		}
	}
	return ret;
}
void print(int arr[], int sz)
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
	int arr[] = { 1,2,3,4,5,6,7,8,9 };

	int sz = sizeof(arr)/sizeof(int);
	//my_memmove(arr, arr + 2, 16);//将3 4 5 6 拷贝到1 2 3 4的位置，结果应该是：3 4 5 6 5 6 7 8 9
	//my_memmove(arr + 4, arr + 2, 16);//将3 4 5 6 拷贝到5 6 7 8的位置，结果应该是：1 2 3 4 3 4 5 6 9
	my_memmove(arr + 5, arr + 1, 16);//将2 3 4 5拷贝到6 7 8 9的位置，结果应该是：1 2 3 4 5 2 3 4 5

	print(arr, sz);
	system("pause");
	return 0;
}