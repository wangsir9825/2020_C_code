#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int my_strlen(const char* arr)
{
	const char* ret = arr;
	while (*ret++);
	return ret - arr-1;
}
int main()
{
	char arr[20] = "abcdef";
	printf("%d\n", my_strlen(arr));
	system("pause");
	return 0;
}