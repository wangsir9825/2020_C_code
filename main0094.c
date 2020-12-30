#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int N = 0;
	int odd = 0;//奇数个数
	int even = 0;//偶数个数,偶数是能够被2所整除的整数
	int i = 0;
	while (scanf("%d", &N) != EOF)
	{
		odd = 0;//清零,为下一次判断做准备
		even = 0;//清零
		for (i = 1; i <= N; i++)
		{
			if (i % 2)
				odd++;
			else
				even++;
		}
		printf("%d %d\n", odd, even);
	}
	return 0;
}