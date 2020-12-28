#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	int arr[100] = { 0 };
	int i = 0, j = 0;
	int count = 0;
	while (scanf("%d", &n) != EOF)//多组输入，输入一个正整数
	{
		count = 0;
		for (i = 2; i <= n; i++)/*第1个for循环*/	//对数组进行赋值
			arr[i-2] = i;//将2~n之间的正整数放在数组内存储
		for (i = 0; i < n - 1; i++)/*第2个for循环*/	//arr中有(n-1)个元素
		{
			for (j = i + 1; j < n - 1; j++)/*第3个for循环*/	//将数组中元素2之后的所有能被2
			{							//整除的数清0，再将元素3之后的所有能被3整除的数清0 ，
										//以此类推，直到元素n为止。
				if (arr[i] == 0)//如果arr[i]=0,则退出第3个for循环
					break;
				else if ((arr[j] != 0) && (arr[j] % arr[i] == 0))
					arr[j] = 0;
			}
			if (arr[i] != 0)
				printf("%d ", arr[i]);
			else
				count++;
		}
		printf("\n%d\n", count);
	}
	return 0;
}