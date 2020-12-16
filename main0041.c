#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char ch;
	while (scanf("%c", &ch) != EOF)//使用scanf读入多行数据
	{
		getchar();//getchar函数可以读入多余的回车符
		//if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))//利用小括号改变布尔表达式的优先级
		if (isalpha(ch))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}