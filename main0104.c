#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int N = 0;
	int sum = 0;
	int num = 0;
	int i = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		sum += num;
	}
	printf("%d\n", sum);
	return 0;
}