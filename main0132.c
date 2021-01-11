#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void my_Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}


void BubbleSort(
	void* base, //首元素地址
	size_t num, //数组元素个数
	size_t width, //每个元素所占的字节
	int(*compare)(const void* eleml, const void* elem2)//自定义比较函数
)
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				my_Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void print1(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print2(char* arr, char sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
}
int compare1(const void* eleml, const void* elem2)
{
	return *(int*)eleml - *(int*)elem2;
}
int compare2(const void* eleml, const void* elem2)
{
	return *(char*)eleml - *(char*)elem2;
}
int main()
{
	int arr1[] = { 1,5,9,8,7,3,2,4,6,0 };
	char arr2[] = "zxcvbnmasdfghjklqwertyuiop";
	int sz1 = sizeof(arr1) / sizeof(int);
	int sz2 = sizeof(arr2) / sizeof(char) - 1;

	printf("整型数组排序前：>");
	print1(arr1, sz1);
	BubbleSort(arr1, sz1,sizeof(int),compare1);
	printf("整型数组排序后：>");
	print1(arr1, sz1);


	printf("字符数组排序前：>");
	print2(arr2, sz2);
	BubbleSort(arr2, sz2, sizeof(char), compare2);
	printf("字符数组排序后：>");
	print2(arr2, sz2);

	return 0;
}