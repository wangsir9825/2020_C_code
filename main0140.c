#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcpy(char* des, const char* src)
{
	char* ret = des;
	assert(des != NULL);
	assert(src != NULL);
	while (*des++ = *src++);
	return ret;
}
int main()
{
	char arr[20] = "abcdef";
	printf("%s\n", my_strcpy(arr, "123456"));
	system("pause");
	return 0;
}