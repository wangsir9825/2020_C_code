#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0;
	scanf("%d", &a);
	//printf("%d%d%d%d", a % 10, (a / 10) % 10, (a / 100) % 10, a / 1000);
	while (a != 0)
	{
		printf("%d", a % 10);
		a = a / 10;
	}
	return 0;
}