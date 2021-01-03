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
	for (i = 0; i < N; i++)
	{
		if (arr[N - i - 1] > num)//从数组的最后一个元素开始判断
		{
			arr[N - i] = arr[N - i - 1];//将较大的元素向后移动
			if ((N - 1) == i)
			{
				arr[0] = num;//如果num比所有的元素都小，则num应该放在数组的第一位
			}
		}
		else
		{
			arr[N - i] = num;
			break;
		}
	}
	for (i = 0; i <= N; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}