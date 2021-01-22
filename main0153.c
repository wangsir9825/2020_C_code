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
int main()
{
	struct ListNode* mylist = BuySListNode(0);
	int item = 0;

	printf("请输入要插入的数据(以-1结束):>");
	while (scanf("%d", &item), item != -1)  //逗号表达式
		SListPushBack(mylist, item);
	printf("翻转前:>");
	SListPrint(mylist);
	printf("翻转后:>");
	SListPrint(reverseList(mylist));
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
//链表转置
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* curr = head;
	while (curr != NULL)
	{
		struct ListNode* nextTemp = curr->next;//备份curr后的节点
		curr->next = prev;//把curr节点连在新链表上
		prev = curr;//把新链表备份
		curr = nextTemp;//准备取下一个节点
	}
	return prev;
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