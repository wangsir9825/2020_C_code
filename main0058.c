#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int t = 0;
	while (scanf("%d", &t) != EOF)//当输入字母时，会出错，陷入死循环
	{
		if (t == '\n')
			continue;
		if (t > 0)
			printf("1\n");
		else if (t == 0)
			printf("0.5\n");
		else
			printf("0\n");
	}
	return 0;
}