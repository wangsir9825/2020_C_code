#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void my_swap(int* m, int* n)
{
	*m = *m ^ *n;
	*n = *m ^ *n;
	*m = *m ^ *n;
}

int main()
{
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	printf("交换前：\nm=%d\nn=%d\n", m, n);
	my_swap(&m, &n);
	printf("交换后：\nm=%d\nn=%d", m, n);
	return 0;
}