#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char arr[3][3] = { '0' };
	//int knum = 0;
	//int bnum = 0;
	char ch = 'O';
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%c", &arr[i][j]);
			getchar();//吸收回车和空格
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])//行检测
		{
			ch = arr[i][0];
			break;
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])//列检测
		{
			ch = arr[0][i];
			break;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])//主对角线检测
	{
		ch = arr[1][1];
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2])//副对角线检测
	{
		ch = arr[1][1];
	}
	if (ch == 'K')
	{
		printf("KiKi wins!\n");
		return 0;
	}
	else if (ch == 'B')
	{
		printf("BoBo wins!\n");
		return 0;
	}
	else
	{
		printf("No winner!\n");
	}

	//for (i = 0; i < 3; i++)
	//{
	//	if (i == 0)
	//	{
	//		if ((arr[0][0] == 'K') && (arr[1][1] == 'K') && (arr[2][2] == 'K'))//主对角线检测
	//		{
	//			printf("KiKi wins!\n");
	//			return 0;
	//		}
	//		if ((arr[0][0] == 'B') && (arr[1][1] == 'B') && (arr[2][2] == 'B'))//主对角线检测
	//		{
	//			printf("BoBo wins!\n");
	//			return 0;
	//		}
	//		if ((arr[2][0] == 'K') && (arr[1][1] == 'K') && (arr[0][2] == 'K'))//副对角线检测
	//		{
	//			printf("KiKi wins!\n");
	//			return 0;
	//		}
	//		if ((arr[2][0] == 'B') && (arr[1][1] == 'B') && (arr[0][2] == 'B'))//副对角线检测
	//		{
	//			printf("BoBo wins!\n");
	//			return 0;
	//		}
	//	}
	//	if((arr[i][0] == 'K') && (arr[i][1] == 'K') && (arr[i][2] == 'K'))//行检测
	//	{
	//		printf("KiKi wins!\n");
	//		return 0;
	//	}
	//	if ((arr[i][0] == 'B') && (arr[i][1] == 'B') && (arr[i][2] == 'B'))//行检测
	//	{
	//		printf("BoBo wins!\n");
	//		return 0;
	//	}
	//	if ((arr[0][i] == 'K') && (arr[1][i] == 'K') && (arr[2][i] == 'K'))//列检测
	//	{
	//		printf("KiKi wins!\n");
	//		return 0;
	//	}
	//	if ((arr[0][i] == 'B') && (arr[1][i] == 'B') && (arr[2][i] == 'B'))//列检测
	//	{
	//		printf("BoBo wins!\n");
	//		return 0;
	//	}
	//}
	//printf("No winner!\n");
	return 0;
}