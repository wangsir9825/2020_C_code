#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)//对10取余，获取个位上的数
		{
			j++;
		}
		if (i / 10 == 9)//对10取整，获取十位上的数
		{
			j++;
		}
	}
	printf("总共出现 %d 个数字9\n", j);
	return 0;
}