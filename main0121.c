#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Base(int num, int bse)
{
	if (num >= bse)
	{
		printf("%d", Base(num / bse, bse));
		return num % bse;
	}
	else
		return num % bse;
}
int main()
{
	int bse = 6;//6进制
	int num = 0;
	scanf("%d", &num);
	printf("%d", Base(num, bse));
	return 0;
}