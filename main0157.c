#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//0, 1, 2, 3, 4, 5, 6, 7, 8
#define size 9
int main()//1维数组找7 i*size + j
{
	int b[size] = { 3,1,4,1,5,9,2,6,7 };
	int i = 2;
	int num1 = b[i];
	int num2 = *(b + i);
	int num3 = *b + i;

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);

	return 0;
}


//#define size 2
//int main()//二维数组找9 i*size + j
//{
//	int b[3][size] = { 3,16,4,1,5,9 };
//
////3, 16
////4, 1
////5, 9
//	int i = 2;
//	int j = 1;
//	//一般元素
//	int num1 = b[i][j];
//
//	int num2 = *(b[i] + j);
//	int num3 = *(*(b + i) + j);
//	int num4 = (*(b + i))[j];
//	int num5 = *(*b + i * size + j);//有警告
//
//	//列边元素5
//	int num6 = b[2][0];
//
//	int num7 = *(b[2] + 0);
//	int num8 = *(*(b + 2)+0);
//	int num9 = (*(b + 2))[0];
//	int num10 = *(*b+2*size+0);
//	//去0
//	int num11 = *(b[2]);
//	int num12 = *(*(b + 2));
//	//int num13 = (*(b + 2))[0];
//	int num13 = *(*b + 2 * size);
//	//去括号
//	int num14 = *b[2];
//	int num15 = **(b + 2);
//	int num16 = *(b + 2)[0];
//	//int num17 = *(*b + 2 * size);
//
//	//行边元素16
//	int num18 = b[0][1];
//
//	int num19 = *(b[0] + 1);
//	int num20 = *(*(b + 0) + 1);
//	int num21 = (*(b + 0))[1];
//	int num22 = *(*b + 0 * size + 1);
//	//去0
//	//int num11 = *(b[0] + 1);
//	int num23 = *(*(b) + 1);
//	int num24 = (*(b))[1];
//	int num25 = *(*b + 1);
//	//去括号
//	//int num14 = *(b[0] + 1);
//	int num26 = *(*b + 1);
//	int num27 = (*b)[1];
//	//int num28 = *(*b + 1);
//
//	//角元素3
//	int num28 = b[0][0];
//
//	int num29 = *(b[0] + 0);
//	int num30 = *(*(b + 0) + 0);
//	int num31 = (*(b + 0))[0];
//	int num32 = *(*b + 0 * size + 0);
//	//去0
//	int num33 = *(b[0]);
//	int num34 = *(*(b));
//	int num35 = (*(b))[0];
//	int num36 = *(*b);
//	//去括号
//	int num37 = *b[0];
//	int num38 = **b;
//	//int num39 = *b[0];
//	//int num40 = **b;
//
//	printf("num1 = %d\n", num1);
//	printf("num2 = %d\n", num2);
//	printf("num3 = %d\n", num3);
//	printf("num4 = %d\n", num4);
//	printf("num5 = %d\n", num5);
//	printf("num6 = %d\n", num6);
//	printf("num7 = %d\n", num7);
//	printf("num8 = %d\n", num8);
//	printf("num9 = %d\n", num9);
//	printf("num10 = %d\n", num10);
//	printf("num11 = %d\n", num11);
//	printf("num12 = %d\n", num12);
//	printf("num13 = %d\n", num13);
//	printf("num14 = %d\n", num14);
//	printf("num15 = %d\n", num15);
//	printf("num16 = %d\n", num16);
//
//	printf("num18 = %d\n", num18);
//	printf("num19 = %d\n", num19);
//	printf("num20 = %d\n", num20);
//	printf("num21 = %d\n", num21);
//	printf("num22 = %d\n", num22);
//	printf("num23 = %d\n", num23);
//	printf("num24 = %d\n", num24);
//	printf("num25 = %d\n", num25);
//	printf("num26 = %d\n", num26);
//	printf("num27 = %d\n", num27);
//
//	printf("num28 = %d\n", num28);
//	printf("num29 = %d\n", num29);
//	printf("num30 = %d\n", num30);
//	printf("num31 = %d\n", num31);
//	printf("num32 = %d\n", num32);
//	printf("num33 = %d\n", num33);
//	printf("num34 = %d\n", num34);
//	printf("num35 = %d\n", num35);
//	printf("num36 = %d\n", num36);
//	printf("num37 = %d\n", num37);
//	printf("num38 = %d\n", num38);
//
//	return 0;
//}