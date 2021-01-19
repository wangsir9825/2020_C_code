#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system realloc
#include <assert.h>//包括的函数有：assert
#include <string.h>//包括的函数有：memset、

#define ElemType int//定义顺序表保存的元素的类型
#define SEQLIST_DEFAULT_SIZE 1//定义顺序表的默认空间
#define SEQLIST_INC_SIZE 1 //每扩容一次，增加1个元素

//定义顺序表的数据结构
typedef struct SeqList
{
	ElemType* base;//指向顺序表空间的指针
	int    capacity;//容量
	int    size;//顺序表中已有的元素个数
}SeqList;

//顺序表初始化
void SeqListInit(SeqList* pst)
{
	assert(pst);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL); //开辟空间成功判断
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);//将内存的值初始化为0
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	int ASize1 = ASize;
	while (K)
	{
		if (ASize1 != 0)
		{
			ASize1--;
			K += *(A + ASize1);//将顺序表中的元素加在K上
			*(A + ASize1) = (K % 10);//将K的最低位存入顺序表
			K /= 10;//去掉最低位
		}
		else
		{
			ElemType* new_base = (ElemType*)realloc(A, sizeof(ElemType) * (ASize + SEQLIST_INC_SIZE));//扩充一个元素的容量
			if (new_base == NULL)
			{
				printf("扩容失败.\n");
				return NULL;
			}
			A = new_base;
			ASize += SEQLIST_INC_SIZE;//空间增加		
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

int main()
{
	ElemType K = 0;
	SeqList mylist;//定义顺序表
	SeqListInit(&mylist);//顺序表初始化，确定其大小
	ElemType* A;//定义指向顺序表空间的指针
	A = mylist.base;
	int i = 0;
	printf("请输入一个数组，以空格隔开:>");
	while (1)
	{
		scanf("%d", A + i);
		if (getchar() == '\n')//吸收空格和回车
			break;
		else		
		{
			i++;
			ElemType* new_base = (ElemType*)realloc(A, sizeof(ElemType) * (mylist.capacity + SEQLIST_INC_SIZE));//扩充一个元素的容量
			if (new_base == NULL)
			{
				printf("扩容失败.\n");
				return NULL;
			}
			A = new_base;
			mylist.capacity += SEQLIST_INC_SIZE;//空间增加		
		}
	}
	mylist.size = i + 1;
	int ASize = mylist.size;
	printf("请输入一个非负整数:>");
	scanf("%d", &K);
	int returnSize = mylist.size;

	addToArrayForm(A, ASize, K, &returnSize);
	mylist.size = returnSize;
	mylist.capacity = returnSize;
	for (i = 0; i < mylist.size; i++)//向顺序表中写入数据
	{
		printf("%d ", A[i]);
	}
	return 0;
}