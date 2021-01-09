#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int String_leftSpin(char* s1, char* s2, int n)
{
	char ch = *s1;
	int k = n;
	while (k--)
	{
		if (strcmp(s1, s2) == 0)
			return 1;
		int i = 0;
		ch = *(s1 + 0);//保存第一个字符
		for (i = 0; i < n; i++)
		{
			if (i == n - 1)
			{
				*(s1 + i) = ch;
			}
			else
			{
				*(s1 + i) = *(s1 + i + 1);
			}
		}
	}
	return 0;
}
int main()
{
	char s1[] = "abcd";
	char s2[] = "ACBD";
	int ret = 0;
	int n = sizeof(s1)/sizeof(char)-1;//字符个数
	ret = String_leftSpin(s1, s2, n);
	if (ret == 1)
	{
		printf("s2是s1旋转之后的字符串(*￣︶￣)");
	}
	else
	{
		printf("s2不是s1旋转之后的字符串");
	}
	return 0;
}