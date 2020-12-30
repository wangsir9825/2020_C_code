#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fx(int x)
{
	if (x < 0)
		return 1;
	if (x == 0)
		return 0;
	else
		return -1;
}
int main()
{
	int x = 0;
	while (scanf("%d", &x) != EOF)
	{
		printf("%d\n", fx(x));
	}
	return 0;
}