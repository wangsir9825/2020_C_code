#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap_arr(char* arr)
{
	int a = 0, b = 0;
	char c = 0;
	while (arr[b] != '\n')
	{
		b++;
	}
	b -= 1;
	while (a < b)
	{
		c = arr[a];
		arr[a++] = arr[b];
		arr[b--] = c;
	}
}
int main()
{
	char arr[100];
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		arr[i] = getchar();
		if (arr[i] == '\n')
			break;
	}
	swap_arr(arr);
	for (i = 0; arr[i] != '\n'; i++)
	{
		printf("%c", arr[i]);
	}
	return 0;
}