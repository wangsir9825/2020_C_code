#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//Sleep(1000);
int main()
{
	int flag = 0;
	int input = 0;
	srand((unsigned)time(NULL));
	printf("*************************************\n");
	printf("*************猜数字游戏**************\n");
	printf("******请猜测100内的一个随机数字******\n");
	while (1)
	{
		int random_num = rand() % 100 + 1;

		printf("**请选择：1：开始游戏	0：退出游戏**\n");
		printf("*************************************\n");
		scanf("%d", &flag);

		for (;;)
		{


			if (1 == flag)
			{
				printf("##############输入你猜测的数字###############\n");
				scanf("%d", &input);
				if (input < random_num)
				{
					printf("猜小了\n");
				}
				else if (input > random_num)
				{
					printf("猜大了\n");
				}
				else
				{
					printf("恭喜，猜对了! 正确答案：%d\n\n", random_num);
					printf("*************************************\n");
					break;
				}

			}
			else if (0 == flag)
			{
				printf("游戏结束，记得早日回来！ヾ(￣▽￣)Bye~Bye~\n");
				return 0;
			}
			else
			{
				printf("你输错了，没有该选项，请重新输入\n\n");
				printf("*************************************\n");
				break;
			}
		}

	}

	return 0;
}
