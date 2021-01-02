#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int max = 0;//给最大值初始化为最小值
	int min = 100;//给最小值初始化为最大值
	int i = 0;
	int grade = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &grade);
		if (max < grade)
			max = grade;
		if (min > grade)
			min = grade;
	}
	printf("%d", max - min);
	return 0;
}