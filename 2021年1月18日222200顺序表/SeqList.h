#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include"Sysutil.h"
//顺序表定义

#define ElemType int//定义顺序表保存的元素的类型
#define SEQLIST_DEFAULT_SIZE 8//定义顺序表的默认空间
#define SEQLIST_INC_SIZE 4 //扩容一次增长的空间大小，即每扩容一次，空间增加4个字节

//定义顺序表的数据结构
typedef struct SeqList
{
	ElemType* base;//指向顺序表空间的指针
	size_t    capacity;//容量
	size_t    size;//顺序表中已有的元素个数
}SeqList;
///////////////函数声明/////////////////////////////////
bool IsFull(SeqList* pst);//判断顺序表是否满
bool IsEmpty(SeqList* pst);//判断顺序表是否空
void SeqListInit(SeqList* pst);//顺序表初始化

void SeqListPushBack(SeqList* pst, ElemType x);//尾插 1
void SeqListPushFront(SeqList* pst, ElemType x);//头插 2

void SeqListShow(SeqList* pst);//显示顺序表 3
void SeqListPopBack(SeqList* pst);//从尾部删除 4
void SeqListPopFront(SeqList* pst);//从头部删除 5
size_t SeqListLength(SeqList* pst);//查看顺序表长度 6
size_t SeqListCapacity(SeqList* pst);//查看顺序表容量 7
void SeqListInsertByVal(SeqList* pst, ElemType x);//按值插入 8
void SeqListInsertByPos(SeqList* pst, int pos, ElemType x);//按位置插入 9
void SeqListDeleteByVal(SeqList* pst, ElemType key);//按值删除 10
void SeqListDeleteByPos(SeqList* pst, size_t pos); //按位置删除 11
int SeqListFind(SeqList* pst, ElemType key);//查找元素 12
void SeqListSort(SeqList* pst);//排序 13
void SeqListReverse(SeqList* pst);//顺序表位置翻转 14
void SeqListRemoveAll(SeqList* pst, ElemType key);//移除所有某一元素 15
void SeqListClear(SeqList* pst); //清除 （清除所有元素）16 
void SeqListDestroy(SeqList* pst);//摧毁（把数据表直接释放） 17
int SeqListFindByBinary(SeqList* pst, ElemType key);//二分查找（必须先进行排序） 18
//////////////////函数实现/////////////////////////////////////
//判满（满返回1，不满返回0）
bool IsFull(SeqList* pst)
{
	return pst->size >= pst->capacity;
}

//判空
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}

//扩容函数（返回false说明扩容失败，返回ture说明扩容成功）
//一般约定，以下划线开头命名的函数，代表这个函数只能是内部函数
//用malloc实现扩容
bool _Inc(SeqList* pst)
{
	//申请新空间
	ElemType *new_base = (ElemType*)malloc(sizeof(ElemType)*(pst->capacity+SEQLIST_INC_SIZE));
	if (new_base == NULL)//判断扩容是否成功
	{
		printf("扩容失败.\n");
		return false;
	}
	//拷贝数据
	memcpy(new_base, pst->base, sizeof(ElemType) * pst->capacity);

	//释放旧空间
	free(pst->base);

	//更改base的指向
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}

//用realloc实现扩容
/*
bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQLIST_INC_SIZE));
	if(new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}
*/


//顺序表初始化
void SeqListInit(SeqList* pst)
{
	assert(pst);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL); //开辟空间成功
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);//将内存的值初始化为0
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

//尾插 1
void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))	//当顺序表满了，并且扩容不成功，则提示顺序表满了，注意千万不
	{								//要写成if (!_Inc(pst) && IsFull(pst))否则就会出错,因为逻辑与(&&)具有短路作用
		printf("顺序表已满，%d 不能尾部插入.\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

//头插 2
void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst);
	//判满
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能头部插入.\n", x);
		return;
	}
	//移动数据
	for (int i = pst->size; i > 0; --i)
		pst->base[i] = pst->base[i - 1];

	//头插数据
	pst->base[0] = x;

	//元素个数加1
	pst->size++;
}

