#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 50
int main()
{
	int arr[MAX] = { 0 };
	int n = 0;
	int i = 0, j = 0;
	int num = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &num);
	for (i = n; i >= 1; i--)
	{
		if (arr[i - 1] > num)
		{
			arr[i] = arr[i - 1];
			if (i == 1)
				arr[0] = num;
		}
		else
		{
			arr[i] = num;
			break;
		}
	}
	for (i = 0; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}