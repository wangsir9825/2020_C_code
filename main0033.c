#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int retn_bit(int n)
{
	int num = 0;
	int i = 0;
	int n_bit = 0;
	for (i = 0; i < 32; i++)
	{
		n_bit = n << i;//从高位开始检验二进制位
		n_bit = n_bit >> 31;
		//printf("%d\n", n_bit);
		if (n_bit)
		{	
			num++;
		}
	}
	return num;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", retn_bit(n));
	return 0;
}