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
//链表转置
struct ListNode* reverseList(struct ListNode* head);
// 单链表打印
void SListPrint(struct ListNode* plist);
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k);
int main()
{
	struct ListNode* mylist = BuySListNode(0);
	int item = 0;
	int k = 0;
	for (item = 1; item < 6; item++)
		SListPushBack(mylist, item);
	printf("初始链表:>");
	SListPrint(mylist);
	printf("需要输出链表中倒数第几个结点:>");
	scanf("%d", &k);
	printf("%d\n", (FindKthToTail(mylist, k))->val);
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
void SListPushBack(struct ListNode* plist, SLTDateType x);
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
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* pList1 = pListHead;
	struct ListNode* pList2 = pListHead;
	for (int i = 0; i < k; i++)
	{
		if (pList2 == NULL)
			return NULL;
		pList2 = pList2->next;
	}
	while (pList2)
	{
		pList1 = pList1->next;
		pList2 = pList2->next;
	}
	return pList1;
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