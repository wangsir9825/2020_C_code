#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct Node
{
	int data;
	struct Node* next;
};
int main()
{
	printf("%d", sizeof(struct Node));
	return 0;
}