#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int num = 0;
	while (scanf("%d", &num) != EOF)
	{
		if (num % 2)
			printf("Odd\n");
		else
			printf("Even\n");
	}
	//int val = 0;
	////循环读入数据
	//while (scanf("%d", &val) != EOF) {
	//	int ret = val & 0x01;
	//	//判断与操作之后的结果是否奇偶
	//	if (ret == 1)
	//		printf("Odd\n");
	//	else
	//		printf("Even\n");
	//}

	return 0;
}