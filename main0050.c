#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//12345 1 2345	12  345		123 45		1234 5
int main()
{
	int i = 0;
	for (i = 10000; i <= 99999; i++)
	{
		if (((i / 10000) * (i % 10000) + (i / 1000) * (i % 1000) + (i / 100) * (i % 100) + (i / 10) * (i % 10)) == i)
			printf("%d ", i);
	}
	return 0;
}
/*
int main() {

	//遍历所有的五位数，从10000开始
	for(int i = 10000; i <= 99999; i++) {
		//设置当前和，除数
		int sum = 0, mod = 10000, cur = i;
		//循环直到mod/10为0
		while(mod / 10) {
			//根据公式计算当前的除数和余数，进行累计求和
			sum += (cur % mod) * (cur / mod);
			//更新mod
			mod /= 10;
		}
		//判断是否满足水仙花数
		if(i == sum)
			printf("%d ", i);
	}
	return 0;
}