#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char ch = '0';
	while (scanf("%c", &ch) != EOF)
	{
		if (ch == '\n')//忽略回车
			continue;
		if (ch >= 'A' && ch <= 'Z')
			printf("%c\n", ch + 32);
		else if (ch >= 'a' && ch <= 'z')
			printf("%c\n", ch - 32);
		else
			printf("%c\n", ch);
	}
	return 0;
}