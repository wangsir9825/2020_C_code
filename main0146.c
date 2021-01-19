#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system realloc
#include <assert.h>//包括的函数有：assert
#include <string.h>//包括的函数有：memset、
#define SEQLIST_DEFAULT_SIZE 1//定义默认开辟的空间大小为1个元素，只能为1，不要乱改，否则以下代码要改变
#define SEQLIST_INC_SIZE 1 //每扩容一次，增加1个元素，只能为1，不要乱改，否则以下代码要改变
//void Init(int* pst)
//{
//	pst = (int*)malloc(sizeof(int) * SEQLIST_DEFAULT_SIZE);
//	assert(pst != NULL); //开辟空间成功判断
//	memset(pst, 0, sizeof(int) * SEQLIST_DEFAULT_SIZE);//将内存的值初始化为0
//}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	int ASize1 = ASize;
	while (K)
	{
		if (ASize1 != 0)//将K值加到数组上
		{
			ASize1--;
			K += *(A + ASize1);//将顺序表中的元素加在K上
			*(A + ASize1) = (K % 10);//将K的最低位存入顺序表
			K /= 10;//去掉最低位
		}
		else//内存不足则扩容
		{
			int* new_base = (int*)realloc(A, sizeof(int) * (ASize + 1));//扩充一个元素的容量
			if (new_base == NULL)
			{
				printf("扩容失败.\n");
				return NULL;
			}
			A = new_base;
			ASize += 1;//空间增加		
			for (int i = ASize - 1; i > 0; --i)//顺序表的数据往后移动
				A[i] = A[i - 1];
			//头插数据
			A[0] = (K % 10);//将K的最低位存入顺序表
			K /= 10;//去掉最低位
		}
	}
	*returnSize = ASize;
	return A;
}

void Destroy(int* pst, int* ASize)//摧毁（把申请的动态内存直接释放）
{
	assert(pst);
	free(pst);//释放空间
	pst = NULL; // 预防野指针
	*ASize = 0;
}
int main()
{
	int* A = (int*)malloc(sizeof(int) * SEQLIST_DEFAULT_SIZE);
	assert(A != NULL); //开辟空间成功判断
	memset(A, 0, sizeof(int) * SEQLIST_DEFAULT_SIZE);//将内存的值初始化为0
	int ASize = 0;	
	int K = 0;
	int returnSize = 0;
	//Init(A);//将A指向的空间进行初始化
	ASize = SEQLIST_DEFAULT_SIZE;
	int i = 0;
	printf("请输入一个数组，以空格隔开:>");
	while (1)//给A赋值
	{
		scanf("%d", A + i);
		if (getchar() == '\n')//吸收空格和回车
			break;
		else
		{
			i++;
			int* new_base = (int*)realloc(A, sizeof(int) * (ASize + SEQLIST_INC_SIZE));//扩充一个元素的容量
			if (new_base == NULL)
			{
				printf("扩容失败.\n");
				return NULL;
			}
			A = new_base;
			ASize += SEQLIST_INC_SIZE;//空间增加		
		}
	}
	printf("请输入一个非负整数:>");
	scanf("%d", &K);
	addToArrayForm(A, ASize, K, &returnSize);
	ASize = returnSize;
	for (i = 0; i < ASize; i++)//向顺序表中写入数据
	{
		printf("%d ", A[i]);
	}
	Destroy(A, &ASize);//摧毁A,防止内存泄露
	system("pause");//暂停一下
	return 0;
}