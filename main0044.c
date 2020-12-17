#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_strlen(const char* arr)
{
	if (*arr == '\0')
		return 0;
	return 1 + my_strlen(arr + 1);
}
int main()
{
	char arr[] = "abcdef";
	printf("%d", my_strlen(arr));
	return 0;
}