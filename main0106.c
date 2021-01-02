#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int num = 0;
	int N = 0;
	int num1 = 0;
	int sheng = 0;
	int jiang = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (0 == i)
		{
			num1 = num;
		}
		else
		{
			if (num1 <= num)
			{
				sheng++;
			}
			else if (num1 >= num)
			{
				jiang++;
			}
			num1 = num;
		}
	}
	if (N - 1 == sheng || N - 1 == jiang)
		printf("sorted\n");
	else
		printf("unsorted\n");
	return 0;
}