#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void JOTZ_func(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz; j++)
		{
			if (*(arr + j) % 2 == 0 && (*(arr + j + 1)) % 2 == 1)
			{
				*(arr + j) ^= *(arr + j + 1);
				*(arr + j + 1) ^= *(arr + j);
				*(arr + j) ^= *(arr + j + 1);
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1,2,10,4,5,6,7,8,9,0 };
	//int arr[] = { 65,465,6,56,4,6,4,63,56,5,65,465 };

	int sz = sizeof(arr) / sizeof(arr[0])-1;
	JOTZ_func(arr,sz);
	for (i = 0; i <= sz; i++)
		printf("%d ", arr[i]);
	return 0;
}