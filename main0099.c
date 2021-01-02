#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h> 
int main()
{
	char arr1[50] = { '0' };
	char arr2[50] = { '0' };
	scanf("%s %s", arr1, arr2);
	if (strcmp(arr1, arr2) == 0)//字符串变量可以直接比较大小，但字符数组不可以
		printf("same\n");
	else
		printf("different\n");
	return 0;
}