//显示顺序表 3
void SeqListShow(SeqList* pst)
{
	assert(pst);
	for (size_t i = 0; i < pst->size; ++i)  //0 1 2 3 4 5
	{
		printf("%d\t", pst->base[i]);
	}
	printf("\n");
}

//尾删 4
void SeqListPopBack(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空, 不能尾部删除.\n");
		return;
	}
	pst->size--;
}

//头删 5
void SeqListPopFront(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空, 不能头部删除.\n");
		return;
	}

	for (size_t i = 0; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

//查看长度 6
size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}

//查看容量 7
size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

//按值插入 8 （插入之前要保证数据有序）
void SeqListInsertByVal(SeqList* pst, ElemType x)
{
	//插入之前要保证数据有序
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能按值插入.\n", x);
		return;
	}

	//寻找位置插入
	int pos = 0;
	while (pos < pst->size && x > pst->base[pos])//寻找应该插入的位置
		pos++;

	for (int i = pst->size; i > pos; --i)//处于pos位置及pos后的数据要往后移动，为新插入的数据留出位置
		pst->base[i] = pst->base[i - 1];

	pst->base[pos] = x;//出入元素
	pst->size++;//元素个数加1
}

//按位置插入 9
void SeqListInsertByPos(SeqList* pst, int pos, ElemType x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，%d 不能按位置插入.\n", x);
		return;
	}
	if (pos<0 || pos>pst->size)
	{
		printf("插入的位置非法，%d 不能按位置插入.\n", x);
		return;
	}

	for (int i = pst->size; i > pos; --i)//元素移动
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

//按值删除 10
void SeqListDeleteByVal(SeqList* pst, ElemType key)
{
	assert(pst);
	int index = SeqListFind(pst, key);
	if (index == -1)
	{
		printf("要删除的元素%d不存在，不能删除.\n", key);
		return;
	}
	//for(int i=index; i<pst->size; ++i)
	//	pst->base[i] = pst->base[i+1];
	//pst->size--;
	SeqListDeleteByPos(pst, index);
}

//按位置删除 11
void SeqListDeleteByPos(SeqList* pst, size_t pos)
{
	//判断位置的合法性
	assert(pst && (pos >= 0 && pos < pst->size));
	for (size_t i = pos; i < pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

////查找元素 12
int SeqListFind(SeqList* pst, ElemType key)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}
	return -1;//查找不到该元素则返回-1
}

////冒泡排序 13
void SeqListSort(SeqList* pst)
{
	for (size_t i = 0; i < pst->size - 1; ++i) //控制趟数
	{
		for (size_t j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				//交换数据
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

//位置翻转 14
void SeqListReverse(SeqList* pst)
{
	assert(pst);
	int start = 0, end = pst->size - 1;
	while (start < end)
	{
		ElemType tmp = pst->base[start];
		pst->base[start] = pst->base[end];
		pst->base[end] = tmp;

		start++;
		end--;
	}
}

//移除所有某一元素 15
void SeqListRemoveAll(SeqList* pst, ElemType key)
{
	assert(pst);
	int index;
	do
	{
		index = SeqListFind(pst, key);//查找元素的位置
		if (index == -1)
			break;
		SeqListDeleteByPos(pst, index);
	} while (1);
}

//清除 （清除所有元素）16 
void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}

//摧毁（把数据表直接释放） 17
void SeqListDestroy(SeqList* pst)
{
	assert(pst);
	free(pst->base);//释放空间
	pst->base = NULL; // 预防野指针
	pst->capacity = pst->size = 0;
}

//二分查找（必须先进行排序） 18
int SeqListFindByBinary(SeqList* pst, ElemType key)
{
	assert(pst);
	SeqListSort(pst); //先保证查找的数据有序

	int low = 0, high = pst->size - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == pst->base[mid])
			return mid;
		else if (key < pst->base[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


#endif /*_SEQLIST_H_*/