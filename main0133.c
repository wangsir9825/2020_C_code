#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int compare1(const void* eleml, const void* elem2)
{
	return *(int*)eleml - *(int*)elem2;
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
void testint()
{
	int arr1[] = { 1,5,9,8,7,3,2,4,6,0 };
	int sz1 = sizeof(arr1) / sizeof(int);	
	printf("整型数组排序前：>");
	print1(arr1, sz1);
	qsort(arr1, sz1, sizeof(int), compare1);
	printf("整型数组排序后：>");
	print1(arr1, sz1);
}
int compare2(const void* eleml, const void* elem2)
{
	return *(char*)eleml - *(char*)elem2;
}
void print2(char* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
}
void testchar()
{
	char arr2[] = "zxcvbnmasdfghjklqwertyuiop";
	int sz2 = sizeof(arr2) / sizeof(char) - 1;
	printf("字符数组排序前：>");
	print2(arr2, sz2);
	qsort(arr2, sz2, sizeof(char), compare2);
	printf("字符数组排序后：>");
	print2(arr2, sz2);
}
int compare3(const void* eleml, const void* elem2)
{
	if ((*(float*)eleml - *(float*)elem2) > 0)
		return 1;
	if ((*(float*)eleml - *(float*)elem2) < 0)
		return -1;
	else
		return 0;
}
void print3(float* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}
void testfloat()
{
	float arr[] = { 1.5f,5.2f,4.8f,8.3f,0.2f };
	int sz = sizeof(arr) / sizeof(float);
	printf("浮点型数组排序前：>");
	print3(arr, sz);
	qsort(arr, sz, sizeof(float), compare3);
	printf("浮点型数组排序后：>");
	print3(arr, sz);
}
struct stu
{
	char name[20];
	int age;
};
int compare4(const void* eleml, const void* elem2)//按年龄排序
{
		return ((struct stu*)eleml)->age - ((struct stu*)elem2)->age;
}
void print4(struct stu* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s,%d\t", arr[i].name, arr[i].age);
	}
	printf("\n");
}

void teststruct()
{
	struct stu arr[3] = { {"Liang Ximeng", 24}, {"Xue Mengyuan",25}, {"Yi Jinyu",23} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("结构体型数组排序前：>");
	print4(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), compare4);
	printf("结构体型数组排序后：>");
	print4(arr, sz);
}
int main()
{
	testint();
	testchar();
	testfloat();
	teststruct();
	return 0;
}