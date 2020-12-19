#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char ch = '0';
	while (scanf("%c", &ch) != EOF)
	{
		if (ch == '\n')//忽略回车
			continue;
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			printf("%c is an alphabet.\n", ch);
		else
			printf("%c is not an alphabet.\n", ch);
	}
	return 0;
}