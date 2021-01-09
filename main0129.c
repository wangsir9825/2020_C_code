#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void String_leftSpin(char* parr, int n, int k)
{
	char ch = *parr;
	while (k--)
	{
		int i = 0;
		ch = *(parr + 0);//保存第一个字符
		for (i = 0; i < n; i++)
		{
			if (i == n-1)
			{
				*(parr + i) = ch;
			}
			else
			{
				*(parr + i) = *(parr + i + 1);
			}
		}
	}
}
int main()
{

	int k = 1;//偏移量
	int n = 4;//字符个数
	printf("请输入左旋字符个数k>");
	while (scanf("%d", &k) != EOF)//输入三次Ctrl+z退出死循环
	{
		char arr[] = "ABCD";
		String_leftSpin(arr, n, k);
		printf("%s\n", arr);
		printf("请输入左旋字符个数k>");
	}
	return 0;
}