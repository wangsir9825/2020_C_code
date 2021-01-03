#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int N = 0;
	int arr[50] = { 0 };
	int i = 0;
	int num = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &num);
	int flag = 0;
	for (i = 0; i < N; i++)
	{
		int j = 0;
		//while (arr[i] == num)//第一种方法
		//{
		//	for (j = 0; j < N - i; j++)
		//	{
		//		arr[i + j] = arr[i + j + 1];//将元素向前移动
		//	}
		//}
		//while (arr[i] == num)//第二种方法
		//{
		//	j++;
		//	if (num != arr[i + j])
		//		for (j = 0; j < N - i; j++)
		//		{
		//			arr[i + j] = arr[i + j + 1];//将元素向前移动
		//		}
		//}
		if (num != arr[i] && arr[i] != 0)//第三种方法
		{
			printf("%d ", arr[i]);
		}

	}
	//for (i = 0; i < N - 1; i++)//第一、二种方法
	//{
	//	if (arr[i] != 0)
	//		printf("%d ", arr[i]);
	//}
	return 0;
}