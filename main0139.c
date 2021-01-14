#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char *p1 = "abc";
	char* p2 = "abf";
	int n = my_strcmp(p1, p2);
	if (n > 0)
	{
		printf("字符串p1大于字符串p2\n");
	}
	else if (n == 0)
	{
		printf("字符串p1等于字符串p2\n");
	}
	else
	{
		printf("字符串p1小于字符串p2\n");
	}
	system("pause");
	return 0;
}