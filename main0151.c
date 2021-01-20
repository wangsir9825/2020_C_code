#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system
#include <assert.h>//包括的函数有：assert

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
typedef struct SList//将链表封装为结构体，这样更方便管理（结构体内部保存的是链表结点指针，这个指针要指向链表的第一个结点，这样就可以用它来代表整个链表）
{
	SListNode* head;  //成员封装
}SList;
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SList* plist);
int main()
{
	SList mylist;
	mylist.head = NULL;//链表首结点的指针为空，则代表该指针指向的链表为“空链表”

	SLTDateType item, key;
	SListNode* pos;

	SListNode* p;//用于保存要查找的值

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("*************当前链表的元素有：*************\n");
		SListPrint(mylist.head);//显示顺序表
		printf("********************************************\n");
		printf("* [1] push_back         [2] push_front      *\n");//尾插和头插
		printf("* [3] show_list         [0] quit_system     *\n");//显示和退出
		printf("* [4] pop_back          [5] pop_front       *\n");//尾删和头删
		printf("* [6] find              [7] insert_pos      *\n");//查找元素和按位置插入
		printf("* [8] delete_pos        [9] destroy         *\n");//按位置删除、销毁
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1://尾插
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushBack(&(mylist.head), item);
			break;
		case 2://头插
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushFront(&(mylist.head), item);
			break;
		case 3://显示
			SListPrint(mylist.head);
			break;
		case 4://从尾部删除 4
			SListPopBack(&(mylist.head));
			break;
		case 5://从头部删除 5
			SListPopFront(&(mylist.head));
			break;
		case 6://查找元素 6
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SListFind(mylist.head, key);
			if (p == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d存在.\n", key);
			break;
		case 7:
			printf("在链表的第一个节点后插入一个值\n");
			pos = mylist.head;
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SListInsertAfter(pos, item);
			break;
		case 8:
			printf("删除的链表的第一个节点后的值\n");
			pos = mylist.head;
			SListEraseAfter(pos);
			break;
		case 9://清除 （清除所有元素）16 
			SListDestory(&mylist);
			break;
		}
		//system("pause");
		//system("cls");
	}
	SListDestory(&mylist);
	return 0;
}
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)//购买节点，亦即创建节点
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;//初始节点的内容为x
	s->next = NULL;
	return s;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* p = plist;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;//转到下一个节点
	}
	printf("Over.\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* s = BuySListNode(x);//首先创建一个新节点,并将需要插入的值放入这个节点

	SListNode* p = *pplist;//令p指向链表的第一个节点
	if (p == NULL)//如果链表为空，则将新节点作为链表的第一个结点
		*pplist = s;
	else
	{
		while (p->next != NULL)//利用p查找链表的尾部节点
			p = p->next;
		p->next = s;//找到最后一个节点后，将新节点粘接在链表后面
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);//合法检查
	SListNode* s = BuySListNode(x); //创建新节点，存储数据

	s->next = *pplist;//将新节点粘接在链表前面
	*pplist = s;//将新节点设置为第一个结点
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);//传入的结构体指针不能为空，但链表可以为空
	SListNode* p = *pplist;

	if (p != NULL) //如果链表为空链表，则不进行删除
	{
		if (p->next == NULL) // 如果链表只有一个节点，则该结点为最后一个结点
			pplist = NULL;//则将链表设置为空链表
		else//如果链表有多个结点
		{
			SListNode* pre = NULL;
			while (p->next != NULL)//先找到最后一个结点
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;//找到最后一个结点之后，将其删除
		}
		free(p);//摧毁最后一个结点（释放结点）
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist) 
{
	assert(pplist);
	SListNode* p = *pplist;//令p指向链表的第一个结点
	if (p != NULL)
	{
		*pplist = p->next;//将第二个结点设置为第一个结点
		free(p);////摧毁原第一个结点（释放结点）
	}
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	//找到返回节点的地址
	//找不到返回NULL
	assert(plist);
	SListNode* p = plist;

	while (p != NULL && p->data != x)//不要写成while (p->data != x && p != NULL)，否则当查找的值不存在时，程序会崩溃，原因就是当p=NULL时，p->data为非法操作
		p = p->next;
	return p;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{

	SListNode* s = BuySListNode(x);//为要插入的值购买一个“目标节点”
	if (pos == NULL)//如果是空链表则直接插在首节点上
		pos = s;
	else
	{
		s->next = pos->next;//将后驱节点连接在目标节点后
		pos->next = s;//将目标节点连接在前驱节点后
	}
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);//传入的pos位置不能为空
	SListNode* p = pos->next;//将目标节点（即要删除的节点）保存

	if (p != NULL) //如果目标节点之后无节点，则不进行删除
	{
		pos->next = p->next;//将目标节点覆盖
		free(p);//摧毁目标节点（释放目标节点）
	}
}

// 单链表的销毁
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;  //从头往后删
		free(p);
		p = plist->head;
	}
}