#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char arr[] = "ABCD";
	char Cleaner = '0';
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		Cleaner = arr[i];
		if (((Cleaner != 'A') + (Cleaner == 'C') + (Cleaner == 'D') + (Cleaner != 'D')) == 3)
			printf("凶手是%c", Cleaner);
	}
	return 0;
