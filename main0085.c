#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int N = 0;
	int arr[50] = { 0 };
	int num = 0;
	int i = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &num);
	for (i = N - 1; i >= 0; i--)
	{
		if (arr[i] > num)
		{
			arr[i + 1] = arr[i];
			if (i == 0)
				arr[i] = num;
		}

		else
		{
			arr[i + 1] = num;
			i = -1;
		}

	}
	for (i = 0; i < N+1; i++)
		printf("%d ", arr[i]);


	return 0;
}