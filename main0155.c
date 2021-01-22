#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system、malloc
#include <assert.h>//包括的函数有：assert
typedef int SLTDateType;
struct ListNode {
	int val;
	struct ListNode* next;
};
// 动态申请一个节点
struct ListNode* BuySListNode(SLTDateType x);//购买节点，亦即创建节点
// 单链表尾插
void SListPushBack(struct ListNode* plist, SLTDateType x);
// 单链表打印
void SListPrint(struct ListNode* plist);

//插入排序
struct ListNode* insertionSortList(struct ListNode* head);

int main()
{
	struct ListNode* mylist = BuySListNode(0);
	int item = 0;
	int k = 0;
	for (item = 6; item > 0; item--)
		SListPushBack(mylist, item);
	printf("初始链表:>");
	SListPrint(mylist);
	printf("插入排序后的链表:>");
	SListPrint(insertionSortList(mylist));
	return 0;
}
// 动态申请一个节点
struct ListNode* BuySListNode(SLTDateType x)//购买节点，亦即创建节点
{
	struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(s != NULL);
	s->val = x;//初始节点的内容为x
	s->next = NULL;
	return s;
}
// 单链表尾插
void SListPushBack(struct ListNode* plist, SLTDateType x)
{
	assert(plist);

	struct ListNode* s = BuySListNode(x);//首先创建一个新节点,并将需要插入的值放入这个节点

	struct ListNode* p = plist;//令p指向链表的第一个节点
	if (p == NULL)//如果链表为空，则将新节点作为链表的第一个结点
		plist = s;
	else
	{
		while (p->next != NULL)//利用p查找链表的尾部节点
			p = p->next;
		p->next = s;//找到最后一个节点后，将新节点粘接在链表后面
	}
}
//插入排序
struct ListNode* insertionSortList(struct ListNode* head) {

	struct ListNode* p = NULL;
	struct ListNode* q = head;
	struct ListNode* prev = NULL;
	struct ListNode* curr = NULL;
	if (head != NULL && head->next != NULL)//当链表为空链表或者为空时没有必要进行以下操作
	{
		if (p == NULL)//取头节点
		{
			p = head;//保存头节点
			q = q->next;//第二个节点
			head = q->next;//第三个节点
			p->next = NULL;//断开头节点
		}
		while (q != NULL)
		{
			curr = p;
			prev = p;
			if (q->val < curr->val)//如果目标节点的值小于所有节点的值，则头插
			{
				q->next = curr;
				p = q;
			}
			else//尾插
			{
				while ((curr != NULL) && (q->val >= curr->val))//找到目标节点的前驱节点和后驱节点，加个等于号考虑重复节点
				{
					prev = curr;
					curr = curr->next;
				}
				q->next = curr;//将后驱节点连在目标节点后
				prev->next = q;//将目标节点连在前驱节点后                     
			}
			q = head;//准备取下一个节点
			if (head != NULL)
				head = head->next;
		}
		return p;
	}
	return head;
}

// 单链表打印
void SListPrint(struct ListNode* plist)
{
	struct ListNode* p = plist;
	while (p != NULL)
	{
		printf("%d->", p->val);
		p = p->next;//转到下一个节点
	}
	printf("NULL\n");
}