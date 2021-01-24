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

//删除链表中重复的结点
struct ListNode* deleteDuplication(struct ListNode* pHead);

int main()
{
	struct ListNode* mylist = BuySListNode(-1);
	int i = 0;
	//int arr[] = { 1,2,3,3,4,4,5 };
	//int arr[] = { 1,1 };
	int arr[] = { 1,1,2,2,3,3,4,4,5 };

	int n = sizeof(arr) / sizeof(int);
	for (i = 0; i < n; i++)
		SListPushBack(mylist, arr[i]);
	printf("初始链表:>");
	SListPrint(mylist->next);
	printf("去重后的链表:>");
	SListPrint(deleteDuplication(mylist->next));
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
//删除链表中重复的结点
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	if (pHead == NULL && pHead->next == NULL)//如果为空链表或只有一个结点，则直接返回
		return pHead;
	struct ListNode* temp = NULL;
	struct ListNode* pre = NULL;//前驱节点
	struct ListNode* curr = NULL;//后驱节点	
	int flag = 0;

	//购买一个结点，作为首节点：
	struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(s != NULL);
	s->val = 0;//初始节点的内容为0
	s->next = NULL;

	//寻找无重节点
	temp = pHead;
	while (temp != NULL)
	{

		pre = temp;
		curr = temp->next;
		while (curr != NULL)
		{
			if (curr->val != temp->val)//无重点
			{
				pre = curr;
				curr = curr->next;
			}
			else//有重点
			{
				pre->next = curr->next;
				free(curr);//释放重点
				curr = pre->next;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			pHead = temp->next;
			free(temp);//释放首重点
			temp = pHead;
			flag = 0;
		}
		else//不干掉temp
		{
			temp = temp->next;//保持链的剩余部分

			//后插
			curr = s;
			while (curr->next != NULL)//寻找前驱和后驱节点
			{
				curr = curr->next;
			}
			pHead->next = NULL;
			curr->next = pHead;

			pHead = temp;
		}
	}
	pHead = s->next;
	free(s);
	return pHead;
}