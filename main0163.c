#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, num = 0;
	int C, M, F;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &C, &M, &F);
		if ((C + M + F) / 3 < 60)
			num++;
	}
	printf("%d", num);
	return 0;
}