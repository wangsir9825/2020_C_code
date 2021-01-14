#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* my_strcat(char* des, const char* src)
{
	assert(des != NULL);
	assert(src != NULL);
	char* ret = des;
	while (*des != '\0')
	{
		des++; 
	}
	while (*des++ = *src++);
	return ret;
}
int main()
{
	char arr[20] = "abc";
	printf("%s\n", my_strcat(arr, "def"));
	system("pause");
	return 0;
}