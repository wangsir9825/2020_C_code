#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char arr[20];
	int i = 0;
	int a = 0;
	int b = 0;
	scanf("%s", arr);
	while (arr[i] != '0')
	{
		if (arr[i] == 'A')
			a++;
		if (arr[i] == 'B')
			b++;
		i++;
	}
	if (a > b)
		printf("A");
	else if (a < b)
		printf("B");
	else
		printf("E");
	return 0;
}
/*
	char ch = 0;
	//循环读取投票
	while(scanf("%c", &ch) != EOF) {
		//当前字符为0则退出
		if(ch == '0')
			break;
		//统计a的票数，同理也要统计b的票数
		if(ch == 'A')
			a_count++;
		if(ch == 'B')
			b_count++;
	}
*/
