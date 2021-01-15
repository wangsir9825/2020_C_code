#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void* my_memcpy(void* des, const void* src, size_t num)
{
	void* ret = des;
	assert(des && src);
	int i = 0;
	while (num--)
	{
		*(char*)des = *(char*)src;
		((char*)des)++;
		((char*)src)++;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int i = 0;
	size_t num = sizeof(arr1);
	my_memcpy(arr2, arr1, num);

	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}