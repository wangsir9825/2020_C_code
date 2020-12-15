#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* parr = arr;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *parr++);
	}
	return 0;
}