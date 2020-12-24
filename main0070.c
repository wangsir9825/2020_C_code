#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define size 3
void init()//初始化函数
{
/***************************************
函数功能：
	输出初始化游戏启动菜单。
函数输入：
	无
函数输出：
	无
***************************************/
	printf("*********************\n");
	printf("*******三子棋********\n");
	printf("**1.play    0.exit***\n");
	printf("*********************\n");
}
int test(int (*arr)[size])
{
	/***************************************
	函数功能：
		判断棋盘结果
	函数输入：
		arr：
			=red，红方棋盘判断
			=blue，蓝方棋盘判断
	函数输出：
		无
	***************************************/
	int i, j;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int count = 0;
	for (i = 0; i < size; i++)//（行列每次检测三次）
	{
		for (j = 0; j < size; j++)
		{
			if (arr[j][i])//列检测
				a += 1;
			if (arr[i][j])
			{
				b += 1;//行检测
				count ++;// 和局判断
			}	
			if (i == 0)//对角线只需检测一次
			{
				c += arr[j][j];//主对角线检测
				d += (*arr)[2 * (j + 1)];//副对角线检测
			}
		}
		if (a == 3 || b == 3 || c == 3 || d == 3)
		{
			return 0;//返回0就是胜利
		}
		else
		{
			a = 0;//清零，为下一列检测做准备
			b = 0;
			//c = 0;	
			//d = 0;			
		}
	}
	if (count == 5)//当count等于5时，说明平局。该检测针对红方，因为红方为先手，当红方棋子达到5个时，则为平局
	{
		return 1;
	}
	else
	{
		return 2;
	}

}
int JGPD(int* shift, int (*red)[size], int (*blue)[size])//结果判断
{
	switch (*shift)
	{
	case 0:
		if(test(red) == 1)
		{
			return 1;//平局
		}
		else if (test(red) == 0)
		{
			return 2;//红胜
		}
		else
		{
			*shift = 1;//红方下完，转换成对手下棋状态
			return 0;//继续战斗
		}
		break;
	case 1:
		if (test(blue) == 0)
		{
			return 3;
		}
		else
		{
			*shift = 0;//蓝方下完，转换成对手下棋状态
			return 0;
		}
		break;
	default:
		return 0;
		break;
	}
}
void QSLZ(int* shift, int(*red)[size], int(*blue)[size], int(*green)[size])
{
/***************************************
函数功能：
	棋手落子，存储棋盘信息
函数输入：
	shift：（shift的值只能取0和1）
		=0，红方落子
		=1，蓝方落子
	red：红方棋盘信息
	blue：蓝方棋盘信息
	green:红蓝双方的信息
函数输出：
	无
***************************************/
	int x, y;
	switch (*shift)
	{
	case 0:
		do
		{
			printf("红方（O）请输入坐标:>");
			scanf("%d%d", &x, &y);
			if (x > 2 || y > 2)
				printf("坐标位置输入越界(ー00ー)\n");
			else if (green[x][y] == 1)
				printf("该位置已被人占(＾＿－)\n");
			else
				red[x][y] = 1;
		}while ((x > 2 || y > 2)||(green[x][y] == 1));
		green[x][y] = 1;
		break;
	case 1:
		do
		{
			printf("蓝方（X）请输入坐标:>");
			scanf("%d%d", &x, &y);
			if (x > 2 || y > 2)
				printf("坐标位置输入越界(ー00ー)\n");
			else if (green[x][y] == 1)
				printf("该位置已被人占(＾＿－)\n");
			else
				blue[x][y] = 1;
		} while ((x > 2 || y > 2) || (green[x][y] == 1));
			green[x][y] = 1;
		break;
	default :
		printf("出错了么(*￣rǒ￣)");
		break;
	}
}
void DYQP(int (*red)[size], int (*blue)[size])//打印棋盘
{
	int i, j;
	printf("	0	1	2\n\n");
	for (i = 0; i < size; i++)
	{
		printf("%d", i);
		for (j = 0; j < size; j++)
		{
			if (red[i][j] == 1)
				printf("	O");
			else if (blue[i][j] == 1)
				printf("	X");
			else
				printf("	#");
		}
		printf("\n");
	}

	//printf("    |    |    \n");
	//printf("    |    |    \n");
	//printf("————————\n");
	//printf("    |    |    \n");
	//printf("    |    |    \n");
	//printf("————————\n");
	//printf("    |    |    \n");
	//printf("    |    |    \n");
}
int play()//玩游戏
{
/***************************************
函数功能：
	实现游戏功能
函数输入：
	无
函数输出：
	0：表示游戏结束
***************************************/
/*-----------------初始化------------------------*/
	int red[3][3] = { 0 };//红方棋盘信息矩阵
	int blue[3][3] = { 0 };//蓝方棋盘信息矩阵
	int green[3][3] = { 0 };//棋盘总信息矩阵
	int mat[3][3] = { 0 };//用于判断的矩阵
	DYQP(red, blue);//显示初始棋盘
	int shift = 0;//切换选手（使两个人交替下棋）
	int state = 0;//鹿死谁手？（state用于储存棋局的结果）
/*---------------------------------------------*/
	while (1)
	{
		QSLZ(&shift, red, blue, green);//棋手落子
		DYQP(red, blue);//打印棋盘
		state = JGPD(&shift, red, blue);//结果判断
		switch (state)
		{
		case 0:
			printf("继续，注意：观棋不语\n");
			break;
		case 1:
			printf("和局\n");
			return 0;
		case 2:
			printf("红方胜\n");
			return 0;
		case 3:
			printf("蓝方胜\n");
			return 0;
		default://state
			printf("程序又出错了么(ಥ﹏ಥ)\n");
			return 0;//游戏中断
		}
	}
	return 0;
}
int main()
{
	int state = 0;
	init();//初始化菜单
	loop: scanf("%d", &state);//输入选择状态
	switch (state)
	{
	case 0:
		printf("游戏结束。");
		break;
	case 1:
		printf("游戏开始：\n");
		play();//玩游戏
		break;
	default:
		printf("输错了，请重新输入:>");

		goto loop;
		break;
	}
	return 0;
}